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
Sheet 2 10
Title "Power"
Date "14 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L C C1
U 1 1 5504745A
P 2250 1200
F 0 "C1" H 2300 1300 50  0000 L CNN
F 1 "100N" H 2300 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2288 1050 30  0001 C CNN
F 3 "" H 2250 1200 60  0000 C CNN
	1    2250 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 55047461
P 2250 1400
F 0 "#PWR01" H 2250 1150 60  0001 C CNN
F 1 "GND" H 2250 1250 60  0000 C CNN
F 2 "" H 2250 1400 60  0000 C CNN
F 3 "" H 2250 1400 60  0000 C CNN
	1    2250 1400
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR02
U 1 1 5504746F
P 2050 1950
F 0 "#PWR02" H 2050 1800 60  0001 C CNN
F 1 "+3V3" H 2050 2090 60  0000 C CNN
F 2 "" H 2050 1950 60  0000 C CNN
F 3 "" H 2050 1950 60  0000 C CNN
	1    2050 1950
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 55047475
P 2500 2150
F 0 "R1" V 2580 2150 50  0000 C CNN
F 1 "1R" V 2507 2151 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2430 2150 30  0001 C CNN
F 3 "" H 2500 2150 30  0000 C CNN
	1    2500 2150
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 5504747C
P 2950 2350
F 0 "C5" H 3000 2450 50  0000 L CNN
F 1 "10U" H 3000 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2988 2200 30  0001 C CNN
F 3 "" H 2950 2350 60  0000 C CNN
	1    2950 2350
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 55047483
P 3300 2350
F 0 "C6" H 3350 2450 50  0000 L CNN
F 1 "10N" H 3350 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3338 2200 30  0001 C CNN
F 3 "" H 3300 2350 60  0000 C CNN
	1    3300 2350
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5504748A
P 3550 2350
F 0 "C7" H 3600 2450 50  0000 L CNN
F 1 "10N" H 3600 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3588 2200 30  0001 C CNN
F 3 "" H 3550 2350 60  0000 C CNN
	1    3550 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 55047491
P 2750 2650
F 0 "#PWR03" H 2750 2400 60  0001 C CNN
F 1 "GND" H 2750 2500 60  0000 C CNN
F 2 "" H 2750 2650 60  0000 C CNN
F 3 "" H 2750 2650 60  0000 C CNN
	1    2750 2650
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 55047497
P 6250 1450
F 0 "C2" H 6300 1550 50  0000 L CNN
F 1 "1U" H 6300 1350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6288 1300 30  0001 C CNN
F 3 "" H 6250 1450 60  0000 C CNN
	1    6250 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5504749E
P 6250 1650
F 0 "#PWR04" H 6250 1400 60  0001 C CNN
F 1 "GND" H 6250 1500 60  0000 C CNN
F 2 "" H 6250 1650 60  0000 C CNN
F 3 "" H 6250 1650 60  0000 C CNN
	1    6250 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR05
U 1 1 550474A4
P 6950 2250
F 0 "#PWR05" H 6950 2100 60  0001 C CNN
F 1 "+3V3" H 6950 2390 60  0000 C CNN
F 2 "" H 6950 2250 60  0000 C CNN
F 3 "" H 6950 2250 60  0000 C CNN
	1    6950 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 550474AB
P 6850 2750
F 0 "#PWR06" H 6850 2500 60  0001 C CNN
F 1 "GND" H 6850 2600 60  0000 C CNN
F 2 "" H 6850 2750 60  0000 C CNN
F 3 "" H 6850 2750 60  0000 C CNN
	1    6850 2750
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 550474B1
P 6100 2550
F 0 "C8" H 6150 2650 50  0000 L CNN
F 1 "100N" H 6150 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6138 2400 30  0001 C CNN
F 3 "" H 6100 2550 60  0000 C CNN
	1    6100 2550
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 550474B8
P 6350 2550
F 0 "C9" H 6400 2650 50  0000 L CNN
F 1 "100N" H 6400 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6388 2400 30  0001 C CNN
F 3 "" H 6350 2550 60  0000 C CNN
	1    6350 2550
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 550474BF
P 6600 2550
F 0 "C10" H 6650 2650 50  0000 L CNN
F 1 "100N" H 6650 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6638 2400 30  0001 C CNN
F 3 "" H 6600 2550 60  0000 C CNN
	1    6600 2550
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 550474C6
P 6950 2550
F 0 "C11" H 7000 2650 50  0000 L CNN
F 1 "10U" H 7000 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6988 2400 30  0001 C CNN
F 3 "" H 6950 2550 60  0000 C CNN
	1    6950 2550
	1    0    0    -1  
