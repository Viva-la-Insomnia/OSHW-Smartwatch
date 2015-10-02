/**************************************************************************//**
 * @file MPU9250.c
 * @brief MPU9250 interface code header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "stdint.h"

extern int MPU9250_WhoAmI(void);
extern void MPU9250_GetMres(void);
extern void MPU9250_GetGres(void);
extern void MPU9250_GetAres(void);
extern void MPU9250_ReadAccelData(int16_t * destination);
extern void MPU9250_ReadGyroData(int16_t * destination);
extern void MPU9250_ReadMagData(int16_t * destination);
extern int16_t MPU9250_ReadTempData(void);
extern void MPU9250_InitAK8963(float * destination);
extern int MPU9250_Init(void);
extern void MPU9250_Calibrate(float * dest1, float * dest2);
extern void MPU9250_SelfTest(float * destination);
