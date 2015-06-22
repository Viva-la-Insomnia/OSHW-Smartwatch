/**************************************************************************//**
 * @file MPU9250.c
 * @brief MPU9250 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 * @note Builds upon Kris Winer's https://github.com/kriswiner/MPU-9250/
 * 		 and basically is a port with some changes
 ******************************************************************************/

/* NOTE Implement different error codes
 * and system log. Replace i2cTransferDone
 * poll with more functional version
 * for the purpose of error detection	   */

/*INCLUDES*/
#include "MPU9250.h"
#include "em_system.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "math.h"

/*DEFINES*/
#define MPU9250_ADDR 	0xD0
#define AK8963_ADDR_MPU 0x0C //MPU9250 and EFM32 emlib specs have different formats for I2C address
#define AK8963_ADDR_EFM 0x18

// See also MPU-9250 Register Map and Descriptions, Revision 4.0, RM-MPU-9250A-00, Rev. 1.4, 9/9/2013 for registers not listed in
// above document; the MPU9250 and MPU9150 are virtually identical but the latter has a different register map
//
//MPU-9250 Registers
#define SELF_TEST_X_GYRO 0x00
#define SELF_TEST_Y_GYRO 0x01
#define SELF_TEST_Z_GYRO 0x02

//Register values left from MPU-9150. Are not defined in MPU-9250 Reference
/*#define X_FINE_GAIN      0x03 // [7:0] fine gain
#define Y_FINE_GAIN      0x04
#define Z_FINE_GAIN      0x05
#define XA_OFFSET_H      0x06 // User-defined trim values for accelerometer
#define XA_OFFSET_L_TC   0x07
#define YA_OFFSET_H      0x08
#define YA_OFFSET_L_TC   0x09
#define ZA_OFFSET_H      0x0A
#define ZA_OFFSET_L_TC   0x0B */

#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E
#define SELF_TEST_Z_ACCEL 0x0F

#define SELF_TEST_A      0x10

#define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define XG_OFFSET_L      0x14
#define YG_OFFSET_H      0x15
#define YG_OFFSET_L      0x16
#define ZG_OFFSET_H      0x17
#define ZG_OFFSET_L      0x18
#define SMPLRT_DIV       0x19
#define CONFIG           0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG     0x1C
#define ACCEL_CONFIG2    0x1D
#define LP_ACCEL_ODR     0x1E
#define WOM_THR          0x1F

#define MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define FIFO_EN          0x23
#define I2C_MST_CTRL     0x24
#define I2C_SLV0_ADDR    0x25
#define I2C_SLV0_REG     0x26
#define I2C_SLV0_CTRL    0x27
#define I2C_SLV1_ADDR    0x28
#define I2C_SLV1_REG     0x29
#define I2C_SLV1_CTRL    0x2A
#define I2C_SLV2_ADDR    0x2B
#define I2C_SLV2_REG     0x2C
#define I2C_SLV2_CTRL    0x2D
#define I2C_SLV3_ADDR    0x2E
#define I2C_SLV3_REG     0x2F
#define I2C_SLV3_CTRL    0x30
#define I2C_SLV4_ADDR    0x31
#define I2C_SLV4_REG     0x32
#define I2C_SLV4_DO      0x33
#define I2C_SLV4_CTRL    0x34
#define I2C_SLV4_DI      0x35
#define I2C_MST_STATUS   0x36
#define INT_PIN_CFG      0x37
#define INT_ENABLE       0x38
#define DMP_INT_STATUS   0x39  // Check DMP interrupt
#define INT_STATUS       0x3A
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define MOT_DETECT_STATUS 0x61
#define I2C_SLV0_DO      0x63
#define I2C_SLV1_DO      0x64
#define I2C_SLV2_DO      0x65
#define I2C_SLV3_DO      0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET  0x68
#define MOT_DETECT_CTRL  0x69
#define USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define PWR_MGMT_2       0x6C
#define DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define DMP_REG_1        0x70
#define DMP_REG_2        0x71
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define MPU9250_WHO_AM_I 0x75 // Should return 0x71
#define XA_OFFSET_H      0x77
#define XA_OFFSET_L      0x78
#define YA_OFFSET_H      0x7A
#define YA_OFFSET_L      0x7B
#define ZA_OFFSET_H      0x7D
#define ZA_OFFSET_L      0x7E

