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
Sheet 6 6
Title "nRF8001"
Date "15 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L nRF8001 U4
U 1 1 550556FB
P 5300 1200
F 0 "U4" H 5350 1250 60  0000 C CNN
F 1 "nRF8001" H 5900 -950 60  0000 C CNN
F 2 "" H 5300 1200 60  0000 C CNN
F 3 "" H 5300 1200 60  0000 C CNN
	1    5300 1200
	1    0    0    -1  
$EndComp
$Comp
L C C25
U 1 1 550557D1
P 4050 1500
F 0 "C25" H 4100 1600 50  0000 L CNN
F 1 "4.7U" H 4100 1400 50  0000 L CNN
F 2 "" H 4088 1350 30  0000 C CNN
F 3 "" H 4050 1500 60  0000 C CNN
	1    4050 1500
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR027
U 1 1 550557EE
P 4050 1150
F 0 "#PWR027" H 4050 1000 60  0001 C CNN
F 1 "+3V3" H 4050 1290 60  0000 C CNN
F 2 "" H 4050 1150 60  0000 C CNN
F 3 "" H 4050 1150 60  0000 C CNN
	1    4050 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 55055802
P 4050 1850
F 0 "#PWR028" H 4050 1600 60  0001 C CNN
F 1 "GND" H 4050 1700 60  0000 C CNN
F 2 "" H 4050 1850 60  0000 C CNN
F 3 "" H 4050 1850 60  0000 C CNN
	1    4050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1300 4050 1150
Wire Wire Line
	4050 1850 4050 1700
Wire Wire Line
	4050 1300 5150 1300
$Comp
L C C30
U 1 1 5505582E
P 4200 2950
F 0 "C30" H 4250 3050 50  0000 L CNN
F 1 "100N" H 4250 2850 50  0000 L CNN
F 2 "" H 4238 2800 30  0000 C CNN
F 3 "" H 4200 2950 60  0000 C CNN
	1    4200 2950
	1    0    0    -1  
$EndComp
$Comp
L C C32
U 1 1 5505584F
P 4550 3050
F 0 "C32" H 4600 3150 50  0000 L CNN
F 1 "33N" H 4600 2950 50  0000 L CNN
F 2 "" H 4588 2900 30  0000 C CNN
F 3 "" H 4550 3050 60  0000 C CNN
	1    4550 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 5505586E
P 4400 3400
F 0 "#PWR029" H 4400 3150 60  0001 C CNN
F 1 "GND" H 4400 3250 60  0000 C CNN
F 2 "" H 4400 3400 60  0000 C CNN
F 3 "" H 4400 3400 60  0000 C CNN
	1    4400 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2850 5150 2850
Wire Wire Line
	5150 2750 4200 2750
Wire Wire Line
	4200 3150 4200 3400
Wire Wire Line
	4200 3400 4550 3400
Wire Wire Line
	4550 3400 4550 3250
Connection ~ 4400 3400
$Comp
L C C26
U 1 1 55055963
P 4400 1750
F 0 "C26" H 4450 1850 50  0000 L CNN
F 1 "100N" H 4450 1650 50  0000 L CNN
F 2 "" H 4438 1600 30  0000 C CNN
F 3 "" H 4400 1750 60  0000 C CNN
	1    4400 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 5505597E
P 4400 2050
F 0 "#PWR030" H 4400 1800 60  0001 C CNN
F 1 "GND" H 4400 1900 60  0000 C CNN
F 2 "" H 4400 2050 60  0000 C CNN
F 3 "" H 4400 2050 60  0000 C CNN
	1    4400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2050 4400 1950
$Comp
L C C27
U 1 1 550559C2
P 4800 1850
F 0 "C27" H 4850 1950 50  0000 L CNN
F 1 "1N" H 4850 1750 50  0000 L CNN
F 2 "" H 4838 1700 30  0000 C CNN
F 3 "" H 4800 1850 60  0000 C CNN
	1    4800 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 550559EB
P 4800 2150
F 0 "#PWR031" H 4800 1900 60  0001 C CNN
F 1 "GND" H 4800 2000 60  0000 C CNN
F 2 "" H 4800 2150 60  0000 C CNN
F 3 "" H 4800 2150 60  0000 C CNN
	1    4800 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2150 4800 2050
Wire Wire Line
	5150 1550 5150 1750
Connection ~ 5150 1650
Wire Wire Line
	5150 1650 4800 1650
