/**************************************************************************//**
 * @file LS013_MD.c
 * @brief LS013B4DN04 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 * Some functions ported and modified from SiLabs SLSTK3400A display drivers
 ******************************************************************************/
//INCLUDES
#include "stdint.h"
#include "math.h"
#include "em_system.h"
#include "em_rmu.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "udelay.h"
#include "string.h"

#include "LS013_MD.h"

//DEFINES
#define DISP_CS_PORT 		4
#define DISP_CS_PIN 		9
#define DISP_EN_PORT		4
#define DISP_EN_PIN			8
#define DISP_USART 			USART0

#define DISP_WIDTH			96
#define DISP_HEIGHT 		96

#define MODE_DYNAMIC 		0x01
#define MODE_STATIC 		0x00
#define MODE_CLEAR_DISP 	0x04
#define MODE_INV_POLARITY	0x02

//MISC
static uint16_t  framebuffer[DISP_WIDTH*DISP_HEIGHT/16];
static bool  	 linestorender[DISP_WIDTH];
static bool 	 polarity = 0;
static bool		 mode_static = 0; //0:Dynamic mode, 1:Static mode

//FUNCTIONS

void LS013_SetBuffer( const uint16_t* img ){
	memcpy( framebuffer, img, (DISP_WIDTH*DISP_HEIGHT/8) );
	for ( int i = 0; i<(DISP_WIDTH-1); i++ ){
		linestorender[i] = 1;
	}
}

void LS013_ClearBuffer(void){
	for ( int i=0; i < sizeof(framebuffer)/sizeof(uint16_t); i++){
		framebuffer[i] = 0x0000;
	}
}

void LS013_InvertBuffer(void){
	for ( int i = 0; i < sizeof(framebuffer)/sizeof(uint16_t); i++ ){
		framebuffer[i] = ~framebuffer[i];
	}
}

void LS013_DispSpiTransmit (uint16_t* data, unsigned int len){
	//Ported
	//Transmits data via SPI, duuh
	uint16_t* pointer = data;

	for(int i = 0; i<len; i++){
		USART_TxDouble( DISP_USART, *pointer );
		pointer++;
	}

	/* Wait for transfer to finish */
	while (!( DISP_USART->STATUS & USART_STATUS_TXC )) ;

}

void LS013_DrawLines( uint8_t start_row, uint8_t width, uint16_t* data ){
	//Draws the select rows from buffer on the screen
	//Set CS and wait the setup time
	GPIO_PinOutSet( DISP_CS_PORT, DISP_CS_PIN );
	UDELAY_Delay(6);
	uint16_t* pointer = data;
	pointer += start_row*6;

	//Display counts from 1 and EFM from 0
	start_row++;

	uint16_t cmd;
	//Send data
	for ( int i = 0; i<width; i++){
		cmd = MODE_DYNAMIC | ((start_row+i) << 8);
		LS013_DispSpiTransmit ( &cmd, 1 );
		LS013_DispSpiTransmit ( pointer, 6 );
		pointer += 6;
	}

	LS013_DispSpiTransmit( 0x0000, 1 ); //Dummy data

	//Wait the clear time and clear CS
	UDELAY_Delay(2);
	GPIO_PinOutClear( DISP_CS_PORT, DISP_CS_PIN );
}

void LS013_ClearDisp(void){
	//Sends the display full clear command
	GPIO_PinOutSet( DISP_CS_PORT, DISP_CS_PIN );
	UDELAY_Delay(6);

	uint16_t mode = 0;
	if (mode_static){
		mode = MODE_STATIC | MODE_CLEAR_DISP;
	}
	else {
		mode = MODE_DYNAMIC | MODE_CLEAR_DISP;
	}

	LS013_DispSpiTransmit ( &mode, 1 );

	//Wait the clear time and clear CS
	UDELAY_Delay(2);
	GPIO_PinOutClear( DISP_CS_PORT, DISP_CS_PIN );
}

void LS013_Init(void){

	LS013_ClearBuffer();

	LS013_ClearDisp();
}

void LS013_Refresh( bool whole_display ){

	uint16_t  displaybuffer[DISP_WIDTH*DISP_HEIGHT/16];
	uint16_t* bufferpointer = displaybuffer;

	for ( int i = 0; i < DISP_WIDTH*DISP_HEIGHT/16; i++ ){
			displaybuffer[i] = ~framebuffer[i];
		}

	if (whole_display == 1){
		LS013_DrawLines(0, (DISP_WIDTH-1), bufferpointer);
		for ( int i = 0; i<(DISP_WIDTH-1); i++ ){
			linestorender[i] = 0;
		}
	}

	else {
		uint16_t width = 0;
		uint16_t row = 0;
		while ( row < DISP_WIDTH ){
			if ( linestorender[row] == 1 ){
				while ( (linestorender[row+width] == 1) | ((row+width) < DISP_WIDTH) ){
					width++;
					linestorender[row+width] = 0;
				}
				LS013_DrawLines( row, width, bufferpointer );
				row += width;
				width = 0;
			}
		}
	}

}