$EndComp
Text Notes 6450 1500 0    60   ~ 0
A decoupling cap\n
Text Notes 6050 3050 0    60   ~ 0
Power capacitors
Text Notes 1900 950  0    60   ~ 0
The uC reset line
$Comp
L EFM32GG332 U?
U 4 1 550474D0
P 3950 1050
AR Path="/550474D0" Ref="U?"  Part="4" 
AR Path="/55046F13/550474D0" Ref="U1"  Part="4" 
F 0 "U1" H 4050 1000 60  0000 C CNN
F 1 "EFM32GG332" H 5450 1000 60  0000 C CNN
F 2 "Housings_QFP:TQFP-64_10x10mm_Pitch0.5mm" H 5450 1000 60  0001 C CNN
F 3 "" H 5450 1000 60  0000 C CNN
	4    3950 1050
	1    0    0    -1  
$EndComp
$Comp
L BQ2501x U2
U 1 1 550474D7
P 2800 3400
F 0 "U2" H 2850 3450 60  0000 C CNN
F 1 "BQ25011" H 3300 2300 60  0000 C CNN
F 2 "Anastasia:VQFN20" H 3300 2300 60  0001 C CNN
F 3 "" H 3300 2300 60  0000 C CNN
	1    2800 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 550474DE
P 2300 3750
F 0 "#PWR07" H 2300 3500 60  0001 C CNN
F 1 "GND" H 2300 3600 60  0000 C CNN
F 2 "" H 2300 3750 60  0000 C CNN
F 3 "" H 2300 3750 60  0000 C CNN
	1    2300 3750
	1    0    0    -1  
$EndComp
$Comp
L USB-MICRO-B CON1
U 1 1 550474E4
P 3150 5000
F 0 "CON1" H 2850 5350 50  0000 C CNN
F 1 "USB-MICRO-B" H 3000 4650 50  0000 C CNN
F 2 "Connect:USB_Micro-B" H 3150 4900 50  0001 C CNN
F 3 "" H 3150 4900 50  0000 C CNN
	1    3150 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 550474EB
P 2250 5400
F 0 "#PWR08" H 2250 5150 60  0001 C CNN
F 1 "GND" H 2250 5250 60  0000 C CNN
F 2 "" H 2250 5400 60  0000 C CNN
F 3 "" H 2250 5400 60  0000 C CNN
	1    2250 5400
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 550474F1
P 1650 5000
F 0 "C13" H 1700 5100 50  0000 L CNN
F 1 "0.1U" H 1700 4900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1688 4850 30  0001 C CNN
F 3 "" H 1650 5000 60  0000 C CNN
	1    1650 5000
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L1
U 1 1 550474F8
P 4200 3650
F 0 "L1" V 4150 3650 50  0000 C CNN
F 1 "47UH" V 4300 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4200 3650 60  0001 C CNN
F 3 "" H 4200 3650 60  0000 C CNN
	1    4200 3650
	0    1    1    0   
$EndComp
$Comp
L C C12
U 1 1 550474FF
P 4700 3800
F 0 "C12" H 4750 3900 50  0000 L CNN
F 1 "2.2U" H 4750 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4738 3650 30  0001 C CNN
F 3 "" H 4700 3800 60  0000 C CNN
	1    4700 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 55047506
P 4700 4100
F 0 "#PWR09" H 4700 3850 60  0001 C CNN
F 1 "GND" H 4700 3950 60  0000 C CNN
F 2 "" H 4700 4100 60  0000 C CNN
F 3 "" H 4700 4100 60  0000 C CNN
	1    4700 4100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR010
