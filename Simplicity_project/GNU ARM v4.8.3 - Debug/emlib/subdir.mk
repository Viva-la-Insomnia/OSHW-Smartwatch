################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../emlib/em_burtc.c \
../emlib/em_cmu.c \
../emlib/em_emu.c \
../emlib/em_gpio.c \
../emlib/em_i2c.c \
../emlib/em_rmu.c \
../emlib/em_rtc.c \
../emlib/em_system.c \
../emlib/em_usart.c 

OBJS += \
./emlib/em_burtc.o \
./emlib/em_cmu.o \
./emlib/em_emu.o \
./emlib/em_gpio.o \
./emlib/em_i2c.o \
./emlib/em_rmu.o \
./emlib/em_rtc.o \
./emlib/em_system.o \
./emlib/em_usart.o 

C_DEPS += \
./emlib/em_burtc.d \
./emlib/em_cmu.d \
./emlib/em_emu.d \
./emlib/em_gpio.d \
./emlib/em_i2c.d \
./emlib/em_rmu.d \
./emlib/em_rtc.d \
./emlib/em_system.d \
./emlib/em_usart.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/em_burtc.o: ../emlib/em_burtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_burtc.d" -MT"emlib/em_burtc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cmu.o: ../emlib/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_cmu.d" -MT"emlib/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: ../emlib/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_emu.d" -MT"emlib/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_gpio.o: ../emlib/em_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_gpio.d" -MT"emlib/em_gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_i2c.o: ../emlib/em_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_i2c.d" -MT"emlib/em_i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rmu.o: ../emlib/em_rmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_rmu.d" -MT"emlib/em_rmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rtc.o: ../emlib/em_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_rtc.d" -MT"emlib/em_rtc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: ../emlib/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_system.d" -MT"emlib/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_usart.o: ../emlib/em_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/inc" -I"/home/sumanguru/Documents/Smartwatch/git/OSHW-Smartwatch/Simplicity_project/src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emlib/em_usart.d" -MT"emlib/em_usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


