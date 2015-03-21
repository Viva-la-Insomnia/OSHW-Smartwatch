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
Sheet 7 10
Title "AFE4403"
Date "17 March 2015"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AFE4403 U7
U 1 1 5507E4DD
P 4850 2000
F 0 "U7" H 4900 2050 60  0000 C CNN
F 1 "AFE4403" H 6300 -350 60  0000 C CNN
F 2 "Anastasia:DSBGA36" H 4850 2000 60  0001 C CNN
F 3 "" H 4850 2000 60  0000 C CNN
	1    4850 2000
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL_SMD X3
U 1 1 5507E5E4
P 7200 3700
F 0 "X3" H 7200 3790 50  0000 C CNN
F 1 "CRYSTAL_8MHZ_SMD" H 7230 3590 50  0000 L CNN
F 2 "Anastasia:5x3.2_Crystal_SMD" H 7200 3700 60  0001 C CNN
F 3 "" H 7200 3700 60  0000 C CNN
	1    7200 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR032
U 1 1 5507E63E
P 7200 4300
F 0 "#PWR032" H 7200 4050 60  0001 C CNN
F 1 "GND" H 7200 4150 60  0000 C CNN
F 2 "" H 7200 4300 60  0000 C CNN
F 3 "" H 7200 4300 60  0000 C CNN
	1    7200 4300
	1    0    0    -1  
$EndComp
$Comp
L C C34
U 1 1 5507E652
P 7000 4050
F 0 "C34" H 7050 4150 50  0000 L CNN
F 1 "C" H 7050 3950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7038 3900 30  0001 C CNN
F 3 "" H 7000 4050 60  0000 C CNN
	1    7000 4050
	1    0    0    -1  
$EndComp
$Comp
L C C35
U 1 1 5507E675
P 7400 4050
F 0 "C35" H 7450 4150 50  0000 L CNN
F 1 "C" H 7450 3950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7438 3900 30  0001 C CNN
F 3 "" H 7400 4050 60  0000 C CNN
	1    7400 4050
	1    0    0    -1  
$EndComp
Text Notes 7550 4300 0    60   ~ 0
Choose load capacitors according \nto crystal's datasheet\n
$Comp
L GND #PWR033
U 1 1 5507E970
P 7050 3350
F 0 "#PWR033" H 7050 3100 60  0001 C CNN
F 1 "GND" H 7050 3200 60  0000 C CNN
F 2 "" H 7050 3350 60  0000 C CNN
F 3 "" H 7050 3350 60  0000 C CNN
	1    7050 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR034
U 1 1 5507E997
P 6900 2800
F 0 "#PWR034" H 6900 2550 60  0001 C CNN
F 1 "GND" H 6900 2650 60  0000 C CNN
F 2 "" H 6900 2800 60  0000 C CNN
F 3 "" H 6900 2800 60  0000 C CNN
	1    6900 2800
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR035
U 1 1 5507E9AF
P 8450 2550
F 0 "#PWR035" H 8450 2400 60  0001 C CNN
F 1 "+3V3" H 8450 2690 60  0000 C CNN
F 2 "" H 8450 2550 60  0000 C CNN
F 3 "" H 8450 2550 60  0000 C CNN
	1    8450 2550
	1    0    0    -1  
$EndComp
$Comp
L C C33
U 1 1 5507EA21
P 7800 3550
F 0 "C33" H 7850 3650 50  0000 L CNN
F 1 "2.2U" H 7850 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7838 3400 30  0001 C CNN
F 3 "" H 7800 3550 60  0000 C CNN
	1    7800 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR036
U 1 1 5507EA5D
P 7800 3850
F 0 "#PWR036" H 7800 3600 60  0001 C CNN
F 1 "GND" H 7800 3700 60  0000 C CNN
F 2 "" H 7800 3850 60  0000 C CNN
F 3 "" H 7800 3850 60  0000 C CNN
	1    7800 3850
	1    0    0    -1  
$EndComp
$Comp
L C C31
U 1 1 5507EAF1
P 8450 2750
F 0 "C31" H 8500 2850 50  0000 L CNN
F 1 "0.1U" H 8500 2650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8488 2600 30  0001 C CNN
F 3 "" H 8450 2750 60  0000 C CNN
	1    8450 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR037
