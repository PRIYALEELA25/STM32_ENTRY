################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER/Src/STM32GPIO_DRIVER.c 

OBJS += \
./DRIVER/Src/STM32GPIO_DRIVER.o 

C_DEPS += \
./DRIVER/Src/STM32GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVER/Src/%.o DRIVER/Src/%.su DRIVER/Src/%.cyclo: ../DRIVER/Src/%.c DRIVER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/GPIO_BLINK/DRIVER/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DRIVER-2f-Src

clean-DRIVER-2f-Src:
	-$(RM) ./DRIVER/Src/STM32GPIO_DRIVER.cyclo ./DRIVER/Src/STM32GPIO_DRIVER.d ./DRIVER/Src/STM32GPIO_DRIVER.o ./DRIVER/Src/STM32GPIO_DRIVER.su

.PHONY: clean-DRIVER-2f-Src