void LS013_ClearBufferArea( uint8_t vert_position, uint8_t horiz_pos, uint8_t width, uint8_t height ){
	Sprite clear;
	clear.HEIGHT = height;
	clear.WIDTH = width;
	clear.SPRITE[(height*((width-width%16)/16+1))] = 0;
	//Fill the clear mask with 1s
	for ( int i = 0; i < (height*((width-width%16)/16+1)); i++){
			clear.SPRITE[i] = 0xFFFF;
		}
	//Clear the leading zeros
	if ( ~(clear.WIDTH%16 == 0) ){
		uint16_t bits = (2^(clear.WIDTH%16))-1;
		for ( int i = 0; i < width; i++ ){
			clear.SPRITE[(DISP_WIDTH/sizeof(uint16_t))*i] &= ~bits;
		}
	}

	if ( ((horiz_pos + clear.WIDTH) <= DISP_WIDTH) & ((vert_position + clear.HEIGHT) <= DISP_HEIGHT ) ){
		int horiz_position = horiz_pos - 16 + clear.WIDTH%16; //To deal with heading zeros of the clear sprite
		int offset = horiz_position%16;
		vert_position = (vert_position - offset)/16;
		//Now vert_position contains the number of uint16_t in vert line in which clear sprite starts
		//Offset contains the offset of sprite from the beginning of that uint16_t
		const int horizunitsinsprite = (clear.WIDTH - clear.WIDTH%16)/16+1;
		for ( int i = 0; i < clear.HEIGHT; i++ ){
			//horiz line
			int j = 0;
			while ( j < horizunitsinsprite ){
				//vertical bit
				int position = horiz_position +(DISP_WIDTH/sizeof(uint16_t))*(vert_position+i)+j;
				framebuffer[position] &= ~clear.SPRITE[j] >> offset;
				framebuffer[position+1] &= ~clear.SPRITE[j] << offset;
				j+=1;
			}
		}
		for ( int i = 0; i < height; i++ ){
			linestorender[vert_position+i] = 1;
		}
	}
}

void LS013_SpriteToBuffer( Sprite sprite, uint8_t position_vert, uint8_t position_horizont, bool merge_draw ){

	if ( ((position_horizont + sprite.WIDTH) <= DISP_WIDTH) & ((position_vert + sprite.HEIGHT) <= DISP_HEIGHT ) ){
		if ( merge_draw == 0 ){
			LS013_ClearBufferArea( position_vert, position_horizont, sprite.WIDTH, sprite.HEIGHT );
		}
		int position_horiz = position_horizont - 16 + sprite.WIDTH%16; //To deal with heading zeros of the sprite
		int offset = position_horiz%16;
		position_horiz = (position_horiz - offset)/16;
		//Now position_horiz contains the number of uint16_t in horizontal line in which sprite starts
		//Offset contains the offset of sprite from the beginning of that uint16_t
		const int horizunitsinsprite = (sprite.WIDTH - sprite.WIDTH%16)/16+1;
 		for ( int i = 0; i < sprite.HEIGHT; i++ ){
 			//horiz line
			int j = 0;
			while ( j < horizunitsinsprite ){
				//vertical bit
				int position = position_horiz +(DISP_HEIGHT/sizeof(uint16_t))*(position_vert+i)+j;
				framebuffer[position] |= sprite.SPRITE[j] >> offset;
				framebuffer[position+1] |= sprite.SPRITE[j] << offset;
				j+=1;
			}
 		}
 		for ( int i = 0; i < sprite.WIDTH; i++ ){
 			linestorender[position_horiz+i] = 1;
 		}
	}

}


void LS013_InvertPolarity(void){
	//Set CS and wait the setup time
		GPIO_PinOutSet( DISP_CS_PORT, DISP_CS_PIN );
		UDELAY_Delay(6);

		//Send data
		if (polarity == 0){
			uint16_t mode = 0;
			if (mode_static){
				mode = MODE_STATIC | MODE_INV_POLARITY;
			}
			else {
				mode = MODE_DYNAMIC | MODE_INV_POLARITY;
			}
			LS013_DispSpiTransmit ( &mode, 1 );

			polarity = 1;
		}
		else {
			uint16_t mode = 0;
			if (mode_static){
				mode = MODE_STATIC;
			}
			else {
				mode = MODE_DYNAMIC;
			}
			LS013_DispSpiTransmit ( &mode, 1 );
			polarity = 0;
		}

		//Wait the clear time and clear CS
		UDELAY_Delay(2);
		GPIO_PinOutClear( DISP_CS_PORT, DISP_CS_PIN );
}

void LS013_StaticMode(void){
	GPIO_PinOutSet( DISP_CS_PORT, DISP_CS_PIN );
	UDELAY_Delay(6);

	uint16_t mode = MODE_STATIC;
	LS013_DispSpiTransmit ( &mode, 1 );

	mode_static = 1;

	//Wait the clear time and clear CS
	UDELAY_Delay(2);
	GPIO_PinOutClear( DISP_CS_PORT, DISP_CS_PIN );
}

void LS013_Enable(void){
	GPIO_PinOutSet( DISP_EN_PORT, DISP_EN_PIN );
}

void LS013_Disable(void){
	GPIO_PinOutClear( DISP_EN_PORT, DISP_EN_PIN );
}
