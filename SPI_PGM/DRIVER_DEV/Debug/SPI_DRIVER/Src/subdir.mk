################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SPI_DRIVER/Src/STM32_GPIO_DRIVER.c \
../SPI_DRIVER/Src/STM32_SPI_DRIVER.c 

OBJS += \
./SPI_DRIVER/Src/STM32_GPIO_DRIVER.o \
./SPI_DRIVER/Src/STM32_SPI_DRIVER.o 

C_DEPS += \
./SPI_DRIVER/Src/STM32_GPIO_DRIVER.d \
./SPI_DRIVER/Src/STM32_SPI_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
SPI_DRIVER/Src/%.o SPI_DRIVER/Src/%.su SPI_DRIVER/Src/%.cyclo: ../SPI_DRIVER/Src/%.c SPI_DRIVER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/SPI_PGM/DRIVER_DEV/SPI_DRIVER/Src" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/SPI_PGM/DRIVER_DEV/SPI_DRIVER/Inc" -I"C:/Users/hp/Desktop/EMBEDEDSYSTEM-C/STM32_PJT/SPI_PGM/DRIVER_DEV/SPI_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SPI_DRIVER-2f-Src

clean-SPI_DRIVER-2f-Src:
	-$(RM) ./SPI_DRIVER/Src/STM32_GPIO_DRIVER.cyclo ./SPI_DRIVER/Src/STM32_GPIO_DRIVER.d ./SPI_DRIVER/Src/STM32_GPIO_DRIVER.o ./SPI_DRIVER/Src/STM32_GPIO_DRIVER.su ./SPI_DRIVER/Src/STM32_SPI_DRIVER.cyclo ./SPI_DRIVER/Src/STM32_SPI_DRIVER.d ./SPI_DRIVER/Src/STM32_SPI_DRIVER.o ./SPI_DRIVER/Src/STM32_SPI_DRIVER.su

.PHONY: clean-SPI_DRIVER-2f-Src

