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

int main(void)
{
  /* Initialise the chip - included for backwards compatibility.
   * Do not add code before this point							*/
  CHIP_Init();

  /* Start in default mode */
  enter_DefaultMode_from_RESET();

  //Calibrate the delay
  UDELAY_Calibrate();

  /* Initialise the subsystems
   * after 150ms delay for them to boot */
  MDELAY_Delay(150);
  BQ25010_init();
  BQ27421_Init();
  MPU9250_Init();
  LS013_Init();
  LS013_SetBuffer(LoadingBackground);
  LS013_Refresh(1);
  LS013_Enable();

  float AK8963_sensitivityadj[3];
  MPU9250_InitAK8963(AK8963_sensitivityadj);

  float gyro_bias[3];
  float	acc_bias[3];
  MPU9250_Calibrate(gyro_bias, acc_bias);

  float selftest_results[6];
  MPU9250_SelfTest(selftest_results);

  /* Infinite loop */
  while (1) {
	  MDELAY_Delay(200);
	  LS013_InvertPolarity();
  }
}