//Magnetometer Registers
#define AK8963_WHO_AM_I  0x00 // should return 0x48
#define AK8963_INFO      0x01
#define AK8963_ST1       0x02  // data ready status bit 0
#define AK8963_XOUT_L	 0x03  // data
#define AK8963_XOUT_H	 0x04
#define AK8963_YOUT_L	 0x05
#define AK8963_YOUT_H	 0x06
#define AK8963_ZOUT_L	 0x07
#define AK8963_ZOUT_H	 0x08
#define AK8963_ST2       0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL      0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC      0x0C  // Self test control
#define AK8963_I2CDIS    0x0F  // I2C disable
#define AK8963_ASAX      0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY      0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ      0x12  // Fuse ROM z-axis sensitivity adjustment value

// Sensor sensitivity scales
enum Ascale {
  AFS_2G = 0,
  AFS_4G,
  AFS_8G,
  AFS_16G
};

enum Gscale {
  GFS_250DPS = 0,
  GFS_500DPS,
  GFS_1000DPS,
  GFS_2000DPS
};

enum Mscale {
  MFS_14BITS = 0, // 0.6 mG per LSB
  MFS_16BITS      // 0.15 mG per LSB
};

// Specify sensor full scale
uint8_t Gscale = GFS_250DPS;
uint8_t Ascale = AFS_2G;
uint8_t Mscale = MFS_16BITS; // Choose either 14-bit or 16-bit magnetometer resolution
uint8_t Mmode = 0x02;        // 2 for 8 Hz, 6 for 100 Hz continuous magnetometer data read
float aRes, gRes, mRes;      // scale resolutions per LSB for the sensors

//FUNCTIONS

/*Returns the device ID -- 0x71*/
extern int MPU9250_WhoAmI(void){
	/*Define the transmission*/
		I2C_TransferSeq_TypeDef seq;
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = MPU9250_WHO_AM_I;
		seq.buf[0].len = 1;
		seq.buf[1].len = 1;

		/*Carry out the transmission*/
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		/*Format the output*/
		int ret = 0;
		ret = seq.buf[1].data[0];
		return ret;
}

// Functions to access sensor data / init / other useful stuff

extern void MPU9250_GetMres(void) {
	switch (Mscale){
	// Possible magnetometer scales (and their register bit settings) are:
	// 14 bit resolution (0) and 16 bit resolution (1)
	case MFS_14BITS:
		  mRes = 10.*4219./8190.; // Proper scale to return milliGauss
		  break;
	case MFS_16BITS:
		  mRes = 10.*4219./32760.0; // Proper scale to return milliGauss
		  break;
	}
}

extern void MPU9250_GetGres(void) {
	switch (Gscale){
		// Possible gyro scales (and their register bit settings) are:
		// 250 DPS (00), 500 DPS (01), 1000 DPS (10), and 2000 DPS  (11).
			// Here's a bit of an algorithm to calculate DPS/(ADC tick) based on that 2-bit value:
		case GFS_250DPS:
			  gRes = 250.0/32768.0;
			  break;
		case GFS_500DPS:
			  gRes = 500.0/32768.0;
			  break;
		case GFS_1000DPS:
			  gRes = 1000.0/32768.0;
			  break;
		case GFS_2000DPS:
			  gRes = 2000.0/32768.0;
			  break;
	}
}

