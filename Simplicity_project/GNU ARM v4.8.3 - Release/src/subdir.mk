################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AFE4490.c \
../src/BQ25010.c \
../src/BQ27421.c \
../src/InitDevice.c \
../src/LS013_MD.c \
../src/MPU9250.c \
../src/main.c \
../src/mdelay.c \
../src/udelay.c 

OBJS += \
./src/AFE4490.o \
./src/BQ25010.o \
./src/BQ27421.o \
./src/InitDevice.o \
./src/LS013_MD.o \
./src/MPU9250.o \
./src/main.o \
./src/mdelay.o \
./src/udelay.o 

C_DEPS += \
./src/AFE4490.d \
./src/BQ25010.d \
./src/BQ27421.d \
./src/InitDevice.d \
./src/LS013_MD.d \
./src/MPU9250.d \
./src/main.d \
./src/mdelay.d \
./src/udelay.d 


# Each subdirectory must supply rules for building sources it contributes
src/AFE4490.o: ../src/AFE4490.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/AFE4490.d" -MT"src/AFE4490.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/BQ25010.o: ../src/BQ25010.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/BQ25010.d" -MT"src/BQ25010.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/BQ27421.o: ../src/BQ27421.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/BQ27421.d" -MT"src/BQ27421.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.o: ../src/InitDevice.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/InitDevice.d" -MT"src/InitDevice.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LS013_MD.o: ../src/LS013_MD.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/LS013_MD.d" -MT"src/LS013_MD.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MPU9250.o: ../src/MPU9250.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/MPU9250.d" -MT"src/MPU9250.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mdelay.o: ../src/mdelay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/mdelay.d" -MT"src/mdelay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/udelay.o: ../src/udelay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG332F1024=1' -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/drivers" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/kits/common/bsp" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/CMSIS/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"/home/sumanguru/Documents/SimplicityStudio_v3/developer/sdks/efm32/v2/emlib/inc" -O3 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/udelay.d" -MT"src/udelay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