U 1 1 5504750C
P 4700 3450
F 0 "#PWR010" H 4700 3300 60  0001 C CNN
F 1 "+3V3" H 4700 3590 60  0000 C CNN
F 2 "" H 4700 3450 60  0000 C CNN
F 3 "" H 4700 3450 60  0000 C CNN
	1    4700 3450
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 55047512
P 4100 4150
F 0 "R3" V 4180 4150 50  0000 C CNN
F 1 "1K6" V 4107 4151 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4030 4150 30  0001 C CNN
F 3 "" H 4100 4150 30  0000 C CNN
	1    4100 4150
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 5504751C
P 3400 1700
F 0 "C3" V 3450 1800 50  0000 L CNN
F 1 "4.7U" V 3350 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3438 1550 30  0001 C CNN
F 3 "" H 3400 1700 60  0000 C CNN
	1    3400 1700
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 55047523
P 3400 1950
F 0 "C4" V 3450 2050 50  0000 L CNN
F 1 "1U" V 3450 1700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3438 1800 30  0001 C CNN
F 3 "" H 3400 1950 60  0000 C CNN
	1    3400 1950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5504752A
P 2950 1850
F 0 "#PWR011" H 2950 1600 60  0001 C CNN
F 1 "GND" H 2950 1700 60  0000 C CNN
F 2 "" H 2950 1850 60  0000 C CNN
F 3 "" H 2950 1850 60  0000 C CNN
	1    2950 1850
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 55047530
P 3100 5750
F 0 "R4" V 3180 5750 50  0000 C CNN
F 1 "15R" V 3107 5751 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3030 5750 30  0001 C CNN
F 3 "" H 3100 5750 30  0000 C CNN
	1    3100 5750
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 55047537
P 3100 6000
F 0 "R6" V 3180 6000 50  0000 C CNN
F 1 "15R" V 3107 6001 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3030 6000 30  0001 C CNN
F 3 "" H 3100 6000 30  0000 C CNN
	1    3100 6000
	0    1    1    0   
$EndComp
Text Notes 2750 5600 0    60   ~ 0
USB connector and data lines\n
Text Notes 2650 1550 0    60   ~ 0
USB Power to IC
$Comp
L BATTERY BT1
U 1 1 550477FF
P 7700 5800
F 0 "BT1" H 7700 6000 50  0000 C CNN
F 1 "BATTERY" H 7700 5610 50  0000 C CNN
F 2 "Anastasia:BATTERY" H 7700 5800 60  0001 C CNN
F 3 "" H 7700 5800 60  0000 C CNN
	1    7700 5800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 55047918
P 8250 5800
F 0 "#PWR012" H 8250 5550 60  0001 C CNN
F 1 "GND" H 8250 5650 60  0000 C CNN
F 2 "" H 8250 5800 60  0000 C CNN
F 3 "" H 8250 5800 60  0000 C CNN
	1    8250 5800
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 550479A6
P 7250 6000
F 0 "C14" H 7300 6100 50  0000 L CNN
F 1 "4.7U" H 7300 5900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7288 5850 30  0001 C CNN
F 3 "" H 7250 6000 60  0000 C CNN
	1    7250 6000
	1    0    0    -1  
$EndComp
Text HLabel 1750 1000 0    60   Input ~ 0
MCU_RESET
$Comp
L TESTPAD TP12
U 1 1 5506D7F2
P 1750 1150
F 0 "TP12" H 2000 1150 60  0000 C CNN
F 1 "TESTPAD" H 1800 950 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 2000 1150 60  0001 C CNN
F 3 "" H 2000 1150 60  0000 C CNN
	1    1750 1150
	-1   0    0    -1  
$EndComp
NoConn ~ 2600 3550
NoConn ~ 3700 4350
Text GLabel 1550 4800 0    60   Input ~ 0
USB_VBUS
Text GLabel 3200 1350 0    60   Input ~ 0
USB_VBUS
Text HLabel 3650 5750 2    60   Input ~ 0
USB_DP
Text HLabel 3650 6000 2    60   Input ~ 0
USB_DN
Text HLabel 3850 3450 2    60   Input ~ 0
PG
Text HLabel 3950 4500 2    60   Input ~ 0
ISET
Text HLabel 2500 4050 0    60   Input ~ 0
STAT1
Text HLabel 2500 4150 0    60   Input ~ 0
STAT2
$Comp
L R R2
U 1 1 5507251D
P 1700 3950
F 0 "R2" V 1780 3950 50  0000 C CNN
F 1 "1K" V 1707 3951 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1630 3950 30  0001 C CNN
F 3 "" H 1700 3950 30  0000 C CNN
	1    1700 3950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR013
