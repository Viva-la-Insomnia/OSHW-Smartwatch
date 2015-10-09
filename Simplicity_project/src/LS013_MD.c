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
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "udelay.h"
#include "string.h"

#include "LS013_MD.h"

//DEFINES
#define DISP_CS_PORT 		0 //SET THE RIGHT PIN AND PORT
#define DISP_CS_PIN 		0

#define DISP_WIDTH			96
#define DISP_HEIGHT 		96

#define MODE_DYNAMIC 		0xA0
#define MODE_STATIC 		0x00
#define MODE_CLEAR_DISP 	0b00100000

#define DISP_USART 			USART0

//MISC
static uint16_t* framebuffer[DISP_WIDTH*DISP_HEIGHT/16];
static bool  	 linestorender[DISP_WIDTH];

//FUNCTIONS

void LS013_InvertBuffer(void){
	for ( int i = 0; i < sizeof(*framebuffer)/sizeof(uint16_t); i++ ){
		*framebuffer[i] = ~*framebuffer[i];
	}
}

void LS013_DispSpiTransmit (uint8_t* data, unsigned int len){
	//Ported
	//Transmits data via SPI, duuh
	while (len>0)
	{
		/* Send only one byte if len==1 or data pointer is not aligned at a 16 bit
       word location in memory. */
		if ((len == 1) || ((unsigned int)data & 0x1))
		{
			USART_Tx( DISP_USART, *(uint8_t*)data );
			len  --;
			data ++;
		}
		else
		{
			USART_TxDouble( DISP_USART, *(uint16_t*)data );
			len  -= 2;
			data += 2;
		}
	}

	/* Wait for transfer to finish */
	while (!( DISP_USART->STATUS & USART_STATUS_TXC )) ;

}

void LS013_DrawLines( uint8_t start_column, uint8_t width, uint16_t* data ){
	//Draws the select columns from buffer on the screen
	//Set CS and wait the setup time
	GPIO_PinOutSet( DISP_CS_PORT, DISP_CS_PIN );
	UDELAY_Delay(6);

	//Display counts from 1 and EFM from 0
	start_column++;
	*data += start_column;

	//Send data
	while( width > 0 ){
		LS013_DispSpiTransmit ( (uint8_t*) MODE_DYNAMIC, 1 ); //Dummy data
		LS013_DispSpiTransmit ( (uint8_t*) (start_column << 1), 1);
		LS013_DispSpiTransmit ( (uint8_t*) data, DISP_HEIGHT/sizeof(uint16_t) );
		width--;
		start_column++;
		*data += 2;
	}

	LS013_DispSpiTransmit( 0x0000, 2 ); //Dummy data

	//Wait the clear time and clear CS
	UDELAY_Delay(2);
	GPIO_PinOutClear( DISP_CS_PORT, DISP_CS_PIN );


}

void LS013_Init(void){
	//Initialises the display
	//Init the USART Interface
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;
	initsync.baudrate = 115200;
	initsync.databits = usartDatabits8;
	initsync.master = 1;
	initsync.msbf = 1;
	initsync.clockMode = usartClockMode0;
#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable = 0;
	initsync.prsRxCh = 0;
	initsync.autoTx = 0;
#endif

	USART_InitSync( DISP_USART, &initsync );

	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable        = 0;
	initprs.txTriggerEnable        = 0;
	initprs.prsTriggerChannel      = usartPrsTriggerCh0;

	USART_InitPrsTrigger( DISP_USART, &initprs );

}

void LS013_DrawDots(void){
	//Fill display with alternating colors aka dots because we only have two
	#define DOTS		0xAAAA
	#define ANTIDOTS	0x5555
	for ( int i = 0; i <DISP_WIDTH*DISP_HEIGHT/16; i+=2 ){
		*framebuffer[i] = (uint16_t) DOTS;
		*framebuffer[i+1] = (uint16_t) ANTIDOTS;
	}
	LS013_DrawLines(0, 95, *framebuffer);

}

void LS013_RenderBuffer( bool renderwhole ){

	LS013_InvertBuffer();

	if (renderwhole == 1){
		LS013_DrawLines(0, 95, *framebuffer);
	}

	else {
		uint8_t width = 0;
		uint8_t column = 0;
		while ( column < DISP_WIDTH ){
			if ( linestorender[column] == 1 ){
				while ( (linestorender[column+width] == 1) | ((column+width) < DISP_WIDTH) ){
					width++;
				}
				LS013_DrawLines( column, width, *framebuffer );
				column += width;
			}
		}
	}

	LS013_InvertBuffer();

}

