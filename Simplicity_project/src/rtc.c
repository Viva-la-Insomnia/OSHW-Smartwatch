/**************************************************************************//**
 * @file rtc.c
 * @brief Real-time-clock library
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "stdint.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_rtc.h"

#define RTC_CRYSTAL_FREQ 32768

uint32_t hours = 12;
uint32_t minutes = 0;
uint32_t seconds = 0;

void RTC_Mod_Init(void){
	//Most of the setup is done in InitDevice
	RTC_Init_TypeDef init = RTC_INIT_DEFAULT;

	init.enable = 0;
	init.debugRun = 0;
	init.comp0Top = 1;

	RTC_Init(&init);

	//Set up the interrupt for every second
	RTC_CompareSet(0, ((RTC_CRYSTAL_FREQ / 32) - 1) );

	//Enable RTC counter interrupt
	NVIC_EnableIRQ(RTC_IRQn);
	RTC_IntEnable(RTC_IEN_COMP0);

	//Start RTC
	RTC_Enable(true);
}

uint32_t RTC_GetTime(void){
	uint32_t time = 0;
	time += hours*10000;
	time += minutes*100;
	time += seconds;
	return time;
}

//RTC interrupt handler
void RTC_IRQHandler(void){
	// Clear interrupt source
	RTC_IntClear(RTC_IFC_COMP0);

	// Increase time by one second
	seconds++;
	if (seconds > 59){
		seconds = 0;
		minutes++;
		if (minutes > 59){
			minutes = 0;
			hours++;
			if (hours > 23){
				hours = 0;
			}
		}
	}
}
