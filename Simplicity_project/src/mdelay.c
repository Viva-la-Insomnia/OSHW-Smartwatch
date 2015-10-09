/**************************************************************************//**
 * @file mdelay.c
 * @brief Microsecond delay
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#include "em_system.h"
#include "em_device.h"
#include "em_chip.h"
#include "udelay.h"
#include "mdelay.h"

void MDELAY_Delay(uint8_t microseconds){
	//Millisecond delay function
	while (microseconds > 0){
		UDELAY_Delay(500);
		UDELAY_Delay(500);
		microseconds--;
	}
}
