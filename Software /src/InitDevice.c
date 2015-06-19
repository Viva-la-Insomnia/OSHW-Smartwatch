//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS


// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_burtc.h"
#include "em_rmu.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_rtc.h"
#include "em_usart.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	CMU_enter_DefaultMode_from_RESET();
	BURTC_enter_DefaultMode_from_RESET();
	HFXO_enter_DefaultMode_from_RESET();
	LFXO_enter_DefaultMode_from_RESET();
	RTC_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
	USART1_enter_DefaultMode_from_RESET();
	I2C0_enter_DefaultMode_from_RESET();
	I2C1_enter_DefaultMode_from_RESET();
	PORTIO_enter_DefaultMode_from_RESET();
	// [Config Calls]$


}


//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {
	// $[High Frequency Clock select]
	/* Using HFRCO at 14MHz as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	// [High Frequency Clock select]$

	// $[LFACLK Setup]
	/* Enable LFRCO oscillator */
	CMU_OscillatorEnable(cmuOsc_LFRCO, true, true);

	/* Select LFRCO as clock source for LFACLK */
	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFRCO);

	// [LFACLK Setup]$

	// $[Peripheral Clock enables]
	/* Enable clock for I2C0 */
	CMU_ClockEnable(cmuClock_I2C0, true);

	/* Enable clock for I2C1 */
	CMU_ClockEnable(cmuClock_I2C1, true);

	/* Enable clock for RTC */
	CMU_ClockEnable(cmuClock_RTC, true);

	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Enable clock for USART1 */
	CMU_ClockEnable(cmuClock_USART1, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$


}

//================================================================================
// ADC0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC0_enter_DefaultMode_from_RESET(void) {
	// $[ADC_Init]
	// [ADC_Init]$

	// $[ADC_InitSingle]
	// [ADC_InitSingle]$

	// $[ADC_InitScan]
	// [ADC_InitScan]$


}

//================================================================================
// ACMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP0_enter_DefaultMode_from_RESET(void) {
	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$


}

//================================================================================
// ACMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP1_enter_DefaultMode_from_RESET(void) {
	// $[ACMP Initialization]
	// [ACMP Initialization]$

	// $[ACMP Channel config]
	// [ACMP Channel config]$


}

//================================================================================
// DAC0_enter_DefaultMode_from_RESET
//================================================================================
extern void DAC0_enter_DefaultMode_from_RESET(void) {
	// $[DAC Initialization]
	// [DAC Initialization]$

	// $[DAC Channel 0 config]
	// [DAC Channel 0 config]$

	// $[DAC Channel 1 config]
	// [DAC Channel 1 config]$


}

//================================================================================
// BURTC_enter_DefaultMode_from_RESET
//================================================================================
extern void BURTC_enter_DefaultMode_from_RESET(void) {
	// $[CMU_ClockEnable]
	/* Enable LE clock for CPU access to BURTC registers */
	CMU_ClockEnable(cmuClock_CORELE, true);
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	// [CMU_OscillatorEnable]$

	// $[RMU_ResetControl]
	/* Release reset line to backup domain. This is needed before the CPU can access
	 * BURTC registers */
	RMU_ResetControl(rmuResetBU, false);
	// [RMU_ResetControl]$

	// $[BURTC_Init]
	BURTC_Init_TypeDef init = BURTC_INIT_DEFAULT;

	init.enable                    = false;
	init.mode                      = burtcModeEM2;
	init.debugRun                  = false;
	init.clkSel                    = burtcClkSelLFRCO;
	init.clkDiv                    = burtcClkDiv_1;
	init.timeStamp                 = false;
	init.compare0Top               = true;
	init.lowPowerMode              = burtcLPDisable;
	init.lowPowerComp              = 0;
	BURTC_Init(&init);
	// [BURTC_Init]$

	// $[BURTC_CompareSet]
	/* Set compare value */
	BURTC_CompareSet(0, 0);
	// [BURTC_CompareSet]$


}

//================================================================================
// HFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void HFXO_enter_DefaultMode_from_RESET(void) {
	// $[HFXO]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_HFXOMODE_MASK) | CMU_CTRL_HFXOMODE_XTAL;

	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_HFXOBOOST_MASK) | CMU_CTRL_HFXOBOOST_50PCENT;

	// [HFXO]$


}