U 1 1 55072596
P 1700 3600
F 0 "#PWR013" H 1700 3450 60  0001 C CNN
F 1 "+3V3" H 1700 3740 60  0000 C CNN
F 2 "" H 1700 3600 60  0000 C CNN
F 3 "" H 1700 3600 60  0000 C CNN
	1    1700 3600
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP14
U 1 1 55072D4F
P 1650 4600
F 0 "TP14" H 1900 4600 60  0000 C CNN
F 1 "TESTPAD" H 1700 4400 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 1900 4600 60  0001 C CNN
F 3 "" H 1900 4600 60  0000 C CNN
	1    1650 4600
	-1   0    0    -1  
$EndComp
$Comp
L TESTPAD TP15
U 1 1 550731F6
P 1650 5500
F 0 "TP15" H 1900 5500 60  0000 C CNN
F 1 "TESTPAD" H 1700 5300 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 1900 5500 60  0001 C CNN
F 3 "" H 1900 5500 60  0000 C CNN
	1    1650 5500
	-1   0    0    -1  
$EndComp
NoConn ~ 2650 5100
Text HLabel 3800 3850 2    60   Input ~ 0
CE
$Comp
L BQ27421-G1 U3
U 1 1 550850D9
P 5200 5450
F 0 "U3" H 5250 5500 60  0000 C CNN
F 1 "BQ27421-G1" H 5600 4600 60  0000 C CNN
F 2 "Anastasia:DSBGA9" H 5200 5450 60  0001 C CNN
F 3 "" H 5200 5450 60  0000 C CNN
	1    5200 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 55085BD1
P 6250 6200
F 0 "#PWR014" H 6250 5950 60  0001 C CNN
F 1 "GND" H 6250 6050 60  0000 C CNN
F 2 "" H 6250 6200 60  0000 C CNN
F 3 "" H 6250 6200 60  0000 C CNN
	1    6250 6200
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 55085D1A
P 6500 6050
F 0 "C15" H 6550 6150 50  0000 L CNN
F 1 "0.47U" H 6550 5950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6538 5900 30  0001 C CNN
F 3 "" H 6500 6050 60  0000 C CNN
	1    6500 6050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 55086166
P 4400 5850
F 0 "#PWR015" H 4400 5600 60  0001 C CNN
F 1 "GND" H 4400 5700 60  0000 C CNN
F 2 "" H 4400 5850 60  0000 C CNN
F 3 "" H 4400 5850 60  0000 C CNN
	1    4400 5850
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5508617A
P 4700 5850
F 0 "R5" V 4780 5850 50  0000 C CNN
F 1 "1.8M" V 4707 5851 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4630 5850 30  0001 C CNN
F 3 "" H 4700 5850 30  0000 C CNN
	1    4700 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 3850 3700 3850
Connection ~ 1650 5400
Wire Wire Line
	1650 4800 1650 4600
Wire Wire Line
	1700 3700 1700 3600
Wire Wire Line
	1700 4250 1700 4200
Wire Wire Line
	2600 4250 1700 4250
Wire Wire Line
	2500 4150 2600 4150
Wire Wire Line
	2600 4050 2500 4050
Wire Wire Line
	3850 3550 3850 3450
Wire Wire Line
	3700 3550 3850 3550
Wire Wire Line
	3900 4500 3950 4500
Wire Wire Line
	3900 4250 3900 4500
Wire Wire Line
	3700 4250 3900 4250
Connection ~ 1900 1000
Wire Wire Line
	1900 1150 1900 1000
Wire Wire Line
	1750 1150 1900 1150
Connection ~ 7400 5800
Connection ~ 7250 5800
Connection ~ 4700 4100
Connection ~ 3350 6000
Connection ~ 3350 5750
Connection ~ 8250 5800
Wire Wire Line
	8450 5800 8450 6200
