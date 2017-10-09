################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app.c \
../src/main.c \
../src/nn.c \
../src/utils.c 

OBJS += \
./src/app.o \
./src/main.o \
./src/nn.o \
./src/utils.o 

C_DEPS += \
./src/app.d \
./src/main.d \
./src/nn.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


