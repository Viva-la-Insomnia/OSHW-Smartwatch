/**************************************************************************//**
 * @file BQ25010.h
 * @brief BQ25010 interface code header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/

extern void BQ25010_init(void);
extern int BQ25010_get_status(void);
extern void BQ25010_charge_on(void);
extern void BQ25010_charge_off(void);
extern void BQ25010_USB_charge_high(void);
extern void BQ25010_USB_charge_low(void);




