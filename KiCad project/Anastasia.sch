EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Anastasia
LIBS:Anastasia-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 10
Title "Smartwatch"
Date "14 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2900 3900 1300 1100
U 5504D17E
F0 "uC part A" 60
F1 "Sheet2.sch" 60
F2 "PA8" I L 2900 4100 60 
F3 "PA0" T R 4200 4100 60 
F4 "PA1" T R 4200 4250 60 
F5 "PA2" T R 4200 4400 60 
F6 "PA9" T R 4200 4850 60 
F7 "PA10" T R 4200 4700 60 
$EndSheet
$Sheet
S 2900 2600 1300 1100
U 5504DA44
F0 "IMU" 60
F1 "Sheet3.sch" 60
F2 "IMU_SDA" B R 4200 2850 60 
F3 "IMU_SCL" B R 4200 2950 60 
F4 "IMU_INT" O L 2900 3550 60 
$EndSheet
$Sheet
S 8150 2500 1250 1100
U 55054148
F0 "Display" 60
F1 "Sheet4.sch" 60
F2 "DISP_CS" I L 8150 3300 60 
F3 "DISP_SI" I L 8150 2600 60 
F4 "DISP_CLK" I L 8150 2700 60 
F5 "DISP_ON/OFF" I L 8150 3450 60 
$EndSheet
$Sheet
S 4650 2650 1250 1050
U 550790E4
F0 "EEPROM" 60
F1 "Sheet6.sch" 60
F2 "MEM_SCL" B L 4650 2950 60 
F3 "MEM_SDA" B L 4650 2850 60 
$EndSheet
$Sheet
S 700  1150 1300 1050
U 5507E4D4
F0 "Pulse oximeter " 60
F1 "Sheet7.sch" 60
F2 "SCLK" I R 2000 1450 60 
F3 "MOSI" I R 2000 1250 60 
F4 "MISO" O R 2000 1350 60 
F5 "SPIEN" I R 2000 1550 60 
F6 "RESET" I R 2000 1800 60 
F7 "ADC_RDY" O R 2000 1700 60 
F8 "AFE_PDN" I R 2000 2000 60 
F9 "DIAG_END" O R 2000 2100 60 
$EndSheet
$Sheet
S 2900 1150 1250 1100
U 55081790
F0 "uC part B" 60
F1 "Sheet8.sch" 60
F2 "I2C1_SDA" T R 4150 2050 60 
F3 "I2C1_SCL" T R 4150 2150 60 
F4 "I2C0_SDA" T R 4150 1250 60 
F5 "I2C0_SCL" T R 4150 1350 60 
F6 "US1_TX" T L 2900 1250 60 
F7 "US1_RX" T L 2900 1350 60 
F8 "US1_CLK" T L 2900 1450 60 
F9 "US1_CS" T L 2900 1550 60 
F10 "PD4" T L 2900 1700 60 
F11 "PD5" T L 2900 1800 60 
F12 "PD8" T R 4150 1600 60 
F13 "PD6" B L 2900 2100 60 
F14 "PD7" B L 2900 2000 60 
$EndSheet
$Sheet
S 6400 1150 1150 1100
U 55081795
F0 "uC part C" 60
F1 "Sheet9.sch" 60
F2 "USB_DM" T L 6400 1350 60 
F3 "USB_DP" T L 6400 1250 60 
F4 "US0_TX" T R 7550 1900 60 
F5 "US0_RX" T R 7550 2000 60 
F6 "US0_CLK" T R 7550 2100 60 
F7 "PF0" T R 7550 1300 60 
F8 "PF1" T R 7550 1550 60 
F9 "PF2" T R 7550 1650 60 
F10 "PE9" T L 6400 2150 60 
F11 "PE8" T L 6400 2000 60 
$EndSheet
$Sheet
S 8150 1150 1250 1050
U 550556D4
F0 "Bluetooth LE" 60
F1 "Sheet5.sch" 60
F2 "RESET_RADIO" I L 8150 1300 60 
F3 "ACTIVE" O L 8150 1450 60 
F4 "RDYN" O L 8150 1550 60 
F5 "REQN" I L 8150 1650 60 
F6 "MOSI" I L 8150 1900 60 
F7 "MISO" O L 8150 2000 60 
F8 "SCK" I L 8150 2100 60 
$EndSheet
Wire Wire Line
	5900 1250 6400 1250
Wire Wire Line
	6400 1350 5900 1350
Wire Wire Line
	4150 1250 4650 1250
Wire Wire Line
	4150 1350 4650 1350
Wire Wire Line
	2000 1250 2900 1250
Wire Wire Line
	2000 1350 2900 1350