Wire Wire Line
	8450 6200 7250 6200
Wire Wire Line
	8000 5800 8450 5800
Wire Wire Line
	4450 3950 4450 5150
Wire Wire Line
	3700 3950 4450 3950
Wire Wire Line
	3700 3950 3700 4050
Wire Wire Line
	3650 6000 3350 6000
Wire Wire Line
	3650 5750 3350 5750
Connection ~ 2850 6000
Connection ~ 2850 5750
Wire Wire Line
	1900 6000 2850 6000
Wire Wire Line
	2050 5750 2850 5750
Wire Wire Line
	2650 5000 2050 5000
Wire Wire Line
	1900 4900 1900 6000
Wire Wire Line
	1900 4900 2650 4900
Wire Wire Line
	1750 1000 3750 1000
Connection ~ 2250 1000
Connection ~ 2250 1400
Connection ~ 1750 1000
Wire Wire Line
	3750 2150 3750 2050
Wire Wire Line
	2050 1950 2050 2150
Wire Wire Line
	2050 2150 2250 2150
Wire Wire Line
	2750 2150 3750 2150
Wire Wire Line
	2750 2650 2750 2550
Wire Wire Line
	2750 2550 3550 2550
Connection ~ 2950 2550
Connection ~ 3300 2550
Wire Wire Line
	5950 1250 6250 1250
Connection ~ 5950 2150
Connection ~ 5950 2250
Wire Wire Line
	5950 2650 5950 2850
Connection ~ 5950 2750
Wire Wire Line
	5950 2350 6950 2350
Wire Wire Line
	6950 2350 6950 2250
Wire Wire Line
	5950 2750 6950 2750
Connection ~ 6100 2750
Connection ~ 6350 2750
Connection ~ 6850 2750
Connection ~ 5950 2350
Connection ~ 6100 2350
Connection ~ 6350 2350
Connection ~ 6600 2350
Connection ~ 6600 2750
Connection ~ 2950 2150
Connection ~ 3300 2150
Connection ~ 3550 2150
Connection ~ 3550 2550
Connection ~ 3750 1250
Connection ~ 6250 1250
Connection ~ 5950 1250
Connection ~ 6250 1650
Connection ~ 3750 2050
Connection ~ 3750 2150
Wire Wire Line
	5950 1950 5950 2350
Connection ~ 6950 2350
Wire Wire Line
	2600 3650 2600 3850
Connection ~ 2600 3750
Wire Wire Line
	2600 3750 2300 3750
Wire Wire Line
	2600 3950 2100 3950
Wire Wire Line
	2100 3950 2100 4800
Wire Wire Line
	1550 4800 2650 4800
Wire Wire Line
	3650 5400 1650 5400
Connection ~ 2100 4800
Connection ~ 2250 5400
Wire Wire Line
	3700 3650 3900 3650
Wire Wire Line
	3700 3750 4000 3750
Wire Wire Line
	4000 3750 4000 3850
Wire Wire Line
	4000 3850 4500 3850
Wire Wire Line
	4500 3850 4500 3650
Wire Wire Line
	4500 3650 4700 3600
Wire Wire Line
	4700 4000 4700 4100
Wire Wire Line
	4700 3600 4700 3450
Wire Wire Line
	4350 4150 4600 4150
Wire Wire Line
	4600 4150 4600 4000
Wire Wire Line
	4600 4000 4700 4000
Wire Wire Line
	3850 4150 3700 4150
Connection ~ 1650 4800
Wire Wire Line
	3200 1350 3500 1350
Wire Wire Line
	3750 1000 3750 1250
Wire Wire Line
	3500 1350 3500 1550
Wire Wire Line
	3500 1550 3750 1550
Wire Wire Line
	3750 1550 3750 1750
Wire Wire Line
	3750 1700 3600 1700
Connection ~ 3750 1700
Wire Wire Line
	3750 1850 3750 1950
Wire Wire Line
	3750 1950 3600 1950
Wire Wire Line
	2950 1700 3200 1700
Wire Wire Line
	2950 1850 2950 1700
