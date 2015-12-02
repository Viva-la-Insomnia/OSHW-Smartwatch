################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/efm32gg/system_efm32gg.c 

S_SRCS += \
../CMSIS/efm32gg/startup_gcc_efm32gg.s 

OBJS += \
./CMSIS/efm32gg/startup_gcc_efm32gg.o \
./CMSIS/efm32gg/system_efm32gg.o 

C_DEPS += \
./CMSIS/efm32gg/system_efm32gg.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/efm32gg/%.o: ../CMSIS/efm32gg/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -c -x assembler-with-cpp -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" '-DEFM32GG332F1024=1' -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/efm32gg/system_efm32gg.o: ../CMSIS/efm32gg/system_efm32gg.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"CMSIS/efm32gg/system_efm32gg.d" -MT"CMSIS/efm32gg/system_efm32gg.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


