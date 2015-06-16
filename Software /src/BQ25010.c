/**************************************************************************//**
 * @file BQ25010.c
 * @brief BQ25010 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "BQ25010.h"
#include "em_gpio.h"


void BQ25010_init(void){
	GPIO->P[0].DOUT &= ~0x0002; /* USB Charging set to 100mA  */
	GPIO->P[0].DOUT |= 0x0004; /* CE High - Disable charging */
}

int BQ25010_get_status(void){
	/* Returns bitwise negative of STAT2 STAT1
	 * Remember the pullups on input pins!
	 * 0: Precharge in progress
	 * 1: Fast charge in progress
	 * 2: Charge done
	 * 3: Timer fault/sleep mode 				*/

	uint32_t stat_pins = 0;
	stat_pins = GPIO->P[0].DIN;
	stat_pins &= 0x600;
	stat_pins = stat_pins >> 9;
	return stat_pins;
}

void BQ25010_charge_on(void){
	GPIO->P[0].DOUT &= ~0x0004;
}

void BQ25010_charge_off(void){
	GPIO->P[0].DOUT |= 0x0004;
}

void BQ25010_USB_charge_high(void){
	/* Set USB Charging current to 500 mAh
	 * WARNING! In current schematic battery
	 * gauge has max current capability of 200mA,
	 * and this function will overload the gauge */
	GPIO->P[0].DOUT |= 0x0002;
}

void BQ25010_USB_charge_low(void){
	/* Set USB Charging current to 100 mAh */
	GPIO->P[0].DOUT &= ~0x0002;
}
