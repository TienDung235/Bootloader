################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mkl46z4.c 

C_DEPS += \
./startup/startup_mkl46z4.d 

OBJS += \
./startup/startup_mkl46z4.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\board" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\source" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\drivers" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\CMSIS" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\utilities" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\startup" -Os -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mkl46z4.d ./startup/startup_mkl46z4.o

.PHONY: clean-startup
