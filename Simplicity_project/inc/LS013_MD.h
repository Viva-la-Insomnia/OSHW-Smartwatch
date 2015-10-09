/**************************************************************************//**
 * @file LS013_MD.c
 * @brief LS013B4DN04 interface code header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#ifndef __EM_SYSTEM_H
#define __EM_SYSTEM_H
#endif

#ifndef __EM_DEVICE_H
#define __EM_DEVICE_H
#endif

#ifndef __EM_CHIP_H
#define __EM_CHIP_H
#endif

#ifndef __EM_GPIO_H
#define __EM_GPIO_H
#endif

#ifndef __EM_USART_H
#define __EM_USART_H
#endif

#ifndef __UDELAY_H
#define __UDELAY_H
#endif

#ifndef __MATH_H
#define __MATH_H
#endif

#ifndef __STDINT_H
#define __STDINT_H
#endif

#ifndef __STRING_H
#define __STRING_H
#endif

typedef struct SpriteType {

	uint8_t WIDTH, HEIGHT;
	uint16_t* SPRITE[];

	/* Sprite file to draw on the display
	 * Actual sprite consists of an array of pixels in uint16_t
	 * Sprite that is not 16n pixels high has heading zeros added in the beginning of every line
	 * */

} Sprite;

typedef struct SpriteType Sprite;

void LS013_InvertBuffer(void);
void LS013_DispSpiTransmit (uint8_t* data, unsigned int len);
void LS013_DrawLines( uint8_t start_column, uint8_t width, uint16_t* data );
void LS013_Init(void);
void LS013_DrawDots(void);
void LS013_RenderBuffer( bool renderwhole );
void LS013_ClearBufferArea( uint8_t vert_position, uint8_t horiz_position, uint8_t width, uint8_t height );
void LS013_SpriteToBuffer( Sprite sprite, uint8_t position_vert, uint8_t position_horiz, bool merge_draw );
void LS013_ClearBufferArea( uint8_t vert_position, uint8_t horiz_position, uint8_t width, uint8_t height );
void LS013_SpriteToBuffer( Sprite sprite, uint8_t position_vert, uint8_t position_horiz, bool merge_draw );
void LS013_SetBuffer( const uint16_t* img );
void LS013_ClearBuffer(void);
