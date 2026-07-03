################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVERS/Src/STM32_GPIO.c \
../DRIVERS/Src/STM32_I2C.c \
../DRIVERS/Src/STM32_UART.c 

OBJS += \
./DRIVERS/Src/STM32_GPIO.o \
./DRIVERS/Src/STM32_I2C.o \
./DRIVERS/Src/STM32_UART.o 

C_DEPS += \
./DRIVERS/Src/STM32_GPIO.d \
./DRIVERS/Src/STM32_I2C.d \
./DRIVERS/Src/STM32_UART.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVERS/Src/%.o DRIVERS/Src/%.su DRIVERS/Src/%.cyclo: ../DRIVERS/Src/%.c DRIVERS/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/I2C_PGM/I2C_TEMP/DRIVERS/Src" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/I2C_PGM/I2C_TEMP/DRIVERS/Inc" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/I2C_PGM/I2C_TEMP/DRIVERS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DRIVERS-2f-Src

clean-DRIVERS-2f-Src:
	-$(RM) ./DRIVERS/Src/STM32_GPIO.cyclo ./DRIVERS/Src/STM32_GPIO.d ./DRIVERS/Src/STM32_GPIO.o ./DRIVERS/Src/STM32_GPIO.su ./DRIVERS/Src/STM32_I2C.cyclo ./DRIVERS/Src/STM32_I2C.d ./DRIVERS/Src/STM32_I2C.o ./DRIVERS/Src/STM32_I2C.su ./DRIVERS/Src/STM32_UART.cyclo ./DRIVERS/Src/STM32_UART.d ./DRIVERS/Src/STM32_UART.o ./DRIVERS/Src/STM32_UART.su

.PHONY: clean-DRIVERS-2f-Src

