################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Flash.c \
../source/Mock2.c \
../source/Ring_buffe.c \
../source/UART0.c \
../source/clock.c \
../source/init.c \
../source/programme.c \
../source/srec.c 

C_DEPS += \
./source/Flash.d \
./source/Mock2.d \
./source/Ring_buffe.d \
./source/UART0.d \
./source/clock.d \
./source/init.d \
./source/programme.d \
./source/srec.d 

OBJS += \
./source/Flash.o \
./source/Mock2.o \
./source/Ring_buffe.o \
./source/UART0.o \
./source/clock.o \
./source/init.o \
./source/programme.o \
./source/srec.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\board" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\source" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\drivers" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\CMSIS" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\utilities" -I"G:\FSoft\Mock\Mock2_Kieu_Tien_Dung\1MKL46Z4_Project\startup" -Os -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Flash.d ./source/Flash.o ./source/Mock2.d ./source/Mock2.o ./source/Ring_buffe.d ./source/Ring_buffe.o ./source/UART0.d ./source/UART0.o ./source/clock.d ./source/clock.o ./source/init.d ./source/init.o ./source/programme.d ./source/programme.o ./source/srec.d ./source/srec.o

.PHONY: clean-source

