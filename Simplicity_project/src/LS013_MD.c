/**************************************************************************//**
 * @file LS013_MD.c
 * @brief LS013B4DN04 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 * Some functions ported and modified from SiLabs SLSTK3400A display drivers
 * and render.c
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

void LS013_ClearBufferArea( uint32_t xstart, uint32_t ystart, uint32_t xwidth, uint32_t ywidth, int color ){
	uint32_t x, y;
	uint16_t* framePointer;
	int frameOffset;

	for (y = ystart; y < ystart+ywidth; y++)
	{
		for (x = xstart; x < xstart+xwidth; x++)
		{
			framePointer = &framebuffer[(x + y * DISP_WIDTH)/16];
			frameOffset  = x % 16;
			if (color)
			{
				*framePointer |= (1 << frameOffset);
			}
			else
			{
				*framePointer &= ~(1 << frameOffset);
			}

		}

		/* Mark line dirty */
		linestorender[y/16] |= (1 << (y % 16));
	}

		}

void LS013_DrawSprite( uint32_t posx, uint32_t posy, const Sprite sprite ){
	uint32_t x, y;
	uint32_t spriteOffset, frameOffset;
	uint16_t spriteUnit;
	uint16_t* framePointer;

	for (y = 0; y < sprite.HEIGHT; y++)
	{
		for (x = 0; x < sprite.WIDTH; x++)
		{
			/* Get correct alien byte*/
			spriteUnit = *(sprite.SPRITE + x/16 + y*sprite.WIDTH/16);
			spriteOffset = x % 16;

			/* Mark bits that are coloured */
			if (spriteUnit & (1 << spriteOffset))
			{
				framePointer = &framebuffer[((posx + x) + (posy + y)*DISP_WIDTH)/16];
				frameOffset  = (posx + x) % 16;
				*framePointer |= (1 << frameOffset);
			}
		}

		/* Mark line dirty */
		linestorender[(posy + y)/16] |= (1 << ((posy + y) % 16));
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