$Comp
L +3V3 #PWR032
U 1 1 55055A52
P 4800 1600
F 0 "#PWR032" H 4800 1450 60  0001 C CNN
F 1 "+3V3" H 4800 1740 60  0000 C CNN
F 2 "" H 4800 1600 60  0000 C CNN
F 3 "" H 4800 1600 60  0000 C CNN
	1    4800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1650 4800 1600
$Comp
L +3V3 #PWR033
U 1 1 55055A97
P 4400 1500
F 0 "#PWR033" H 4400 1350 60  0001 C CNN
F 1 "+3V3" H 4400 1640 60  0000 C CNN
F 2 "" H 4400 1500 60  0000 C CNN
F 3 "" H 4400 1500 60  0000 C CNN
	1    4400 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1550 4400 1500
Wire Wire Line
	5150 1400 4550 1400
Wire Wire Line
	4550 1400 4550 1550
Wire Wire Line
	4550 1550 4400 1550
$Comp
L GND #PWR034
U 1 1 55055AEC
P 4950 2250
F 0 "#PWR034" H 4950 2000 60  0001 C CNN
F 1 "GND" H 4950 2100 60  0000 C CNN
F 2 "" H 4950 2250 60  0000 C CNN
F 3 "" H 4950 2250 60  0000 C CNN
	1    4950 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2250 4950 2250
Wire Wire Line
	5150 1950 5150 2450
Connection ~ 5150 2350
Connection ~ 5150 2250
Connection ~ 5150 2150
Connection ~ 5150 2050
Connection ~ 5150 2450
$Comp
L R R5
U 1 1 5506853F
P 6650 1450
F 0 "R5" V 6730 1450 50  0000 C CNN
F 1 "22K" V 6657 1451 50  0000 C CNN
F 2 "" V 6580 1450 30  0000 C CNN
F 3 "" H 6650 1450 30  0000 C CNN
	1    6650 1450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR035
U 1 1 55068568
P 7100 1450
F 0 "#PWR035" H 7100 1200 60  0001 C CNN
F 1 "GND" H 7100 1300 60  0000 C CNN
F 2 "" H 7100 1450 60  0000 C CNN
F 3 "" H 7100 1450 60  0000 C CNN
	1    7100 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 1450 6400 1450
Wire Wire Line
	6900 1450 7100 1450
$Comp
L INDUCTOR L5
U 1 1 55068623
P 7400 3100
F 0 "L5" V 7350 3100 50  0000 C CNN
F 1 "8.2NH" V 7500 3100 50  0000 C CNN
F 2 "" H 7400 3100 60  0000 C CNN
F 3 "" H 7400 3100 60  0000 C CNN
	1    7400 3100
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L4
U 1 1 55068662
P 7900 2800
F 0 "L4" V 7850 2800 50  0000 C CNN
F 1 "5.6NH" V 8000 2800 50  0000 C CNN
F 2 "" H 7900 2800 60  0000 C CNN
F 3 "" H 7900 2800 60  0000 C CNN
	1    7900 2800
	0    1    1    0   
$EndComp
$Comp
L INDUCTOR L6
U 1 1 55068691
P 7900 3400
F 0 "L6" V 7850 3400 50  0000 C CNN
F 1 "3.9NH" V 8000 3400 50  0000 C CNN
F 2 "" H 7900 3400 60  0000 C CNN
F 3 "" H 7900 3400 60  0000 C CNN
	1    7900 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 2800 7600 2800
Wire Wire Line
	6950 3400 7600 3400
Wire Wire Line
	6250 3050 6950 3050
Wire Wire Line
	6950 3050 6950 2800
Connection ~ 7400 2800
Wire Wire Line
	6250 3150 6950 3150
Wire Wire Line
	6950 3150 6950 3400
Connection ~ 7400 3400
Wire Wire Line
	8200 2800 9950 2800
Wire Wire Line
	9950 2800 9950 3950
Wire Wire Line
	9950 3950 5150 3950
Wire Wire Line
	5150 3950 5150 3000
$Comp
L C C35
U 1 1 55068A29
P 9250 4150
F 0 "C35" H 9300 4250 50  0000 L CNN
F 1 "2.2N" H 9300 4050 50  0000 L CNN
F 2 "" H 9288 4000 30  0000 C CNN
F 3 "" H 9250 4150 60  0000 C CNN
	1    9250 4150
	1    0    0    -1  