Wire Wire Line
	3200 1950 3200 1850
Wire Wire Line
	3200 1850 2950 1850
Wire Wire Line
	1650 5200 1650 5500
Wire Wire Line
	2650 5400 2650 5200
Wire Wire Line
	3650 4800 3650 5400
Connection ~ 3650 4900
Connection ~ 3650 5100
Connection ~ 2650 5400
Connection ~ 3650 5200
Wire Wire Line
	6100 6000 6100 6100
Wire Wire Line
	6100 6100 6250 6100
Wire Wire Line
	6250 6100 6250 6200
Wire Wire Line
	6100 5850 6500 5850
Wire Wire Line
	6250 6200 6400 6200
Wire Wire Line
	6400 6200 6400 6250
Wire Wire Line
	6400 6250 6500 6250
Wire Wire Line
	6100 5750 7250 5750
Wire Wire Line
	5000 5900 4950 5900
Wire Wire Line
	4450 5850 4400 5850
Wire Wire Line
	4950 5900 4950 5850
Text HLabel 4900 6200 0    60   Input ~ 0
GPOUT
Text HLabel 4900 5600 0    60   Input ~ 0
GAUGE_SCL
Text HLabel 4900 5700 0    60   Input ~ 0
GAUGE_SDA
Wire Wire Line
	4900 5600 5000 5600
Wire Wire Line
	5000 5700 4900 5700
Wire Wire Line
	4900 6200 4900 6000
Wire Wire Line
	4900 6000 5000 6000
$Comp
L IP4220CZ6 U4
U 1 1 55094F19
P 1150 6350
F 0 "U4" H 1200 6400 60  0000 C CNN
F 1 "IP4220CZ6" H 1550 5900 60  0000 C CNN
F 2 "Anastasia:SOT457" H 1150 6350 60  0001 C CNN
F 3 "" H 1150 6350 60  0000 C CNN
	1    1150 6350
	1    0    0    -1  
$EndComp
NoConn ~ 950  6450
NoConn ~ 950  6650
Text GLabel 2250 6550 2    60   Input ~ 0
USB_VBUS
Wire Wire Line
	2250 6550 2000 6550
$Comp
L GND #PWR016
U 1 1 550950F7
P 650 6550
F 0 "#PWR016" H 650 6300 60  0001 C CNN
F 1 "GND" H 650 6400 60  0000 C CNN
F 2 "" H 650 6550 60  0000 C CNN
F 3 "" H 650 6550 60  0000 C CNN
	1    650  6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  6550 650  6550
Wire Wire Line
	2050 5000 2050 5750
Wire Wire Line
	2000 6450 2000 6000
Connection ~ 2000 6000
Wire Wire Line
	2000 6650 2150 6650
Wire Wire Line
	2150 6650 2150 5750
Connection ~ 2150 5750
Text Notes 1150 6950 0    60   ~ 0
ESD Protection\n
Text Notes 4000 4350 0    60   ~ 0
Battery Charge Current Set Resistor
Connection ~ 4400 5850
Wire Wire Line
	7400 5800 7250 5800
Wire Wire Line
	7250 5800 7250 5750
Wire Wire Line
	4450 5150 6100 5150
Connection ~ 6100 5600
Wire Wire Line
	6100 5150 6100 5600
$Comp
L TESTPAD TP16
U 1 1 550C93EA
P 7100 5750
F 0 "TP16" H 7350 5750 60  0000 C CNN
F 1 "TESTPAD" H 7150 5550 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 7350 5750 60  0001 C CNN
F 3 "" H 7350 5750 60  0000 C CNN
	1    7100 5750
	0    -1   -1   0   
$EndComp
$Comp
L TESTPAD TP13
U 1 1 550CAB5D
P 4800 3450
F 0 "TP13" H 5050 3450 60  0000 C CNN
F 1 "TESTPAD" H 4850 3250 60  0001 C CNN
F 2 "Anastasia:Test_Point_Round-SMD-Pad" H 5050 3450 60  0001 C CNN
F 3 "" H 5050 3450 60  0000 C CNN
	1    4800 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3450 4800 3450
Connection ~ 7100 5750
$EndSCHEMATC