U 1 1 5507EB22
P 8450 3000
F 0 "#PWR037" H 8450 2750 60  0001 C CNN
F 1 "GND" H 8450 2850 60  0000 C CNN
F 2 "" H 8450 3000 60  0000 C CNN
F 3 "" H 8450 3000 60  0000 C CNN
	1    8450 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR038
U 1 1 5507EC48
P 6950 2450
F 0 "#PWR038" H 6950 2200 60  0001 C CNN
F 1 "GND" H 6950 2300 60  0000 C CNN
F 2 "" H 6950 2450 60  0000 C CNN
F 3 "" H 6950 2450 60  0000 C CNN
	1    6950 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3650 6700 3550
Wire Wire Line
	6700 3550 7400 3550
Wire Wire Line
	7400 3550 7400 3850
Wire Wire Line
	6700 3750 7000 3750
Wire Wire Line
	7000 3700 7000 3850
Connection ~ 7400 3700
Connection ~ 7000 3750
Wire Wire Line
	7200 3800 7200 4300
Wire Wire Line
	7000 4250 7000 4300
Wire Wire Line
	7000 4300 7400 4300
Wire Wire Line
	7400 4300 7400 4250
Connection ~ 7200 4300
Wire Wire Line
	6700 3450 6900 3450
Wire Wire Line
	6900 3450 6900 3350
Wire Wire Line
	6900 3350 7050 3350
Wire Wire Line
	6700 2900 6700 2800
Wire Wire Line
	6650 2800 6900 2800
Connection ~ 6700 2800
Wire Wire Line
	6700 3000 7300 3000
Wire Wire Line
	7300 3000 7300 2550
Wire Wire Line
	7800 3850 7800 3750
Wire Wire Line
	7600 3350 7800 3350
Wire Wire Line
	6700 3250 7300 3250
Wire Wire Line
	7300 3250 7300 3450
Wire Wire Line
	7300 3450 7600 3450
Wire Wire Line
	7600 3450 7600 3350
Wire Wire Line
	8450 3000 8450 2950
Wire Wire Line
	7300 2550 8450 2550
Wire Wire Line
	6950 2450 6700 2450
Wire Wire Line
	6700 2200 6950 2200
Wire Wire Line
	6950 2200 6950 2450
Wire Wire Line
	6700 2650 6700 2550
Wire Wire Line
	7100 2650 6700 2650
Wire Wire Line
	7100 1850 7100 2650
$Comp
L GND #PWR039
U 1 1 5507EE1C
P 7800 2300
F 0 "#PWR039" H 7800 2050 60  0001 C CNN
F 1 "GND" H 7800 2150 60  0000 C CNN
F 2 "" H 7800 2300 60  0000 C CNN
F 3 "" H 7800 2300 60  0000 C CNN
	1    7800 2300
	1    0    0    -1  
$EndComp
$Comp
L C C30
U 1 1 5507EE30
P 7800 2050
F 0 "C30" H 7850 2150 50  0000 L CNN
F 1 "0.1U" H 7850 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7838 1900 30  0001 C CNN
F 3 "" H 7800 2050 60  0000 C CNN
	1    7800 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2250 7800 2300
Wire Wire Line
	7100 1850 8350 1850
$Comp
L C C32
U 1 1 5507F067
P 8050 3000
F 0 "C32" H 8100 3100 50  0000 L CNN
F 1 "0.1U" H 8100 2900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8088 2850 30  0001 C CNN
F 3 "" H 8050 3000 60  0000 C CNN
	1    8050 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR040
U 1 1 5507F092
P 8050 3250
F 0 "#PWR040" H 8050 3000 60  0001 C CNN
F 1 "GND" H 8050 3100 60  0000 C CNN
F 2 "" H 8050 3250 60  0000 C CNN
F 3 "" H 8050 3250 60  0000 C CNN
	1    8050 3250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR041
U 1 1 5507F0A6
P 8050 2750
F 0 "#PWR041" H 8050 2600 60  0001 C CNN
F 1 "+3V3" H 8050 2890 60  0000 C CNN
F 2 "" H 8050 2750 60  0000 C CNN
F 3 "" H 8050 2750 60  0000 C CNN
	1    8050 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 3250 8050 3200