$EndComp
$Comp
L C C36
U 1 1 55068B3E
P 9700 4150
F 0 "C36" H 9750 4250 50  0000 L CNN
F 1 "N/C" H 9750 4050 50  0000 L CNN
F 2 "" H 9738 4000 30  0000 C CNN
F 3 "" H 9700 4150 60  0000 C CNN
	1    9700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 4350 9250 4350
$Comp
L GND #PWR036
U 1 1 55068D17
P 9500 4350
F 0 "#PWR036" H 9500 4100 60  0001 C CNN
F 1 "GND" H 9500 4200 60  0000 C CNN
F 2 "" H 9500 4350 60  0000 C CNN
F 3 "" H 9500 4350 60  0000 C CNN
	1    9500 4350
	1    0    0    -1  
$EndComp
$Comp
L C C33
U 1 1 55068D43
P 8500 3400
F 0 "C33" H 8550 3500 50  0000 L CNN
F 1 "1.8N" H 8550 3300 50  0000 L CNN
F 2 "" H 8538 3250 30  0000 C CNN
F 3 "" H 8500 3400 60  0000 C CNN
	1    8500 3400
	0    -1   -1   0   
$EndComp
$Comp
L C C34
U 1 1 55068D64
P 8800 3600
F 0 "C34" H 8850 3700 50  0000 L CNN
F 1 "1.2N" H 8850 3500 50  0000 L CNN
F 2 "" H 8838 3450 30  0000 C CNN
F 3 "" H 8800 3600 60  0000 C CNN
	1    8800 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR037
U 1 1 55068D89
P 9000 3750
F 0 "#PWR037" H 9000 3500 60  0001 C CNN
F 1 "GND" H 9000 3600 60  0000 C CNN
F 2 "" H 9000 3750 60  0000 C CNN
F 3 "" H 9000 3750 60  0000 C CNN
	1    9000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3800 8900 3800
Wire Wire Line
	8900 3800 8900 3750
Wire Wire Line
	8900 3750 9000 3750
Wire Wire Line
	8200 3400 8300 3400
Wire Wire Line
	8700 3400 9400 3400
Connection ~ 8800 3400
Wire Notes Line
	6700 4550 10400 4550
Text Notes 7100 4400 0    60   ~ 0
DIFFERENTIAL ANTENNA\nPAY ATTENTION TO\nPCB ROUTING (EMF!!!)\n
Text HLabel 6450 1300 2    60   Input ~ 0
RESET_RADIO
Wire Wire Line
	6250 1300 6450 1300
Wire Wire Line
	5150 2600 3850 2600
$Comp
L INDUCTOR L3
U 1 1 550699FE
P 3550 2600
F 0 "L3" V 3500 2600 50  0000 C CNN
F 1 "10UH" V 3650 2600 50  0000 C CNN
F 2 "" H 3550 2600 60  0000 C CNN
F 3 "" H 3550 2600 60  0000 C CNN
	1    3550 2600
	0    1    1    0   
$EndComp
$Comp
L INDUCTOR L2
U 1 1 55069AC1
P 2800 2600
F 0 "L2" V 2750 2600 50  0000 C CNN
F 1 "15NH" V 2900 2600 50  0000 C CNN
F 2 "" H 2800 2600 60  0000 C CNN
F 3 "" H 2800 2600 60  0000 C CNN
	1    2800 2600
	0    1    1    0   
$EndComp
Connection ~ 3850 2600
Wire Wire Line
	3100 2600 3250 2600
Wire Wire Line
	2500 2450 2500 2850
$Comp
L C C31
U 1 1 55069B78
P 2500 3050
F 0 "C31" H 2550 3150 50  0000 L CNN
F 1 "1U" H 2550 2950 50  0000 L CNN
F 2 "" H 2538 2900 30  0000 C CNN
F 3 "" H 2500 3050 60  0000 C CNN
	1    2500 3050
	1    0    0    -1  
$EndComp
Connection ~ 2500 2600
$Comp
L +3V3 #PWR038
U 1 1 55069C09
P 2500 2450
F 0 "#PWR038" H 2500 2300 60  0001 C CNN
F 1 "+3V3" H 2500 2590 60  0000 C CNN
F 2 "" H 2500 2450 60  0000 C CNN
F 3 "" H 2500 2450 60  0000 C CNN
	1    2500 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR039
