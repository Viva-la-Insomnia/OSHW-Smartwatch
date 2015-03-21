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
Sheet 3 10
Title "uC part A"
Date "14 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EFM32GG332 U1
U 1 1 5504D189
P 7350 900
F 0 "U1" H 7450 850 60  0000 C CNN
F 1 "EFM32GG332" H 8850 850 60  0000 C CNN
F 2 "Housings_QFP:TQFP-64_10x10mm_Pitch0.5mm" H 8850 850 60  0001 C CNN
F 3 "" H 8850 850 60  0000 C CNN
	1    7350 900 
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL_SMD X2
U 1 1 5504D39D
P 4900 3200
F 0 "X2" H 4900 3290 50  0000 C CNN
F 1 "SMD_48MHZ_CRYSTAL_OSC" H 4930 3090 50  0000 L CNN
F 2 "Anastasia:2x1.6" H 4900 3200 60  0001 C CNN
F 3 "" H 4900 3200 60  0000 C CNN
	1    4900 3200
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 5504D3F7
P 4700 2850
F 0 "C18" H 4750 2950 50  0000 L CNN
F 1 "C" H 4750 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4738 2700 30  0001 C CNN
F 3 "" H 4700 2850 60  0000 C CNN
	1    4700 2850
	1    0    0    -1  
$EndComp
$Comp
L C C19
U 1 1 5504D470
P 5100 2850
F 0 "C19" H 5150 2950 50  0000 L CNN
F 1 "C" H 5150 2750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5138 2700 30  0001 C CNN
F 3 "" H 5100 2850 60  0000 C CNN
	1    5100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3200 5100 3050
Wire Wire Line
	4700 3200 4700 3050
$Comp
L GND #PWR017
U 1 1 5504D536
P 4900 2500
F 0 "#PWR017" H 4900 2250 60  0001 C CNN
F 1 "GND" H 4900 2350 60  0000 C CNN
F 2 "" H 4900 2500 60  0000 C CNN
F 3 "" H 4900 2500 60  0000 C CNN
	1    4900 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2500 5100 2500
Wire Wire Line
	5100 2500 5100 2650
Wire Wire Line
	4700 2500 4700 2650
Connection ~ 4900 2500
Wire Wire Line
	5100 3200 6700 3200
Wire Wire Line
	4700 3200 4550 3200
Wire Wire Line
	4550 3200 4550 3600
Text Notes 3500 2300 0    60   ~ 0
Choose load capacitors\naccording to EFM32GG332 datasheet
Wire Wire Line
	6700 3200 6700 2600
Wire Wire Line
	6700 2600 7150 2600
Wire Wire Line
	7150 2700 6850 2700
Wire Wire Line
	6850 2700 6850 3600
Wire Wire Line
	6850 3600 4550 3600
Text Notes 3700 3300 0    60   ~ 0
High Frequency \nCrystal Oscillator
$Comp
L C C17
U 1 1 5504D74C
P 5750 2150
F 0 "C17" H 5800 2250 50  0000 L CNN
F 1 "C" H 5800 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5788 2000 30  0001 C CNN
F 3 "" H 5750 2150 60  0000 C CNN
	1    5750 2150
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 5504D769
P 5350 2150
F 0 "C16" H 5400 2250 50  0000 L CNN
F 1 "C" H 5400 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5388 2000 30  0001 C CNN
F 3 "" H 5350 2150 60  0000 C CNN
	1    5350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1950 5750 1950
Wire Wire Line
	4900 2500 4900 1800
Wire Wire Line
	4900 1800 5550 1800
Wire Wire Line
	5550 1800 5550 1950
Connection ~ 5550 1950
Wire Wire Line
	5350 2350 5350 2950
Wire Wire Line
	5750 2500 5750 2350
Wire Wire Line
	5750 2500 6150 2500
Wire Wire Line
	6150 2500 6150 2300
Wire Wire Line
	6150 2300 7150 2300
Wire Wire Line
	7150 2400 6400 2400
Wire Wire Line
	6400 2400 6400 2950
Wire Wire Line
	6400 2950 5350 2950
Connection ~ 5350 2500
$Comp
L GND #PWR018
U 1 1 5504D88A
P 4900 3300
F 0 "#PWR018" H 4900 3050 60  0001 C CNN
F 1 "GND" H 4900 3150 60  0000 C CNN
F 2 "" H 4900 3300 60  0000 C CNN
F 3 "" H 4900 3300 60  0000 C CNN
	1    4900 3300
	1    0    0    -1  
$EndComp
Text Notes 5950 2200 0    60   ~ 0
Low Frequency\nReal-Time Clock \nCrystal Oscillator\n
$Comp
L CRYSTAL X1
U 1 1 550DBF8D
P 5650 2700
F 0 "X1" H 5650 2850 50  0000 C CNN
F 1 "32.768kHz SMD Crystal" H 5650 2550 50  0000 C CNN
F 2 "Anastasia:1.6x1.0CRYSTAL" H 5650 2700 60  0001 C CNN
F 3 "" H 5650 2700 60  0000 C CNN
	1    5650 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2700 5950 2500
Connection ~ 5950 2500
$EndSCHEMATC
