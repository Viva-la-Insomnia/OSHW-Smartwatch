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
Sheet 1 4
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
S 1100 850  1250 1100
U 55046F13
F0 "Power" 60
F1 "Sheet1.sch" 60
$EndSheet
Text Notes 1350 1500 0    60   ~ 0
Battery charger\nBuck regulator\nUSB connector\nuC power (part D)
$Sheet
S 2950 850  1300 1100
U 5504D17E
F0 "uC part A" 60
F1 "Sheet2.sch" 60
$EndSheet
Text Notes 3000 1300 0    60   ~ 0
uC part A (ports A and B)\nCrystal oscillators\n
$Sheet
S 2950 2300 1300 1100
U 5504DA44
F0 "IMU" 60
F1 "Sheet3.sch" 60
F2 "IMU_SDA" I L 2950 2550 60 
F3 "IMU_SCL" I L 2950 2700 60 
F4 "IMU_INT" I L 2950 2900 60 
$EndSheet
$EndSCHEMATC