extern void MPU9250_GetAres(void) {
	switch (Ascale){
	// Possible accelerometer scales (and their register bit settings) are:
	// 2 Gs (00), 4 Gs (01), 8 Gs (10), and 16 Gs  (11).
		// Here's a bit of an algorithm to calculate DPS/(ADC tick) based on that 2-bit value:
	case AFS_2G:
		  aRes = 2.0/32768.0;
		  break;
	case AFS_4G:
		  aRes = 4.0/32768.0;
		  break;
	case AFS_8G:
		  aRes = 8.0/32768.0;
		  break;
	case AFS_16G:
		  aRes = 16.0/32768.0;
		  break;
	}
}


extern void MPU9250_ReadAccelData(int16_t * destination){
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = ACCEL_XOUT_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 6;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	destination[0] = ((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1] ;  // Turn the MSB and LSB into a signed 16-bit value
	destination[1] = ((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3] ;
	destination[2] = ((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5] ;
}


extern void MPU9250_ReadGyroData(int16_t * destination){
	// Read the six raw data registers into data array
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = GYRO_XOUT_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 6;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Turn the MSB and LSB into a signed 16-bit value
	destination[0] = ((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1] ;  // Turn the MSB and LSB into a signed 16-bit value
	destination[1] = ((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3] ;
	destination[2] = ((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5] ;
}

extern void MPU9250_ReadMagData(int16_t * destination){
	// wait for magnetometer data ready bit to be set
	unsigned int flag = 0;

	do {
	I2C_TransferSeq_TypeDef seq;
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = AK8963_ST1;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	flag = seq.buf[1].data[0];

	} while(flag & 0x01);

	I2C_TransferSeq_TypeDef seq;
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = AK8963_XOUT_L;
	seq.buf[0].len = 1;
	seq.buf[1].len = 7;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	if(!(seq.buf[1].data[6] & 0x08)) { // Check if overflow flag is set, if not then report data
		destination[0] = ((int16_t)seq.buf[1].data[1] << 8) | seq.buf[1].data[0] ;  // Turn the MSB and LSB into a signed 16-bit value
		destination[1] = ((int16_t)seq.buf[1].data[3] << 8) | seq.buf[1].data[2] ;  // Data stored as little Endian
		destination[2] = ((int16_t)seq.buf[1].data[5] << 8) | seq.buf[1].data[4] ;
	}
}

extern int16_t MPU9250_ReadTempData(void){
	// Read the two raw data registers sequentially into data array
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = TEMP_OUT_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	return ((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1] ;  // Turn the MSB and LSB into a 16-bit value
}

extern void MPU9250_InitAK8963(float * destination){
	// First extract the factory calibration for each magnetometer axis

  	// Power down magnetometer
	I2C_TransferSeq_TypeDef seq;
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = AK8963_CNTL;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 10ms

	// Enter Fuse ROM access mode
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = AK8963_CNTL;
	seq.buf[0].data[1] = 0x0F;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 10ms

	// Read the x-, y-, and z-axis calibration values
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = AK8963_ASAX;
	seq.buf[0].len = 1;
	seq.buf[1].len = 3;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Return x-axis sensitivity adjustment values, etc.
	destination[0] =  (float)(seq.buf[1].data[0] - 128)/256. + 1.;
	destination[1] =  (float)(seq.buf[1].data[1] - 128)/256. + 1.;
	destination[2] =  (float)(seq.buf[1].data[2] - 128)/256. + 1.;

	// Power down magnetometer
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = AK8963_CNTL;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 10ms

	// Configure the magnetometer for continuous read and highest resolution
	// set Mscale bit 4 to 1 (0) to enable 16 (14) bit resolution in CNTL register,
	// and enable continuous mode data acquisition Mmode (bits [3:0]), 0010 for 8 Hz and 0110 for 100 Hz sample rates
	seq.addr = AK8963_ADDR_EFM;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = AK8963_CNTL;
	seq.buf[0].data[1] = Mscale << 4 | Mmode;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 10ms
}


extern int MPU9250_Init(void){
	/*Making sure that I2C connection is set up right*/
	/*Init the I2C bus*/
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;
	init.enable = 1;
	init.master = 1;
	init.freq = I2C_FREQ_FAST_MAX;
	init.clhr = i2cClockHLRAsymetric;

	I2C_Init(I2C1, &init);

	/*Initialising the MPU9250 with default settings*/

	// wake up device
	//Clear sleep mode bit (6), enable all sensors
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_1;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Wait for all registers to reset
	// delay 100ms

	// get stable time source
	// Auto select clock source to be PLL gyroscope reference if ready else
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_1;
	seq.buf[0].data[1] = 0x01;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 200ms

	// Configure Gyro and Thermometer
	// Disable FSYNC and set thermometer and gyro bandwidth to 41 and 42 Hz, respectively;
	// minimum delay time for this setting is 5.9 ms, which means sensor fusion update rates cannot
	// be higher than 1 / 0.0059 = 170 Hz
	// DLPF_CFG = bits 2:0 = 011; this limits the sample rate to 1000 Hz for both
	// With the MPU9250, it is possible to get gyro sample rates of 32 kHz (!), 8 kHz, or 1 kHz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = CONFIG;
	seq.buf[0].data[1] = 0x03;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set sample rate = gyroscope output rate/(1 + SMPLRT_DIV)
	// Use a 200 Hz rate; a rate consistent with the filter update rate
	// determined inset in CONFIG above
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = SMPLRT_DIV;
	seq.buf[0].data[1] = 0x04;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set gyroscope full scale range
	// Range selects FS_SEL and AFS_SEL are 0 - 3, so 2-bit values are left-shifted into positions 4:3
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	unsigned int temp = seq.buf[1].data[0];

	//  writeRegister(GYRO_CONFIG, temp & ~0xE0); // Clear self-test bits [7:5]

	// Clear Fchoice bits [1:0]
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] = temp & ~0x02;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Clear AFS bits [4:3]
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] = temp & ~0x18;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set full scale range for the gyro
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] = temp | Gscale << 3;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// writeRegister(GYRO_CONFIG, temp | 0x00); // Set Fchoice for the gyro to 11 by writing its inverse to bits 1:0 of GYRO_CONFIG

	// Set accelerometer full-scale range configuration
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	temp = seq.buf[1].data[0];

	//  writeRegister(ACCEL_CONFIG, c & ~0xE0); // Clear self-test bits [7:5]

	// Clear AFS bits [4:3]
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] = temp & ~0x18;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set full scale range for the accelerometer
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] = temp | Ascale << 3;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set accelerometer sample rate configuration
	// It is possible to get a 4 kHz sample rate from the accelerometer by choosing 1 for
	// accel_fchoice_b bit [3]; in this case the bandwidth is 1.13 kHz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = ACCEL_CONFIG2;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	temp = seq.buf[1].data[0];

	// Clear accel_fchoice_b (bit 3) and A_DLPFG (bits [2:0])
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG2;
	seq.buf[0].data[1] = temp & ~0x0F;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set accelerometer rate to 1 kHz and bandwidth to 41 Hz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG2;
	seq.buf[0].data[1] = temp | 0x03;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// The accelerometer, gyro, and thermometer are set to 1 kHz sample rates,
	// but all these rates are further reduced by a factor of 5 to 200 Hz because of the SMPLRT_DIV setting

	// Configure Interrupts and Bypass Enable
	// Set interrupt pin active high, push-pull, hold interrupt pin level HIGH until interrupt cleared,
	// clear on read of INT_STATUS, and enable I2C_BYPASS_EN so additional chips
	// can join the I2C bus and all can be controlled by EFM32 micro as master
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = INT_PIN_CFG;
	seq.buf[0].data[1] = 0x22;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Enable data ready (bit 0) interrupt
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = INT_ENABLE;
	seq.buf[0].data[1] = 0x01;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 100ms

	return 1;
}


// Function which accumulates gyro and accelerometer data after device initialization. It calculates the average
// of the at-rest readings and then loads the resulting offsets into accelerometer and gyro bias registers.
extern void MPU9250_Calibrate(float * dest1, float * dest2){
	uint8_t data[12]; // data array to hold accelerometer and gyro x, y, z, data
	uint16_t ii, packet_count, fifo_count;
	int32_t gyro_bias[3]  = {0, 0, 0}, accel_bias[3] = {0, 0, 0};

	// Write a one to bit 7 reset bit; toggle reset device
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_1;
	seq.buf[0].data[1] = 0x80;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 100ms

	// get stable time source; Auto select clock source to be PLL gyroscope reference if ready
	// else use the internal oscillator, bits 2:0 = 001
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_1;
	seq.buf[0].data[1] = 0x01;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_2;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 200ms

	// Configure device for bias calculation
	// Disable all interrupts
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = INT_ENABLE;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Disable FIFO
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = FIFO_EN;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Turn on internal clock source
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = PWR_MGMT_1;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Disable I2C master
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = I2C_MST_CTRL;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Disable FIFO and I2C master modes
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = USER_CTRL;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Reset FIFO and DMP
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = USER_CTRL;
	seq.buf[0].data[1] = 0x0C;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 15ms

	// Configure MPU9250 gyro and accelerometer for bias calculation
	// Set low-pass filter to 188 Hz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = CONFIG;
	seq.buf[0].data[1] = 0x01;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set sample rate to 1 kHz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = SMPLRT_DIV;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set gyro full-scale to 250 degrees per second, maximum sensitivity
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set accelerometer full-scale to 2 g, maximum sensitivity
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	uint16_t  gyrosensitivity  = 131;   // = 131 LSB/(degrees/sec)
	uint16_t  accelsensitivity = 16384;  // = 16384 LSB/g

	// Configure FIFO to capture accelerometer and gyro data for bias calculation
	// Enable FIFO
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = USER_CTRL;
	seq.buf[0].data[1] = 0x40;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Enable gyro and accelerometer sensors for FIFO  (max size 512 bytes in MPU-9250)
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = FIFO_EN;
	seq.buf[0].data[1] = 0x78;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	//delay 40ms
	// accumulate 40 samples in 40 milliseconds = 480 bytes

	// At end of sample accumulation, turn off FIFO sensor read
	// Disable gyro and accelerometer sensors for FIFO
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = FIFO_EN;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// read FIFO sample count
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = FIFO_COUNTH;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	fifo_count = ((uint16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1];
	packet_count = fifo_count/12; // How many sets of full gyro and accelerometer data for averaging

	for (ii = 0; ii < packet_count; ii++) {
		int16_t accel_temp[3] = {0, 0, 0}, gyro_temp[3] = {0, 0, 0};
		// read data for averaging
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = FIFO_R_W;
		seq.buf[0].len = 1;
		seq.buf[1].len = 12;
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		accel_temp[0] = (int16_t) (((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]  ) ;  // Form signed 16-bit integer for each sample in FIFO
		accel_temp[1] = (int16_t) (((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3]  ) ;
		accel_temp[2] = (int16_t) (((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5]  ) ;
		gyro_temp[0]  = (int16_t) (((int16_t)seq.buf[1].data[6] << 8) | seq.buf[1].data[7]  ) ;
		gyro_temp[1]  = (int16_t) (((int16_t)seq.buf[1].data[8] << 8) | seq.buf[1].data[9]  ) ;
		gyro_temp[2]  = (int16_t) (((int16_t)seq.buf[1].data[10] << 8) | seq.buf[1].data[11]) ;

		accel_bias[0] += (int32_t) accel_temp[0]; // Sum individual signed 16-bit biases to get accumulated signed 32-bit biases
		accel_bias[1] += (int32_t) accel_temp[1];
		accel_bias[2] += (int32_t) accel_temp[2];
		gyro_bias[0]  += (int32_t) gyro_temp[0];
		gyro_bias[1]  += (int32_t) gyro_temp[1];
		gyro_bias[2]  += (int32_t) gyro_temp[2];

	}
	accel_bias[0] /= (int32_t) packet_count; // Normalize sums to get average count biases
	accel_bias[1] /= (int32_t) packet_count;
	accel_bias[2] /= (int32_t) packet_count;
	gyro_bias[0]  /= (int32_t) packet_count;
	gyro_bias[1]  /= (int32_t) packet_count;
	gyro_bias[2]  /= (int32_t) packet_count;

	if(accel_bias[2] > 0L) {accel_bias[2] -= (int32_t) accelsensitivity;}  // Remove gravity from the z-axis accelerometer bias calculation
	else {accel_bias[2] += (int32_t) accelsensitivity;}

	// Construct the gyro biases for push to the hardware gyro bias registers, which are reset to zero upon device startup
	data[0] = (-gyro_bias[0]/4  >> 8) & 0xFF; // Divide by 4 to get 32.9 LSB per deg/s to conform to expected bias input format
	data[1] = (-gyro_bias[0]/4)       & 0xFF; // Biases are additive, so change sign on calculated average gyro biases
	data[2] = (-gyro_bias[1]/4  >> 8) & 0xFF;
	data[3] = (-gyro_bias[1]/4)       & 0xFF;
	data[4] = (-gyro_bias[2]/4  >> 8) & 0xFF;
	data[5] = (-gyro_bias[2]/4)       & 0xFF;

	// Push gyro biases to hardware registers
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = XG_OFFSET_H;
	seq.buf[0].data[1] = data[0];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = XG_OFFSET_L;
	seq.buf[0].data[1] = data[1];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = YG_OFFSET_H;
	seq.buf[0].data[1] = data[2];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = YG_OFFSET_L;
	seq.buf[0].data[1] = data[3];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ZG_OFFSET_H;
	seq.buf[0].data[1] = data[4];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ZG_OFFSET_L;
	seq.buf[0].data[1] = data[5];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Output scaled gyro biases for display in the main program
	dest1[0] = (float) gyro_bias[0]/(float) gyrosensitivity;
	dest1[1] = (float) gyro_bias[1]/(float) gyrosensitivity;
	dest1[2] = (float) gyro_bias[2]/(float) gyrosensitivity;

	// Construct the accelerometer biases for push to the hardware accelerometer bias registers. These registers contain
	// factory trim values which must be added to the calculated accelerometer biases; on boot up these registers will hold
	// non-zero values. In addition, bit 0 of the lower byte must be preserved since it is used for temperature
	// compensation calculations. Accelerometer bias registers expect bias input as 2048 LSB per g, so that
	// the accelerometer biases calculated above must be divided by 8.

	int32_t accel_bias_reg[3] = {0, 0, 0}; // A place to hold the factory accelerometer trim biases
	// Read factory accelerometer trim values
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = XA_OFFSET_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	accel_bias_reg[0] = (int32_t) (((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]);

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = YA_OFFSET_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	accel_bias_reg[1] = (int32_t) (((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]);

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = ZA_OFFSET_H;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	accel_bias_reg[2] = (int32_t) (((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]);

	uint32_t mask = 1uL; // Define mask for temperature compensation bit 0 of lower byte of accelerometer bias registers
	uint8_t mask_bit[3] = {0, 0, 0}; // Define array to hold mask bit for each accelerometer bias axis

	for(ii = 0; ii < 3; ii++) {
		if((accel_bias_reg[ii] & mask)) mask_bit[ii] = 0x01; // If temperature compensation bit is set, record that fact in mask_bit
	}

	// Construct total accelerometer bias, including calculated average accelerometer bias from above
	accel_bias_reg[0] -= (accel_bias[0]/8); // Subtract calculated averaged accelerometer bias scaled to 2048 LSB/g (16 g full scale)
	accel_bias_reg[1] -= (accel_bias[1]/8);
	accel_bias_reg[2] -= (accel_bias[2]/8);

	data[0] = (accel_bias_reg[0] >> 8) & 0xFF;
	data[1] = (accel_bias_reg[0])      & 0xFF;
	data[1] = data[1] | mask_bit[0]; // preserve temperature compensation bit when writing back to accelerometer bias registers
	data[2] = (accel_bias_reg[1] >> 8) & 0xFF;
	data[3] = (accel_bias_reg[1])      & 0xFF;
	data[3] = data[3] | mask_bit[1]; // preserve temperature compensation bit when writing back to accelerometer bias registers
	data[4] = (accel_bias_reg[2] >> 8) & 0xFF;
	data[5] = (accel_bias_reg[2])      & 0xFF;
	data[5] = data[5] | mask_bit[2]; // preserve temperature compensation bit when writing back to accelerometer bias registers

	// Apparently this is not working for the acceleration biases in the MPU-9250
	// Are we handling the temperature correction bit properly?
	// Push accelerometer biases to hardware registers
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = XA_OFFSET_H;
	seq.buf[0].data[1] = data[0];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = XA_OFFSET_L;
	seq.buf[0].data[1] = data[1];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = YA_OFFSET_H;
	seq.buf[0].data[1] = data[2];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = YA_OFFSET_L;
	seq.buf[0].data[1] = data[3];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ZA_OFFSET_H;
	seq.buf[0].data[1] = data[4];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ZA_OFFSET_L;
	seq.buf[0].data[1] = data[5];
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Output scaled accelerometer biases for display in the main program
	dest2[0] = (float)accel_bias[0]/(float)accelsensitivity;
	dest2[1] = (float)accel_bias[1]/(float)accelsensitivity;
	dest2[2] = (float)accel_bias[2]/(float)accelsensitivity;
}

// Accelerometer and gyroscope self test; check calibration wrt factory settings
extern void MPU9250_SelfTest(float * destination){ // Should return percent deviation from factory trim values, +/- 14 or less deviation is a pass
	uint8_t selfTest[6];
	int16_t gAvg[3], aAvg[3], aSTAvg[3], gSTAvg[3];
	float factoryTrim[6];
	uint8_t FS = 0;

	// Set gyro sample rate to 1 kHz
	I2C_TransferSeq_TypeDef seq;
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = SMPLRT_DIV;
	seq.buf[0].data[1] = 0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set gyro sample rate to 1 kHz and DLPF to 92 Hz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = CONFIG;
	seq.buf[0].data[1] = 0x02;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set full scale range for the gyro to 250 dps
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] = 1<<FS;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set accelerometer rate to 1 kHz and bandwidth to 92 Hz
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG2;
	seq.buf[0].data[1] =  0x02;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Set full scale range for the accelerometer to 2 g
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] =  1<<FS;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	for( int ii = 0; ii < 200; ii++) {  // get average current values of gyro and acclerometer

		// Read the six raw data registers into data array
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = ACCEL_XOUT_H;
		seq.buf[0].len = 1;
		seq.buf[1].len = 6;
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		aAvg[0] += (int16_t)(((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]) ;  // Turn the MSB and LSB into a signed 16-bit value
		aAvg[1] += (int16_t)(((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3]) ;
		aAvg[2] += (int16_t)(((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5]) ;

		// Read the six raw data registers sequentially into data array
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = GYRO_XOUT_H;
		seq.buf[0].len = 1;
		seq.buf[1].len = 6;
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		gAvg[0] += (int16_t)(((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]) ;  // Turn the MSB and LSB into a signed 16-bit value
		gAvg[1] += (int16_t)(((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3]) ;
		gAvg[2] += (int16_t)(((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5]) ;
	}

	for (int ii =0; ii < 3; ii++) {  // Get average of 200 values and store as average current readings
		aAvg[ii] /= 200;
		gAvg[ii] /= 200;
	}

	// Configure the accelerometer for self-test
	// Enable self test on all three axes and set accelerometer range to +/- 2 g
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] =  0xE0;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Enable self test on all three axes and set gyro range to +/- 250 degrees/s
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] =  0xE0;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Delay a while to let the device stabilize
	//delay 25ms

	for( int ii = 0; ii < 200; ii++) {  // get average self-test values of gyro and acclerometer

		// Read the six raw data registers into data array
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = ACCEL_XOUT_H;
		seq.buf[0].len = 1;
		seq.buf[1].len = 6;
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		aSTAvg[0] += (int16_t)(((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]) ;  // Turn the MSB and LSB into a signed 16-bit value
		aSTAvg[1] += (int16_t)(((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3]) ;
		aSTAvg[2] += (int16_t)(((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5]) ;

		// Read the six raw data registers sequentially into data array
		seq.addr = MPU9250_ADDR;
		seq.flags = I2C_FLAG_WRITE_READ;
		seq.buf[0].data[0] = GYRO_XOUT_H;
		seq.buf[0].len = 1;
		seq.buf[1].len = 6;
		I2C_TransferInit(I2C1, &seq);
		while(!(I2C_Transfer(I2C1) == i2cTransferDone));

		gSTAvg[0] += (int16_t)(((int16_t)seq.buf[1].data[0] << 8) | seq.buf[1].data[1]) ;  // Turn the MSB and LSB into a signed 16-bit value
		gSTAvg[1] += (int16_t)(((int16_t)seq.buf[1].data[2] << 8) | seq.buf[1].data[3]) ;
		gSTAvg[2] += (int16_t)(((int16_t)seq.buf[1].data[4] << 8) | seq.buf[1].data[5]) ;
	}

	for (int ii =0; ii < 3; ii++) {  // Get average of 200 values and store as average self-test readings
		aSTAvg[ii] /= 200;
		gSTAvg[ii] /= 200;
	}

	// Configure the gyro and accelerometer for normal operation
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = ACCEL_CONFIG;
	seq.buf[0].data[1] =  0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	seq.buf[0].data[0] = GYRO_CONFIG;
	seq.buf[0].data[1] =  0x00;
	seq.buf[0].len = 2;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));

	// Delay a while to let the device stabilize
	//delay 25ms


	// Retrieve accelerometer and gyro factory Self-Test Code from USR_Reg
	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_X_ACCEL;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[0] = seq.buf[0].data[1]; // X-axis accel self-test results

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_Y_ACCEL;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[1] = seq.buf[0].data[1]; // Y-axis accel self-test results

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_Z_ACCEL;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[2] = seq.buf[0].data[1]; // Z-axis accel self-test results

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_X_GYRO;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[3] = seq.buf[0].data[1]; // X-axis gyro self-test results

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_Y_GYRO;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[4] = seq.buf[0].data[1]; // Y-axis gyro self-test results

	seq.addr = MPU9250_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = SELF_TEST_Z_GYRO;
	seq.buf[0].len = 1;
	seq.buf[1].len = 1;
	I2C_TransferInit(I2C1, &seq);
	while(!(I2C_Transfer(I2C1) == i2cTransferDone));
	selfTest[5] = seq.buf[0].data[1]; // Z-axis gyro self-test results

	// Retrieve factory self-test value from self-test code reads
	factoryTrim[0] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[0] - 1.0) )); // FT[Xa] factory trim calculation
	factoryTrim[1] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[1] - 1.0) )); // FT[Ya] factory trim calculation
	factoryTrim[2] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[2] - 1.0) )); // FT[Za] factory trim calculation
	factoryTrim[3] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[3] - 1.0) )); // FT[Xg] factory trim calculation
	factoryTrim[4] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[4] - 1.0) )); // FT[Yg] factory trim calculation
	factoryTrim[5] = (float)(2620/1<<FS)*(pow( 1.01 , ((float)selfTest[5] - 1.0) )); // FT[Zg] factory trim calculation
	// Report results as a ratio of (STR - FT)/FT; the change from Factory Trim of the Self-Test Response
	// To get percent, must multiply by 100
	for (int i = 0; i < 3; i++) {
		destination[i]   = 100.0*((float)(aSTAvg[i] - aAvg[i]))/factoryTrim[i];   // Report percent differences
		destination[i+3] = 100.0*((float)(gSTAvg[i] - gAvg[i]))/factoryTrim[i+3]; // Report percent differences
	}

}
