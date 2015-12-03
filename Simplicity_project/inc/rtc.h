/**************************************************************************//**
 * @file rtc.h
 * @brief Real-time-clock library header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

#ifndef RTC_H_
#define RTC_H_
#endif

extern void RTC_Mod_Init(void); //Inits the RTC module
extern uint32_t RTC_GetTime(void); //Returns time in HHMMSS format
void RTC_IRQHandler(void); //Internal interrupt handler
