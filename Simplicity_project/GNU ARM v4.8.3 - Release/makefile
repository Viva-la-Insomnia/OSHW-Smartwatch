################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/efm32gg/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Anastasia.axf

# Tool invocations
Anastasia.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "Anastasia.ld" -Xlinker --gc-sections -Xlinker -Map="Anastasia.map" --specs=nano.specs -o Anastasia.axf "./src/AFE4490.o" "./src/BQ25010.o" "./src/BQ27421.o" "./src/InitDevice.o" "./src/LS013_MD.o" "./src/MPU9250.o" "./src/main.o" "./src/mdelay.o" "./src/udelay.o" "./emlib/em_burtc.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./CMSIS/efm32gg/startup_gcc_efm32gg.o" "./CMSIS/efm32gg/system_efm32gg.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: Anastasia.hex'
	arm-none-eabi-objcopy -O ihex "Anastasia.axf" "Anastasia.hex"
	@echo ' '

	@echo 'Building bin file: Anastasia.bin'
	arm-none-eabi-objcopy -O binary "Anastasia.axf" "Anastasia.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Anastasia.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Anastasia.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
