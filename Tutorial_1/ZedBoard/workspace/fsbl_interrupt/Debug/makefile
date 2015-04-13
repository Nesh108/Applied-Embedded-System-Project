################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
fsbl_interrupt.elf.size \


# All Target
all: fsbl_interrupt.elf secondary-outputs

# Tool invocations
fsbl_interrupt.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM gcc linker'
	arm-xilinx-eabi-gcc -L"/afs/tu-berlin.de/home/a/avaccari/irb-ubuntu/AEP-Tutorial/Tutorial_1/ZedBoard/workspace/fsbl_interrupt/src" -Wl,-T -Wl,../src/lscript.ld -L../../Interrupt_Handler_bsp/ps7_cortexa9_0/lib -o "fsbl_interrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

fsbl_interrupt.elf.size: fsbl_interrupt.elf
	@echo 'Invoking: ARM Print Size'
	arm-xilinx-eabi-size fsbl_interrupt.elf  |tee "fsbl_interrupt.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(S_UPPER_DEPS) fsbl_interrupt.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
