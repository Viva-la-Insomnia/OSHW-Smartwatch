/**************************************************************************//**
 * @file udelay.c
 * @brief Microsecond delay routine.
 * @version 4.0.0
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/
//THIS HAS BEEN MODIFIED TO EXCLUDE INTERRUPT DISABLE WHEN CALIBRATING
//BECAUSE COMPILATION PROBLEMS

#include "em_device.h"
#include "em_cmu.h"
#include "em_int.h"
#include "em_timer.h"

#include "udelay.h"


void UDELAY_Calibrate(void){
	while(0);
}

void UDELAY_Delay( uint32_t usecs ){

	/* adjustment factor for 40MHz oscillator, based on the timing of this whole function with speed optimization on, could probably be done in a prettier way. */

	uint32_t cycle_delay = usecs * 40 - 28;

	/* Reset Timer */

	TIMER_CounterSet(TIMER0, 0);

	/* Start TIMER0 */

	TIMER0->CMD = TIMER_CMD_START;

	/* Wait until counter value is over top */

	while(TIMER0->CNT < cycle_delay){

		/* Do nothing, just wait */

	}

	TIMER0->CMD = TIMER_CMD_STOP;

}

