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
LIBS:special
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
Sheet 8 10
Title "uC part B"
Date "17 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EFM32GG332 U1
U 2 1 550823D3
P 3000 950
F 0 "U1" H 3100 900 60  0000 C CNN
F 1 "EFM32GG332" H 4500 900 60  0000 C CNN
F 2 "Housings_QFP:TQFP-64_10x10mm_Pitch0.5mm" H 4500 900 60  0001 C CNN
F 3 "" H 4500 900 60  0000 C CNN
	2    3000 950 
	1    0    0    -1  
$EndComp
Text HLabel 2650 1550 0    60   3State ~ 0
I2C1_SDA
Text HLabel 2650 1650 0    60   3State ~ 0
I2C1_SCL
Text HLabel 2650 1750 0    60   3State ~ 0
I2C0_SDA
Text HLabel 2650 1850 0    60   3State ~ 0
I2C0_SCL
Wire Wire Line
	2650 1550 2800 1550
Wire Wire Line
	2800 1650 2650 1650
Wire Wire Line
	2650 1750 2800 1750
Wire Wire Line
	2650 1850 2800 1850
Text HLabel 2650 2550 0    60   3State ~ 0
US1_TX
Text HLabel 2650 2650 0    60   3State ~ 0
US1_RX
Text HLabel 2650 2750 0    60   3State ~ 0
US1_CLK
Text HLabel 2650 2850 0    60   3State ~ 0
US1_CS
Wire Wire Line
	2650 2550 2800 2550
Wire Wire Line
	2800 2650 2650 2650
Wire Wire Line
	2650 2750 2800 2750
Wire Wire Line
	2800 2850 2650 2850
Text HLabel 1900 2950 0    60   3State ~ 0
PD4
Text HLabel 1900 3050 0    60   3State ~ 0
PD5
Wire Wire Line
	1900 2950 2800 2950
Wire Wire Line
	2800 3050 1900 3050
Text HLabel 2150 1450 0    60   3State ~ 0
PC3
Wire Wire Line
	2150 1450 2800 1450
Text HLabel 1650 3350 0    60   3State ~ 0
PD8
Wire Wire Line
	2800 3350 1650 3350
Text HLabel 2600 3150 0    60   BiDi ~ 0
PD6
Text HLabel 2600 3250 0    60   BiDi ~ 0
PD7
Wire Wire Line
	2800 3150 2600 3150
Wire Wire Line
	2600 3250 2800 3250
$EndSCHEMATC