Wire Wire Line
	2000 1450 2900 1450
Wire Wire Line
	2000 1550 2900 1550
Wire Wire Line
	7550 1900 8150 1900
Wire Wire Line
	7550 2000 8150 2000
Wire Wire Line
	7550 2100 8150 2100
Wire Wire Line
	7900 1900 7900 2600
Wire Wire Line
	7900 2600 8150 2600
Connection ~ 7900 1900
Wire Wire Line
	7800 2700 8150 2700
Connection ~ 7800 2100
Wire Wire Line
	4200 2850 4650 2850
Wire Wire Line
	4200 2950 4650 2950
Wire Wire Line
	4400 2950 4400 3100
Connection ~ 4400 2950
$Comp
L TESTPAD TP11
U 1 1 550D359E
P 4400 3100
F 0 "TP11" H 4650 3100 60  0000 C CNN
F 1 "TESTPAD" H 4450 2900 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 4650 3100 60  0001 C CNN
F 3 "" H 4650 3100 60  0000 C CNN
	1    4400 3100
	0    1    1    0   
$EndComp
$Comp
L TESTPAD TP7
U 1 1 550D3AEA
P 7650 2350
F 0 "TP7" H 7900 2350 60  0000 C CNN
F 1 "TESTPAD" H 7700 2150 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 7900 2350 60  0001 C CNN
F 3 "" H 7900 2350 60  0000 C CNN
	1    7650 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 2350 7650 2000
Connection ~ 7650 2000
Wire Wire Line
	2900 4100 2650 4100
Wire Wire Line
	2650 4100 2650 3550
Wire Wire Line
	2650 3550 2900 3550
Wire Wire Line
	8150 1650 7550 1650
Wire Wire Line
	8150 1450 8050 1450
Wire Wire Line
	8050 1450 8050 850 
Wire Wire Line
	8050 850  9700 850 
Wire Wire Line
	9700 850  9700 4100
Wire Wire Line
	9700 4100 4200 4100
Wire Wire Line
	8150 1300 7550 1300
Wire Wire Line
	7550 1550 8150 1550
Wire Wire Line
	2900 1700 2000 1700
Wire Wire Line
	2000 1800 2900 1800
Wire Wire Line
	2000 2000 2900 2000
Wire Wire Line
	2000 2100 2900 2100
$Sheet
S 4650 1150 1250 1100
U 55046F13
F0 "Power" 60
F1 "Sheet1.sch" 60
F2 "MCU_RESET" I L 4650 1850 60 
F3 "USB_DP" T R 5900 1250 60 
F4 "USB_DN" T R 5900 1350 60 
F5 "PG" I L 4650 1950 60 
F6 "ISET" I L 4650 2050 60 
F7 "STAT1" O R 5900 1850 60 
F8 "STAT2" O R 5900 2150 60 
F9 "CE" I L 4650 2150 60 
F10 "GPOUT" B L 4650 1600 60 
F11 "GAUGE_SCL" B L 4650 1350 60 
F12 "GAUGE_SDA" B L 4650 1250 60 
$EndSheet
Wire Wire Line
	4650 1600 4150 1600
Wire Wire Line
	8150 3300 6350 3300
Wire Wire Line
	6350 3300 6350 2150
Wire Wire Line
	6350 2150 6400 2150
Wire Wire Line
	6400 2000 6250 2000
Wire Wire Line
	6250 2000 6250 3450
Wire Wire Line
	6250 3450 8150 3450
Wire Wire Line
	4200 4250 4450 4250
Wire Wire Line
	4450 4250 4450 2050
Wire Wire Line
	4450 2050 4650 2050
Wire Wire Line
	4200 4400 4550 4400
Wire Wire Line
	4550 4400 4550 2150
Wire Wire Line
	4550 2150 4650 2150
Wire Wire Line
	5900 2150 6000 2150
Wire Wire Line
	6000 2150 6000 4700
Wire Wire Line
	6000 4700 4200 4700
Wire Wire Line
	4200 4850 6100 4850
Wire Wire Line
	6100 4850 6100 1850
Wire Wire Line
	6100 1850 5900 1850
Wire Wire Line
	7800 2100 7800 2700
Wire Wire Line
	4150 2150 4250 2150
Wire Wire Line
	4250 2150 4250 2950
Connection ~ 4250 2950
Wire Wire Line
	4150 2050 4350 2050
Wire Wire Line
	4350 2050 4350 2850
Connection ~ 4350 2850
Text Notes 6900 5600 0    60   ~ 0
Copyright Tuomas Tinus, Jimi Järvelin 2015.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.2.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.2. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.2 for applicable\nconditions
$EndSCHEMATC