Wire Wire Line
	8050 2800 8050 2750
Wire Wire Line
	6700 3150 7700 3150
Wire Wire Line
	7700 3150 7700 2800
Wire Wire Line
	7700 2800 8050 2800
$Comp
L C C26
U 1 1 5507F407
P 6850 1450
F 0 "C26" H 6900 1550 50  0000 L CNN
F 1 "1U" H 6900 1350 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6888 1300 30  0001 C CNN
F 3 "" H 6850 1450 60  0000 C CNN
	1    6850 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR042
U 1 1 5507F42E
P 6850 1750
F 0 "#PWR042" H 6850 1500 60  0001 C CNN
F 1 "GND" H 6850 1600 60  0000 C CNN
F 2 "" H 6850 1750 60  0000 C CNN
F 3 "" H 6850 1750 60  0000 C CNN
	1    6850 1750
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR043
U 1 1 5507F442
P 6850 1150
F 0 "#PWR043" H 6850 1000 60  0001 C CNN
F 1 "+3V3" H 6850 1290 60  0000 C CNN
F 2 "" H 6850 1150 60  0000 C CNN
F 3 "" H 6850 1150 60  0000 C CNN
	1    6850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1750 6850 1650
Wire Wire Line
	6850 1250 6850 1150
Wire Wire Line
	6700 2300 6850 2300
Wire Wire Line
	6850 2300 6850 2050
Wire Wire Line
	6850 2050 6650 2050
Wire Wire Line
	6650 2050 6650 1250
Wire Wire Line
	6650 1250 6850 1250
$Comp
L GND #PWR044
U 1 1 5507FE0D
P 3700 2300
F 0 "#PWR044" H 3700 2050 60  0001 C CNN
F 1 "GND" H 3700 2150 60  0000 C CNN
F 2 "" H 3700 2300 60  0000 C CNN
F 3 "" H 3700 2300 60  0000 C CNN
	1    3700 2300
	1    0    0    -1  
$EndComp
$Comp
L C C27
U 1 1 5507FE21
P 3700 2050
F 0 "C27" H 3750 2150 50  0000 L CNN
F 1 "2.2U" H 3750 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3738 1900 30  0001 C CNN
F 3 "" H 3700 2050 60  0000 C CNN
	1    3700 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2300 3700 2250
Wire Wire Line
	3950 2400 4650 2400
Wire Wire Line
	3950 1850 3950 2400
Wire Wire Line
	3950 1850 3700 1850
NoConn ~ 4650 4100
$Comp
L LED D2
U 1 1 550800F9
P 3350 4300
F 0 "D2" H 3350 4400 50  0000 C CNN
F 1 "RED_LED" H 3350 4200 50  0000 C CNN
F 2 "" H 3350 4300 60  0001 C CNN
F 3 "" H 3350 4300 60  0000 C CNN
	1    3350 4300
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5508011C
P 3350 4650
F 0 "D3" H 3350 4750 50  0000 C CNN
F 1 "IR_LED" H 3350 4550 50  0000 C CNN
F 2 "" H 3350 4650 60  0001 C CNN
F 3 "" H 3350 4650 60  0000 C CNN
	1    3350 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 4300 3550 4650
Wire Wire Line
	3150 4300 3150 4650
Wire Wire Line
	3150 4450 2950 4450
Wire Wire Line
	2950 4450 2950 4150
Wire Wire Line
	2950 4150 3700 4150
Wire Wire Line
	3700 4150 3700 4350
Connection ~ 3150 4450
Connection ~ 3550 4450
$Comp
L DIODE D1
U 1 1 5507F689
P 2350 3150
F 0 "D1" H 2350 3250 50  0000 C CNN
F 1 "PHOTODIODE" H 2350 3050 50  0000 C CNN
F 2 "" H 2350 3150 60  0001 C CNN
F 3 "" H 2350 3150 60  0000 C CNN
	1    2350 3150
	0    -1   1    0   
$EndComp
Wire Wire Line
	2350 3350 2350 3450
Wire Wire Line
	2550 3300 2550 2950
Wire Wire Line
	2550 2950 2350 2950
Wire Wire Line
	4650 3950 4500 3950