//================================================================================
// LFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void LFXO_enter_DefaultMode_from_RESET(void) {
	// $[Use oscillator source]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOMODE_MASK) | CMU_CTRL_LFXOMODE_XTAL;
	// [Use oscillator source]$

	// $[LFXO Boost Percent]
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_LFXOBOOST_MASK) | CMU_CTRL_LFXOBOOST_70PCENT;
	// [LFXO Boost Percent]$

	// $[REDLFXO Boost]
	// [REDLFXO Boost]$


}

//================================================================================
// RTC_enter_DefaultMode_from_RESET
//================================================================================
extern void RTC_enter_DefaultMode_from_RESET(void) {
	// $[RTC_Init]
	RTC_Init_TypeDef init = RTC_INIT_DEFAULT;

	init.debugRun                  = 1;
	init.comp0Top                  = 1;

	RTC_Init(&init);
	// [RTC_Init]$


}

//================================================================================
// OPAMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP0_enter_DefaultMode_from_RESET(void) {
	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$


}

//================================================================================
// OPAMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP1_enter_DefaultMode_from_RESET(void) {
	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$


}

//================================================================================
// OPAMP2_enter_DefaultMode_from_RESET
//================================================================================
extern void OPAMP2_enter_DefaultMode_from_RESET(void) {
	// $[DAC Output]
	// [DAC Output]$

	// $[OPAMP_Enable]
	// [OPAMP_Enable]$


}

//================================================================================
// USART0_enter_DefaultMode_from_RESET
//================================================================================
extern void USART0_enter_DefaultMode_from_RESET(void) {
	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;

	initsync.baudrate              = 115200;
	initsync.databits              = usartDatabits8;
	initsync.master                = 1;
	initsync.msbf                  = 1;
	initsync.clockMode             = usartClockMode0;
	#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable           = 0;
	initsync.prsRxCh               = 0;
	initsync.autoTx                = 0;
	#endif

	USART_InitSync(USART0, &initsync);
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable        = 0;
	initprs.txTriggerEnable        = 0;
	initprs.prsTriggerChannel      = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART0, &initprs);
	// [USART_InitPrsTrigger]$


}

//================================================================================
// USART1_enter_DefaultMode_from_RESET
//================================================================================
extern void USART1_enter_DefaultMode_from_RESET(void) {
	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;

	initsync.baudrate              = 115200;
	initsync.databits              = usartDatabits8;
	initsync.master                = 1;
	initsync.msbf                  = 1;
	initsync.clockMode             = usartClockMode0;
	#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable           = 0;
	initsync.prsRxCh               = 0;
	initsync.autoTx                = 0;
	#endif

	USART_InitSync(USART1, &initsync);
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable        = 0;
	initprs.txTriggerEnable        = 0;
	initprs.prsTriggerChannel      = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART1, &initprs);
	// [USART_InitPrsTrigger]$


}

//================================================================================
// USART2_enter_DefaultMode_from_RESET
//================================================================================
extern void USART2_enter_DefaultMode_from_RESET(void) {
	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	// [USART_InitPrsTrigger]$


}

//================================================================================
// LEUART0_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART0_enter_DefaultMode_from_RESET(void) {
	// $[LEUART0 initialization]
	// [LEUART0 initialization]$


}

//================================================================================
// LEUART1_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART1_enter_DefaultMode_from_RESET(void) {
	// $[LEUART1 initialization]
	// [LEUART1 initialization]$


}

//================================================================================
// VCMP_enter_DefaultMode_from_RESET
//================================================================================
extern void VCMP_enter_DefaultMode_from_RESET(void) {
	// $[VCMP_Init]
	// [VCMP_Init]$


}

//================================================================================
// WDOG_enter_DefaultMode_from_RESET
//================================================================================
extern void WDOG_enter_DefaultMode_from_RESET(void) {
	// $[CMU_ClockEnable]
	// [CMU_ClockEnable]$

	// $[CMU_OscillatorEnable]
	// [CMU_OscillatorEnable]$

	// $[WDOG_Init]
	// [WDOG_Init]$


}

