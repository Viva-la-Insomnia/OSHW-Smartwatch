/**************************************************************************//**
 * @file
 * @brief Empty Project
 * @author Energy Micro AS
 * @version 3.20.2
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/
/**************************************************************************//**
 * @file main.c
 * @brief OSHW-Smartwatch main code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "em_device.h"
#include "em_chip.h"
#include "udelay.h"
#include "mdelay.h"
#include "BQ25010.h"
#include "BQ27421.h"
#include "MPU9250.h"
#include "LS013_MD.h"
#include "InitDevice.h"
#include "Graphics.h"
#include "rtc.h"
#include "EEPROM.h"
#include "em_usart.h"
#include "em_gpio.h"

int main(void)
{
	/* Initialise the chip - included for backwards compatibility.
	 * Do not add code before this point							*/
	CHIP_Init();

	/* Start in default mode */
	enter_DefaultMode_from_RESET();

	//Calibrate the delay function
	UDELAY_Calibrate();

	/* Initialise the subsystems
	 * after 150ms delay for them to boot */
	//UDELAY_Delay(150);

	LS013_Init();
	LS013_Enable();
	UDELAY_Delay(250);
	//LS013_SetBuffer(LoadingBackground);

	uint16_t cook[4];
	cook[0] = 0xa55a;
	cook[1] = 0x5aa5;
	cook[2] = 0xa55a;
	cook[3] = 0x5aa5;
	Sprite sprite;
	sprite.HEIGHT = 8;
	sprite.WIDTH = 8;
	sprite.SPRITE = cook;

	while(1){
		for (uint32_t i = 10; i<80; i++ ){
			LS013_DrawSprite( i, 10, sprite );
			LS013_Refresh(0);
			LS013_ClearBufferArea( i, 10, sprite.WIDTH, sprite.HEIGHT, 0 );
		}
		for (uint32_t i = 10; i<80; i++ ){
			LS013_DrawSprite( 80, i, sprite );
			LS013_Refresh(0);
			LS013_ClearBufferArea( 80, i, sprite.WIDTH, sprite.HEIGHT, 0 );
		}
		for (uint32_t i = 80; i>10; i-- ){
			LS013_DrawSprite( i, 80, sprite );
			LS013_Refresh(0);
			LS013_ClearBufferArea( i, 80, sprite.WIDTH, sprite.HEIGHT, 0 );
		}
		for (uint32_t i = 80; i>10; i-- ){
			LS013_DrawSprite( 10, i, sprite );
			LS013_Refresh(0);
			LS013_ClearBufferArea( 10, i, sprite.WIDTH, sprite.HEIGHT, 0 );
		}
	}
	//RTC_Mod_Init();
	//BQ25010_init();
	//BQ27421_Init();
	//MPU9250_Init();

	/* Uncomment when we solder in the MPU
	float AK8963_sensitivityadj[3];
	MPU9250_InitAK8963(AK8963_sensitivityadj);

	float gyro_bias[3];
	float	acc_bias[3];
	MPU9250_Calibrate(gyro_bias, acc_bias);

	float selftest_results[6];
	MPU9250_SelfTest(selftest_results);
	*/

  // Infinite loop
	while (1) {
		UDELAY_Delay(200);
		//LS013_InvertPolarity();
	}
}
