################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.c \
../DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.c 

OBJS += \
./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.o \
./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.o 

C_DEPS += \
./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.d \
./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.o: ../DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.c DRIVER\ _DEVELOP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Src" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Inc" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"DRIVER _DEVELOP/Src/STM32_GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.o: ../DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.c DRIVER\ _DEVELOP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Src" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Inc" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/USART_BUTTON/DRIVERS/DRIVER _DEVELOP/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"DRIVER _DEVELOP/Src/STM32_USART_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DRIVER-20-_DEVELOP-2f-Src

clean-DRIVER-20-_DEVELOP-2f-Src:
	-$(RM) ./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.cyclo ./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.d ./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.o ./DRIVER\ _DEVELOP/Src/STM32_GPIO_DRIVER.su ./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.cyclo ./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.d ./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.o ./DRIVER\ _DEVELOP/Src/STM32_USART_DRIVER.su

.PHONY: clean-DRIVER-20-_DEVELOP-2f-Src

