################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Main_app/Src/humidity_sensor.c \
../Main_app/Src/main_inner_system.c \
../Main_app/Src/micro_servo_motor.c \
../Main_app/Src/soil_sensor.c \
../Main_app/Src/tools.c \
../Main_app/Src/ultra_sonic_sensor.c 

OBJS += \
./Main_app/Src/humidity_sensor.o \
./Main_app/Src/main_inner_system.o \
./Main_app/Src/micro_servo_motor.o \
./Main_app/Src/soil_sensor.o \
./Main_app/Src/tools.o \
./Main_app/Src/ultra_sonic_sensor.o 

C_DEPS += \
./Main_app/Src/humidity_sensor.d \
./Main_app/Src/main_inner_system.d \
./Main_app/Src/micro_servo_motor.d \
./Main_app/Src/soil_sensor.d \
./Main_app/Src/tools.d \
./Main_app/Src/ultra_sonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Main_app/Src/%.o Main_app/Src/%.su Main_app/Src/%.cyclo: ../Main_app/Src/%.c Main_app/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F756xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"/home/asaad/STM32CubeIDE/workspace_1.13.2/sensors_peripheral_project/Main_app/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Main_app-2f-Src

clean-Main_app-2f-Src:
	-$(RM) ./Main_app/Src/humidity_sensor.cyclo ./Main_app/Src/humidity_sensor.d ./Main_app/Src/humidity_sensor.o ./Main_app/Src/humidity_sensor.su ./Main_app/Src/main_inner_system.cyclo ./Main_app/Src/main_inner_system.d ./Main_app/Src/main_inner_system.o ./Main_app/Src/main_inner_system.su ./Main_app/Src/micro_servo_motor.cyclo ./Main_app/Src/micro_servo_motor.d ./Main_app/Src/micro_servo_motor.o ./Main_app/Src/micro_servo_motor.su ./Main_app/Src/soil_sensor.cyclo ./Main_app/Src/soil_sensor.d ./Main_app/Src/soil_sensor.o ./Main_app/Src/soil_sensor.su ./Main_app/Src/tools.cyclo ./Main_app/Src/tools.d ./Main_app/Src/tools.o ./Main_app/Src/tools.su ./Main_app/Src/ultra_sonic_sensor.cyclo ./Main_app/Src/ultra_sonic_sensor.d ./Main_app/Src/ultra_sonic_sensor.o ./Main_app/Src/ultra_sonic_sensor.su

.PHONY: clean-Main_app-2f-Src