//================================================================================
// I2C0_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C0_enter_DefaultMode_from_RESET(void) {
	// $[I2C0 initialization]
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;

	init.enable                    = 1;
	init.master                    = 1;
	init.freq                      = I2C_FREQ_FAST_MAX;
	init.clhr                      = i2cClockHLRAsymetric;
	I2C_Init(I2C0, &init);
	// [I2C0 initialization]$


}

//================================================================================
// I2C1_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C1_enter_DefaultMode_from_RESET(void) {
	// $[I2C1 initialization]
	I2C_Init_TypeDef init = I2C_INIT_DEFAULT;

	init.enable                    = 1;
	init.master                    = 1;
	init.freq                      = I2C_FREQ_STANDARD_MAX;
	init.clhr                      = i2cClockHLRStandard;
	I2C_Init(I2C1, &init);
	// [I2C1 initialization]$


}

//================================================================================
// TIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER0_enter_DefaultMode_from_RESET(void) {
	// $[TIMER0 initialization]
	// [TIMER0 initialization]$

	// $[TIMER0 CC0 init]
	// [TIMER0 CC0 init]$

	// $[TIMER0 CC1 init]
	// [TIMER0 CC1 init]$

	// $[TIMER0 CC2 init]
	// [TIMER0 CC2 init]$

	// $[TIMER0 DTI init]
	// [TIMER0 DTI init]$


}

//================================================================================
// TIMER1_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER1_enter_DefaultMode_from_RESET(void) {
	// $[TIMER1 initialization]
	// [TIMER1 initialization]$

	// $[TIMER1 CC0 init]
	// [TIMER1 CC0 init]$

	// $[TIMER1 CC1 init]
	// [TIMER1 CC1 init]$

	// $[TIMER1 CC2 init]
	// [TIMER1 CC2 init]$


}

//================================================================================
// TIMER2_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER2_enter_DefaultMode_from_RESET(void) {
	// $[TIMER2 initialization]
	// [TIMER2 initialization]$

	// $[TIMER2 CC0 init]
	// [TIMER2 CC0 init]$

	// $[TIMER2 CC1 init]
	// [TIMER2 CC1 init]$

	// $[TIMER2 CC2 init]
	// [TIMER2 CC2 init]$


}

//================================================================================
// TIMER3_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER3_enter_DefaultMode_from_RESET(void) {
	// $[TIMER3 initialization]
	// [TIMER3 initialization]$

	// $[TIMER3 CC0 init]
	// [TIMER3 CC0 init]$

	// $[TIMER3 CC1 init]
	// [TIMER3 CC1 init]$

	// $[TIMER3 CC2 init]
	// [TIMER3 CC2 init]$


}

//================================================================================
// PCNT0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT0_enter_DefaultMode_from_RESET(void) {
	// $[PCNT0 initialization]
	// [PCNT0 initialization]$


}

//================================================================================
// PCNT1_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT1_enter_DefaultMode_from_RESET(void) {
	// $[PCNT1 initialization]
	// [PCNT1 initialization]$


}

//================================================================================
// PCNT2_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT2_enter_DefaultMode_from_RESET(void) {
	// $[PCNT2 initialization]
	// [PCNT2 initialization]$


}

//================================================================================
// PRS_enter_DefaultMode_from_RESET
//================================================================================
extern void PRS_enter_DefaultMode_from_RESET(void) {
	// $[PRS initialization]
	// [PRS initialization]$


}

//================================================================================
// ETM_enter_DefaultMode_from_RESET
//================================================================================
extern void ETM_enter_DefaultMode_from_RESET(void) {
	// $[ETM initialization]
	// [ETM initialization]$


}



