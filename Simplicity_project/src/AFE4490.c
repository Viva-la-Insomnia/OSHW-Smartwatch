/**************************************************************************//**
 * @file AFE4490.c
 * @brief AFE4490 interface code
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/
//INCLUDES
#include "AFE4490.h"
#include "em_system.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_usart.h"

//DEFINES

//FUNCTIONS
extern void AFE4490_Init(void){
	//Init the USART Interface
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;
	initsync.baudrate = 115200;
	initsync.databits = usartDatabits8;
	initsync.master = 1;
	initsync.msbf = 1;
	initsync.clockMode = usartClockMode0;
#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable = 0;
	initsync.prsRxCh = 0;
	initsync.autoTx = 0;
#endif

	USART_InitSync(USART1, &initsync);

	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable        = 0;
	initprs.txTriggerEnable        = 0;
	initprs.prsTriggerChannel      = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART1, &initprs);
}
