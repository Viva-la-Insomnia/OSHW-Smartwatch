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
Sheet 4 10
Title "IMU MPU-9150"
Date "15 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +3V3 #PWR019
U 1 1 5504DED0
P 4750 1000
F 0 "#PWR019" H 4750 850 60  0001 C CNN
F 1 "+3V3" H 4750 1140 60  0000 C CNN
F 2 "" H 4750 1000 60  0000 C CNN
F 3 "" H 4750 1000 60  0000 C CNN
	1    4750 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 5504DEF3
P 4750 1550
F 0 "#PWR020" H 4750 1300 60  0001 C CNN
F 1 "GND" H 4750 1400 60  0000 C CNN
F 2 "" H 4750 1550 60  0000 C CNN
F 3 "" H 4750 1550 60  0000 C CNN
	1    4750 1550
	1    0    0    -1  
$EndComp
$Comp
L C C21
U 1 1 5504DF2D
P 4350 1550
F 0 "C21" H 4400 1650 50  0000 L CNN
F 1 "10N" H 4400 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4388 1400 30  0001 C CNN
F 3 "" H 4350 1550 60  0000 C CNN
	1    4350 1550
	1    0    0    -1  
$EndComp
$Comp
L MPU-9150 U5
U 1 1 5504E110
P 3100 750
F 0 "U5" H 3150 800 60  0000 C CNN
F 1 "MPU-9150" H 3550 -750 60  0000 C CNN
F 2 "Anastasia:LGA24" H 3100 750 60  0001 C CNN
F 3 "" H 3100 750 60  0000 C CNN
	1    3100 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1050 4000 1200
Wire Wire Line
	4750 1050 4750 1000
Connection ~ 4000 1050
Connection ~ 4750 1050
Wire Wire Line
	4350 1350 4000 1350
Wire Wire Line
	4000 1650 4000 1950
Connection ~ 4000 1750
Wire Wire Line
	4000 1450 4150 1450
Wire Wire Line
	4150 1450 4150 2100
$Comp
L C C23
U 1 1 5504E266
P 4150 2300
F 0 "C23" H 4200 2400 50  0000 L CNN
F 1 "0.1U" H 4200 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4188 2150 30  0001 C CNN
F 3 "" H 4150 2300 60  0000 C CNN
	1    4150 2300
	1    0    0    -1  
$EndComp
Connection ~ 4150 2100
$Comp
L C C20
U 1 1 5504E2C2
P 4750 1250
F 0 "C20" H 4800 1350 50  0000 L CNN
F 1 "0.1U" H 4800 1150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4788 1100 30  0001 C CNN
F 3 "" H 4750 1250 60  0000 C CNN
	1    4750 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1450 4750 1550
Wire Wire Line
	4000 1050 4750 1050
$Comp
L +3V3 #PWR021
U 1 1 5504E385
P 4350 1250
F 0 "#PWR021" H 4350 1100 60  0001 C CNN
F 1 "+3V3" H 4350 1390 60  0000 C CNN
F 2 "" H 4350 1250 60  0000 C CNN
F 3 "" H 4350 1250 60  0000 C CNN
	1    4350 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1250 4350 1350
$Comp
L GND #PWR022
U 1 1 5504E3C5
P 4350 1850
F 0 "#PWR022" H 4350 1600 60  0001 C CNN
F 1 "GND" H 4350 1700 60  0000 C CNN
F 2 "" H 4350 1850 60  0000 C CNN
F 3 "" H 4350 1850 60  0000 C CNN
	1    4350 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 5504E3EC
P 4150 2600
F 0 "#PWR023" H 4150 2350 60  0001 C CNN
F 1 "GND" H 4150 2450 60  0000 C CNN
F 2 "" H 4150 2600 60  0000 C CNN
F 3 "" H 4150 2600 60  0000 C CNN
	1    4150 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1750 4350 1850
Wire Wire Line
	4150 2500 4150 2600
$Comp
L GND #PWR024
U 1 1 5504E44A
P 4000 1950
F 0 "#PWR024" H 4000 1700 60  0001 C CNN
F 1 "GND" H 4000 1800 60  0000 C CNN
F 2 "" H 4000 1950 60  0000 C CNN
F 3 "" H 4000 1950 60  0000 C CNN
	1    4000 1950
	1    0    0    -1  
$EndComp
Connection ~ 4000 1850
$Comp
L C C22
U 1 1 5504E476
P 2900 2000
F 0 "C22" H 2950 2100 50  0000 L CNN
F 1 "2.2N" H 2950 1900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2938 1850 30  0001 C CNN
F 3 "" H 2900 2000 60  0000 C CNN
	1    2900 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 5504E498
P 2900 2300
F 0 "#PWR025" H 2900 2050 60  0001 C CNN
F 1 "GND" H 2900 2150 60  0000 C CNN
F 2 "" H 2900 2300 60  0000 C CNN
F 3 "" H 2900 2300 60  0000 C CNN
	1    2900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1650 2900 1800
Wire Wire Line
	2900 2200 2900 2300
$Comp
L GND #PWR026
U 1 1 550533AC
P 2350 1500
F 0 "#PWR026" H 2350 1250 60  0001 C CNN
F 1 "GND" H 2350 1350 60  0000 C CNN
F 2 "" H 2350 1500 60  0000 C CNN
F 3 "" H 2350 1500 60  0000 C CNN
	1    2350 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1450 2350 1450
Wire Wire Line
	2350 850  2350 1500
Wire Wire Line
	2900 1350 2350 1350
Connection ~ 2350 1450
Wire Wire Line
	2900 850  2350 850 
Connection ~ 2350 1350
Text Notes 1050 1450 0    60   ~ 0
Connect pin 9 to 3V3 \nto change LSB of \nthe I2C address of the chip
Text HLabel 4100 950  2    60   Input ~ 0
IMU_SDA
Text HLabel 4100 850  2    60   Input ~ 0
IMU_SCL
Wire Wire Line
	4100 850  4000 850 
Wire Wire Line
	4000 950  4100 950 
Text HLabel 2300 1850 0    60   Input ~ 0
IMU_INT
Wire Wire Line
	2900 1550 2650 1550
Wire Wire Line
	2650 1550 2650 1850
Wire Wire Line
	2650 1850 2300 1850
Connection ~ 4000 1100
NoConn ~ 2900 1200
NoConn ~ 2900 1100
NoConn ~ 2900 950 
$EndSCHEMATC