extern void PORTIO_enter_DefaultMode_from_RESET(void) {

	// $[Port A Configuration]

	/* Port A drive strength set to Low (1 mA) */
	GPIO->P[0].CTRL = (GPIO->P[0].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;

	/* Pin PA0 is configured to Input enabled */
	GPIO->P[0].MODEL = (GPIO->P[0].MODEL & ~_GPIO_P_MODEL_MODE0_MASK) | GPIO_P_MODEL_MODE0_INPUT;

	/* Pin PA1 is configured to Push-pull */
	GPIO->P[0].MODEL = (GPIO->P[0].MODEL & ~_GPIO_P_MODEL_MODE1_MASK) | GPIO_P_MODEL_MODE1_PUSHPULL;

	/* Pin PA2 is configured to Push-pull */
	GPIO->P[0].MODEL = (GPIO->P[0].MODEL & ~_GPIO_P_MODEL_MODE2_MASK) | GPIO_P_MODEL_MODE2_PUSHPULL;

	/* Pin PA8 is configured to Input enabled */
	GPIO->P[0].MODEH = (GPIO->P[0].MODEH & ~_GPIO_P_MODEH_MODE8_MASK) | GPIO_P_MODEH_MODE8_INPUT;

	/* Pin PA9 is configured to Input enabled with pull-up */
	GPIO->P[0].MODEH = (GPIO->P[0].MODEH & ~_GPIO_P_MODEH_MODE9_MASK) | GPIO_P_MODEH_MODE9_INPUTPULL;
	GPIO->P[0].DOUT |= (1 << 9);

	/* Pin PA10 is configured to Input enabled with pull-up */
	GPIO->P[0].MODEH = (GPIO->P[0].MODEH & ~_GPIO_P_MODEH_MODE10_MASK) | GPIO_P_MODEH_MODE10_INPUTPULL;
	GPIO->P[0].DOUT |= (1 << 10);
	// [Port A Configuration]$


	// $[Port B Configuration]

	/* Port B drive strength set to Low (1 mA) */
	GPIO->P[1].CTRL = (GPIO->P[1].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;
	// [Port B Configuration]$


	// $[Port C Configuration]

	/* Port C drive strength set to Low (1 mA) */
	GPIO->P[2].CTRL = (GPIO->P[2].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;

	/* Pin PC4 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE4_MASK) | GPIO_P_MODEL_MODE4_WIREDANDPULLUPFILTER;

	/* Pin PC5 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE5_MASK) | GPIO_P_MODEL_MODE5_WIREDANDPULLUPFILTER;

	/* Pin PC6 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE6_MASK) | GPIO_P_MODEL_MODE6_WIREDANDPULLUPFILTER;
	GPIO->P[2].DOUT |= (1 << 6);

	/* Pin PC7 is configured to Open-drain with pull-up and filter */
	GPIO->P[2].MODEL = (GPIO->P[2].MODEL & ~_GPIO_P_MODEL_MODE7_MASK) | GPIO_P_MODEL_MODE7_WIREDANDPULLUPFILTER;
	GPIO->P[2].DOUT |= (1 << 7);
	// [Port C Configuration]$


	// $[Port D Configuration]

	/* Port D drive strength set to Low (1 mA) */
	GPIO->P[3].CTRL = (GPIO->P[3].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;

	/* Pin PD0 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE0_MASK) | GPIO_P_MODEL_MODE0_PUSHPULL;

	/* Pin PD1 is configured to Input enabled */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE1_MASK) | GPIO_P_MODEL_MODE1_INPUT;

	/* Pin PD2 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE2_MASK) | GPIO_P_MODEL_MODE2_PUSHPULL;

	/* Pin PD3 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE3_MASK) | GPIO_P_MODEL_MODE3_PUSHPULL;

	/* Pin PD4 is configured to Input enabled */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE4_MASK) | GPIO_P_MODEL_MODE4_INPUT;

	/* Pin PD5 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE5_MASK) | GPIO_P_MODEL_MODE5_PUSHPULL;
	GPIO->P[3].DOUT |= (1 << 5);

	/* Pin PD6 is configured to Input enabled */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE6_MASK) | GPIO_P_MODEL_MODE6_INPUT;

	/* Pin PD7 is configured to Push-pull */
	GPIO->P[3].MODEL = (GPIO->P[3].MODEL & ~_GPIO_P_MODEL_MODE7_MASK) | GPIO_P_MODEL_MODE7_PUSHPULL;
	GPIO->P[3].DOUT |= (1 << 7);

	/* Pin PD8 is configured to Input enabled with pull-up */
	GPIO->P[3].MODEH = (GPIO->P[3].MODEH & ~_GPIO_P_MODEH_MODE8_MASK) | GPIO_P_MODEH_MODE8_INPUTPULL;
	GPIO->P[3].DOUT |= (1 << 8);
	// [Port D Configuration]$


	// $[Port E Configuration]

	/* Port E drive strength set to Low (1 mA) */
	GPIO->P[4].CTRL = (GPIO->P[4].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;

	/* Pin PE8 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE8_MASK) | GPIO_P_MODEH_MODE8_PUSHPULL;

	/* Pin PE9 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE9_MASK) | GPIO_P_MODEH_MODE9_PUSHPULL;

	/* Pin PE10 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE10_MASK) | GPIO_P_MODEH_MODE10_PUSHPULL;

	/* Pin PE11 is configured to Input enabled */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE11_MASK) | GPIO_P_MODEH_MODE11_INPUT;

	/* Pin PE12 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE12_MASK) | GPIO_P_MODEH_MODE12_PUSHPULL;

	/* Pin PE13 is configured to Push-pull */
	GPIO->P[4].MODEH = (GPIO->P[4].MODEH & ~_GPIO_P_MODEH_MODE13_MASK) | GPIO_P_MODEH_MODE13_PUSHPULL;
	// [Port E Configuration]$


	// $[Port F Configuration]

	/* Port F drive strength set to Low (1 mA) */
	GPIO->P[5].CTRL = (GPIO->P[5].CTRL & ~_GPIO_P_CTRL_DRIVEMODE_MASK) | GPIO_P_CTRL_DRIVEMODE_LOW;

	/* Pin PF0 is configured to Push-pull */
	GPIO->P[5].MODEL = (GPIO->P[5].MODEL & ~_GPIO_P_MODEL_MODE0_MASK) | GPIO_P_MODEL_MODE0_PUSHPULL;

	/* Pin PF1 is configured to Input enabled */
	GPIO->P[5].MODEL = (GPIO->P[5].MODEL & ~_GPIO_P_MODEL_MODE1_MASK) | GPIO_P_MODEL_MODE1_INPUT;

	/* Pin PF2 is configured to Push-pull */
	GPIO->P[5].MODEL = (GPIO->P[5].MODEL & ~_GPIO_P_MODEL_MODE2_MASK) | GPIO_P_MODEL_MODE2_PUSHPULL;
	// [Port F Configuration]$


	// $[Route Configuration]

	/* Disabling DBG interface. Warning: The chip may be hard to get in touch with. It
	 * may be necessary to use the "unlock" feature in energyAware Commander to access
	 * the debug interface again. */
	GPIO->ROUTE &= ~(GPIO_ROUTE_SWCLKPEN | GPIO_ROUTE_SWDIOPEN);

	/* Module I2C0 is configured to location 2 */
	I2C0->ROUTE = (I2C0->ROUTE & ~_I2C_ROUTE_LOCATION_MASK) | I2C_ROUTE_LOCATION_LOC2;

	/* Enable signals SCL, SDA */
	I2C0->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

	/* Enable signals SCL, SDA */
	I2C1->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

	/* Module PCNT0 is configured to location 2 */
	PCNT0->ROUTE = (PCNT0->ROUTE & ~_PCNT_ROUTE_LOCATION_MASK) | PCNT_ROUTE_LOCATION_LOC2;

	/* Enable signals CLK, CS, RX, TX */
	USART0->ROUTE |= USART_ROUTE_CLKPEN | USART_ROUTE_CSPEN | USART_ROUTE_RXPEN |
		USART_ROUTE_TXPEN;

	/* Module USART1 is configured to location 1 */
	USART1->ROUTE = (USART1->ROUTE & ~_USART_ROUTE_LOCATION_MASK) | USART_ROUTE_LOCATION_LOC1;

	/* Enable signals CLK, CS, RX, TX */
	USART1->ROUTE |= USART_ROUTE_CLKPEN | USART_ROUTE_CSPEN | USART_ROUTE_RXPEN |
		USART_ROUTE_TXPEN;
	// [Route Configuration]$


}