void LS013_ClearBufferArea( uint8_t vert_position, uint8_t horiz_position, uint8_t width, uint8_t height ){
	Sprite clear;
	clear.HEIGHT = height;
	clear.WIDTH = width;
	clear.SPRITE[(width*((height-height%16)/16+1))] = 0;
	//Fill the clear mask with 1s
	for ( int i = 0; i < sizeof(*clear.SPRITE)/sizeof(uint16_t); i++){
			*clear.SPRITE[i] = 0xFFFF;
		}
	//Clear the leading zeros
	if ( ~(clear.HEIGHT%16 == 0) ){
		uint16_t bits = (2^(clear.HEIGHT%16))-1;
		for ( int i = 0; i < width; i++ ){
			*clear.SPRITE[(DISP_HEIGHT/sizeof(uint16_t))*i] &= ~bits;
		}
	}

	if ( ((horiz_position + clear.WIDTH) <= DISP_WIDTH) & ((vert_position + clear.HEIGHT) <= DISP_HEIGHT ) ){
		vert_position -= 16 - clear.HEIGHT%16; //To deal with heading zeros of the clear sprite
		int offset = vert_position%16;
		vert_position = (vert_position - offset)/16;
		//Now vert_position contains the number of uint16_t in vert line in which clear sprite starts
		//Offset contains the offset of sprite from the beginning of that uint16_t
		const int vertunitsinsprite = (clear.HEIGHT - clear.HEIGHT%16)/16+1;
		for ( int i = 0; i < clear.WIDTH; i++ ){
			//horiz line
			int j = 0;
			while ( j < vertunitsinsprite ){
				//vertical bit
				int position = vert_position +(DISP_HEIGHT/sizeof(uint16_t))*(horiz_position+i)+j;
				*framebuffer[position] &= ~*clear.SPRITE[j] >> offset;
				*framebuffer[position+1] &= ~*clear.SPRITE[j] << offset;
				j+=1;
			}
		}
		for ( int i = 0; i < width; i++ ){
			linestorender[horiz_position+i] = 1;
		}
	}
}

void LS013_SpriteToBuffer( Sprite sprite, uint8_t position_vert, uint8_t position_horiz, bool merge_draw ){

	if ( ((position_horiz + sprite.WIDTH) <= DISP_WIDTH) & ((position_vert + sprite.HEIGHT) <= DISP_HEIGHT ) ){
		if ( merge_draw == 0 ){
			LS013_ClearBufferArea( position_vert, position_horiz, sprite.WIDTH, sprite.HEIGHT );
		}
		position_vert -= 16 - sprite.HEIGHT%16; //To deal with heading zeros of the sprite
		int offset = position_vert%16;
		position_vert = (position_vert - offset)/16;
		//Now position_vert contains the number of uint16_t in vert line in which sprite starts
		//Offset contains the offset of sprite from the beginning of that uint16_t
		const int vertunitsinsprite = (sprite.HEIGHT - sprite.HEIGHT%16)/16+1;
 		for ( int i = 0; i < sprite.WIDTH; i++ ){
 			//horiz line
			int j = 0;
			while ( j < vertunitsinsprite ){
				//vertical bit
				int position = position_vert +(DISP_HEIGHT/sizeof(uint16_t))*(position_horiz+i)+j;
				*framebuffer[position] |= *sprite.SPRITE[j] >> offset;
				*framebuffer[position+1] |= *sprite.SPRITE[j] << offset;
				j+=1;
			}
 		}
 		for ( int i = 0; i < sprite.WIDTH; i++ ){
 			linestorender[position_horiz+i] = 1;
 		}
	}

}

void LS013_SetBuffer( const uint16_t* img ){
	memcpy( framebuffer, img, (DISP_WIDTH*DISP_HEIGHT/8) );
}

void LS013_ClearBuffer(void){
	for ( int i=0; i < sizeof(*framebuffer)/sizeof(uint16_t); i++){
		*framebuffer[i] = 0x0000;
	}
}