Wire Wire Line
	4500 3950 4500 4450
Wire Wire Line
	4300 4350 4300 3850
Wire Wire Line
	4300 3850 4650 3850
Wire Notes Line
	2700 3800 2700 5100
Wire Notes Line
	2700 3800 4750 3800
Wire Notes Line
	4750 3800 4750 5100
Wire Notes Line
	4750 5100 2700 5100
Text Notes 4250 5050 0    60   ~ 0
TRANSMIT\n
Wire Wire Line
	4650 3400 3300 3400
Wire Wire Line
	3300 3400 3300 3300
Wire Wire Line
	3200 3400 3200 3500
Wire Wire Line
	3200 3500 4650 3500
Wire Wire Line
	2100 3600 2100 2850
Wire Wire Line
	2100 2850 2800 2850
Wire Notes Line
	2000 2800 3250 2800
Wire Notes Line
	3250 2800 3250 3750
Wire Notes Line
	3250 3750 2000 3750
Wire Notes Line
	2000 3750 2000 2800
Text Notes 2850 3750 0    60   ~ 0
RECEIVE\n
Text Notes 2550 2950 0    60   ~ 0
VCM Shielding\n
Text HLabel 4250 2950 0    60   Input ~ 0
SCLK
Text HLabel 4250 3050 0    60   Input ~ 0
MOSI
Text HLabel 4250 3150 0    60   Input ~ 0
MISO
Text HLabel 4250 3250 0    60   Input ~ 0
SPIEN
Text HLabel 2750 2600 0    60   Input ~ 0
RESET
Text HLabel 4500 2150 0    60   Input ~ 0
ADC_RDY
Text HLabel 4500 2250 0    60   Input ~ 0
AFE_PDN
Text HLabel 4350 2650 0    60   Input ~ 0
DIAG_END
NoConn ~ 4650 2550
Wire Wire Line
	4500 2250 4650 2250
Wire Wire Line
	4500 2150 4650 2150
Wire Wire Line
	4350 2650 4650 2650
Wire Wire Line
	4250 2950 4650 2950
Wire Wire Line
	4250 3050 4650 3050
Wire Wire Line
	4650 3150 4250 3150
Wire Wire Line
	4250 3250 4650 3250
$Comp
L R R7
U 1 1 55080A62
P 3000 2350
F 0 "R7" V 3080 2350 50  0000 C CNN
F 1 "10K" V 3007 2351 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2930 2350 30  0001 C CNN
F 3 "" H 3000 2350 30  0000 C CNN
	1    3000 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2600 3450 2600
Wire Wire Line
	3450 2600 3450 2800
Wire Wire Line
	3450 2800 4650 2800
Connection ~ 3000 2600
$Comp
L +3V3 #PWR045
U 1 1 55080B5C
P 3000 1950
F 0 "#PWR045" H 3000 1800 60  0001 C CNN
F 1 "+3V3" H 3000 2090 60  0000 C CNN
F 2 "" H 3000 1950 60  0000 C CNN
F 3 "" H 3000 1950 60  0000 C CNN
	1    3000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2100 3000 1950
$Comp
L C C28
U 1 1 550D75B9
P 7250 2050
F 0 "C28" H 7300 2150 50  0000 L CNN
F 1 "10N" H 7300 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7288 1900 30  0001 C CNN
F 3 "" H 7250 2050 60  0000 C CNN
	1    7250 2050
	1    0    0    -1  
$EndComp
Connection ~ 7800 2250
Connection ~ 7800 1850
$Comp
L FILTER FB1
U 1 1 550D77C7
P 8700 1850
F 0 "FB1" H 8700 2000 50  0000 C CNN
F 1 "FILTER" H 8700 1750 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 8700 1850 60  0001 C CNN
F 3 "" H 8700 1850 60  0000 C CNN
	1    8700 1850
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR046
U 1 1 550D77E4
P 9200 1700
F 0 "#PWR046" H 9200 1550 60  0001 C CNN
F 1 "+3V3" H 9200 1840 60  0000 C CNN
F 2 "" H 9200 1700 60  0000 C CNN
F 3 "" H 9200 1700 60  0000 C CNN
	1    9200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 1850 9200 1850