U 1 1 55069C1D
P 2500 3350
F 0 "#PWR039" H 2500 3100 60  0001 C CNN
F 1 "GND" H 2500 3200 60  0000 C CNN
F 2 "" H 2500 3350 60  0000 C CNN
F 3 "" H 2500 3350 60  0000 C CNN
	1    2500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 3350 2500 3250
Text Notes 2650 2450 0    60   ~ 0
For the internal DC-DC\nLowers power consumption\nCan be avoided in the final design
$Comp
L CRYSTAL_SMD X3
U 1 1 5506A365
P 8100 1650
F 0 "X3" H 8100 1740 50  0000 C CNN
F 1 "CRYSTAL_SMD_16MHZ" H 8130 1540 50  0000 L CNN
F 2 "" H 8100 1650 60  0000 C CNN
F 3 "" H 8100 1650 60  0000 C CNN
	1    8100 1650
	1    0    0    -1  
$EndComp
$Comp
L C C28
U 1 1 5506A386
P 7900 2050
F 0 "C28" H 7950 2150 50  0000 L CNN
F 1 "12P" H 7950 1950 50  0000 L CNN
F 2 "" H 7938 1900 30  0000 C CNN
F 3 "" H 7900 2050 60  0000 C CNN
	1    7900 2050
	1    0    0    -1  
$EndComp
$Comp
L C C29
U 1 1 5506A3A3
P 8300 2050
F 0 "C29" H 8350 2150 50  0000 L CNN
F 1 "12P" H 8350 1950 50  0000 L CNN
F 2 "" H 8338 1900 30  0000 C CNN
F 3 "" H 8300 2050 60  0000 C CNN
	1    8300 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR040
U 1 1 5506A4BA
P 8100 2300
F 0 "#PWR040" H 8100 2050 60  0001 C CNN
F 1 "GND" H 8100 2150 60  0000 C CNN
F 2 "" H 8100 2300 60  0000 C CNN
F 3 "" H 8100 2300 60  0000 C CNN
	1    8100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2250 7900 2300
Wire Wire Line
	7900 2300 8300 2300
Wire Wire Line
	8300 2300 8300 2250
Connection ~ 8100 2300
Wire Wire Line
	8300 1400 8300 1850
Wire Wire Line
	7900 1850 7900 1650
Wire Wire Line
	7900 1650 7450 1650
Wire Wire Line
	7450 1650 7450 1950
Wire Wire Line
	7450 1950 6250 1950
Wire Wire Line
	8300 1400 7350 1400
Wire Wire Line
	7350 1400 7350 1850
Wire Wire Line
	7350 1850 6250 1850
Connection ~ 8300 1650
Wire Notes Line
	10400 4550 10400 2700
Wire Notes Line
	10400 2700 6700 2700
Wire Notes Line
	6700 2700 6700 4550
$Comp
L TESTPAD TP1
U 1 1 5506B344
P 6350 2800
F 0 "TP1" H 6600 2800 60  0000 C CNN
F 1 "TESTPAD" H 6400 2600 60  0001 C CNN
F 2 "" H 6600 2800 60  0000 C CNN
F 3 "" H 6600 2800 60  0000 C CNN
	1    6350 2800
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP2
U 1 1 5506B35D
P 6350 2900
F 0 "TP2" H 6600 2900 60  0000 C CNN
F 1 "TESTPAD" H 6400 2700 60  0001 C CNN
F 2 "" H 6600 2900 60  0000 C CNN
F 3 "" H 6600 2900 60  0000 C CNN
	1    6350 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2800 6250 2800
Wire Wire Line
	6250 2900 6350 2900
Text HLabel 6450 2100 2    60   Input ~ 0
ACTIVE
Text HLabel 6450 2200 2    60   Input ~ 0
RDYN
Text HLabel 6450 2300 2    60   Input ~ 0
REQN
Text HLabel 6450 2450 2    60   Input ~ 0
MOSI
Text HLabel 6450 2550 2    60   Input ~ 0
MISO
Text HLabel 6450 2650 2    60   Input ~ 0
SCK
Wire Wire Line
	6450 2100 6250 2100
Wire Wire Line
	6250 2200 6450 2200
Wire Wire Line
	6450 2300 6250 2300
Wire Wire Line
	6250 2450 6450 2450
Wire Wire Line
	6450 2550 6250 2550
Wire Wire Line
	6250 2650 6450 2650
$EndSCHEMATC
