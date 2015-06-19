/**************************************************************************//**
 * @file BQ27421.c
 * @brief BQ27421 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "BQ27421.h"
#include "em_system.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_i2c.h"

/*CONSTANTS*/
const int BQ27421_ADDR = 0xAA;

/*FUNCTIONS*/

/********************************************
 * Should return 0x0421. If this returns
 * smth else than 0x0421 you have a problem?
 *******************************************/
extern unsigned long BQ27421_Get_Device_Type(void){
	/*Define the transmission*/
	I2C_TransferSeq_TypeDef seq;
	seq.addr = BQ27421_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = 0x00;
	seq.buf[0].data[1] = 0x01;
	seq.buf[0].data[2] = 0x00;
	seq.buf[0].len = 3;
	seq.buf[1].len = 2;

	/*Carry out the transmission*/
	I2C_TransferInit(I2C0, &seq);
	while(!(I2C_Transfer(I2C0) == i2cTransferDone));

	/*Format the output*/
	uint32_t ret = seq.buf[1].data[1];
	ret <<= 8;
	ret += seq.buf[1].data[0];
	return ret;
}

extern unsigned long BQ27421_Get_Temp(void){
	/*Define the transmission*/
	I2C_TransferSeq_TypeDef seq;
	seq.addr = BQ27421_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = 0x02;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;

	/*Carry out the transmission*/
	I2C_TransferInit(I2C0, &seq);
	while(!(I2C_Transfer(I2C0) == i2cTransferDone));

	/*Format the output*/
	uint32_t ret = seq.buf[1].data[1];
		ret <<= 8;
		ret += seq.buf[1].data[0];
		return ret;
}

extern unsigned long BQ27421_Get_Pack_Voltage(void){
	/*Define the transmission*/
	I2C_TransferSeq_TypeDef seq;
	seq.addr = BQ27421_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	seq.buf[0].data[0] = 0x04;
	seq.buf[0].len = 1;
	seq.buf[1].len = 2;

	/*Carry out the transmission*/
	I2C_TransferInit(I2C0, &seq);
	while(!(I2C_Transfer(I2C0) == i2cTransferDone));

	/*Format the output*/
	uint32_t ret = seq.buf[1].data[1];
		ret <<= 8;
		ret += seq.buf[1].data[0];
		return ret;
}
/*All the other functions(except for unseal - see sluuac5a) are pretty much a
 * copypaste of the functions above with only seq.buf data changed*/
/*As an idea - add safety checks to ensure, for example,
 * that no devices are transmitting during beginning of function.
 * Needed because UC is clocked much faster than the I2C bus */

extern int BQ27421_Init(void) {
	/*Making sure that I2C connection is set up right*/
	/*Init the I2C bus*/
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;
	init.enable = 1;
	init.master = 1;
	init.freq = I2C_FREQ_FAST_MAX;
	init.clhr = i2cClockHLRAsymetric;

	I2C_Init(I2C0, &init);

	if ( !(BQ27421_Get_Device_Type() == 0x0421) ){
		return 0; /*THE PROBLEM*/
	}
	/*Wait for 66us before issuing the next command to the gauge*/

	return 1;

}