Wire Wire Line
	9200 1850 9200 1700
Connection ~ 8150 1850
Connection ~ 7500 2250
$Comp
L C C29
U 1 1 550D75A0
P 7500 2050
F 0 "C29" H 7550 2150 50  0000 L CNN
F 1 "10N" H 7550 1950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7538 1900 30  0001 C CNN
F 3 "" H 7500 2050 60  0000 C CNN
	1    7500 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2250 7800 2250
Wire Wire Line
	3550 4450 3700 4450
$Comp
L TESTPAD TP25
U 1 1 550E81F4
P 3700 4350
F 0 "TP25" H 3950 4350 60  0000 C CNN
F 1 "TESTPAD" H 3750 4150 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3950 4350 60  0001 C CNN
F 3 "" H 3950 4350 60  0000 C CNN
	1    3700 4350
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP27
U 1 1 550E821D
P 3700 4450
F 0 "TP27" H 3950 4450 60  0000 C CNN
F 1 "TESTPAD" H 3750 4250 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3950 4450 60  0001 C CNN
F 3 "" H 3950 4450 60  0000 C CNN
	1    3700 4450
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP26
U 1 1 550E8236
P 4300 4350
F 0 "TP26" H 4550 4350 60  0000 C CNN
F 1 "TESTPAD" H 4350 4150 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 4550 4350 60  0001 C CNN
F 3 "" H 4550 4350 60  0000 C CNN
	1    4300 4350
	0    1    1    0   
$EndComp
$Comp
L TESTPAD TP28
U 1 1 550E8251
P 4500 4450
F 0 "TP28" H 4750 4450 60  0000 C CNN
F 1 "TESTPAD" H 4550 4250 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 4750 4450 60  0001 C CNN
F 3 "" H 4750 4450 60  0000 C CNN
	1    4500 4450
	0    1    1    0   
$EndComp
Connection ~ 4500 4450
Connection ~ 4300 4350
Connection ~ 3700 4350
Connection ~ 3700 4450
Wire Wire Line
	4650 3600 3200 3600
$Comp
L TESTPAD TP20
U 1 1 550E8502
P 3300 3300
F 0 "TP20" H 3550 3300 60  0000 C CNN
F 1 "TESTPAD" H 3350 3100 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3550 3300 60  0001 C CNN
F 3 "" H 3550 3300 60  0000 C CNN
	1    3300 3300
	-1   0    0    1   
$EndComp
$Comp
L TESTPAD TP21
U 1 1 550E8529
P 3200 3400
F 0 "TP21" H 3450 3400 60  0000 C CNN
F 1 "TESTPAD" H 3250 3200 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3450 3400 60  0001 C CNN
F 3 "" H 3450 3400 60  0000 C CNN
	1    3200 3400
	-1   0    0    1   
$EndComp
$Comp
L TESTPAD TP24
U 1 1 550E8546
P 3200 3600
F 0 "TP24" H 3450 3600 60  0000 C CNN
F 1 "TESTPAD" H 3250 3400 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 3450 3600 60  0001 C CNN
F 3 "" H 3450 3600 60  0000 C CNN
	1    3200 3600
	-1   0    0    1   
$EndComp
$Comp
L TESTPAD TP23
U 1 1 550E8563
P 2100 3600
F 0 "TP23" H 2350 3600 60  0000 C CNN
F 1 "TESTPAD" H 2150 3400 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2350 3600 60  0001 C CNN
F 3 "" H 2350 3600 60  0000 C CNN
	1    2100 3600
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP22
U 1 1 550E8584
P 2350 3450
F 0 "TP22" H 2600 3450 60  0000 C CNN
F 1 "TESTPAD" H 2400 3250 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2600 3450 60  0001 C CNN
F 3 "" H 2600 3450 60  0000 C CNN
	1    2350 3450
	1    0    0    -1  
$EndComp
$Comp
L TESTPAD TP19
U 1 1 550E859D
P 2600 3300
F 0 "TP19" H 2850 3300 60  0000 C CNN
F 1 "TESTPAD" H 2650 3100 60  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 2850 3300 60  0001 C CNN
F 3 "" H 2850 3300 60  0000 C CNN
	1    2600 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3300 2550 3300
$EndSCHEMATC
