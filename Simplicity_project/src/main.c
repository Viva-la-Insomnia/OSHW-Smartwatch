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
#include "BQ25010.h"
#include "BQ27421.h"
#include "MPU9250.h"
#include "InitDevice.h"

int main(void)
{
  /* Initialise the chip - included for backwards compatibility.
   * Do not add code before this point							*/
  CHIP_Init();


  /* Start in default mode */
  enter_DefaultMode_from_RESET();

  /* Initialise the subsystems
   * after 100ms delay for them to boot */

  //delay 100ms
  BQ25010_init();
  BQ27421_Init();
  MPU9250_Init();

  float AK8963_sensitivityadj[3];
  MPU9250_InitAK8963(AK8963_sensitivityadj);

  float gyro_bias[3];
  float	acc_bias[3];
  MPU9250_Calibrate(gyro_bias, acc_bias);

  float selftest_results[6];
  MPU9250_SelfTest(selftest_results);

  /* Infinite loop */
  while (1) {
  }
}
