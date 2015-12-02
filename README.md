# OSHW-Smartwatch
This is a repo for EFM32-based smartwatch project.
-- Tuomas Tinus, Jimi Järvelin

Contribute by contacting us / sending in a pull request
Read the README in the Simplicity_project/ on Simplicity IDE setup details

Our code and hardware are GNU GPL v2 / CERN OHL v1.2, licenses are in the repo. 
However, note that external libraries used in this project are distributed under different licenses, e.g. ARM CMSIS is shared under BSD

Features of the project: 
 - EFM32 low-power microcontroller
 - Lithium battery-powered with charge over USB and battery gauging
 - Bluetooth Low-Energy interface
 - Inertial Measurement Unit (Accelerometer, Gyroscope, Magnetometer)
 - Sharp low-power memory display
 - Separate I2C EEPROM memory (up to 1MB in the current iteration)(flash in the final version)
 - Planned password manager functionality with EFM32 hardware encryption

Current state of project: We have assembled a prototype and are debugging the software

We would like to thank Jared Sanson - http://jared.geek.nz/2014/jul/oshw-oled-watch - for inspiration and design ideas.
Kris Winer - https://github.com/kriswiner/MPU-9250/ - for his MPU-9250 code
