/**************************************************************************//**
 * @file BQ27421.h
 * @brief BQ27421 interface code header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

extern unsigned long BQ27421_Get_Device_Type(void);
extern unsigned long BQ27421_Get_Temp(void);
extern unsigned long BQ27421_Get_Pack_Voltage(void);
extern int BQ27421_Init(void);
