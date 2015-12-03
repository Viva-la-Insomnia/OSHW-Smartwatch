/**************************************************************************//**
 * @file EEPROM.h
 * @brief I2C EEPROM library header
 * @author Tuomas Tinus, Jimi Järvelin
 * @version 0.5
 ******************************************************************************/
//This library is a modified port of
/***************************************************************************//**
 * @file
 * @brief EEPROM driver for 24AA024 (2Kbit) EEPROM device on the DK.
 * @version 4.0.0
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#ifndef EEPROM_H_
#define EEPROM_H_
#endif

//Reads data of length len from address offset
extern int EEPROM_Read(unsigned int offset,
		uint8_t *data,
		unsigned int len);

//Writes data of length len to address offset
extern int EEPROM_Write(unsigned int offset,
		uint8_t *data,
		unsigned int len);
