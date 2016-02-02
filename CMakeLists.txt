cmake_minimum_required(VERSION 3.4)

project(TeensyFreeRTOSPort)

# newlib port
#file(GLOB newlib_port "newlib/port.c")

# collect the FreeRTOS files
#file(GLOB freertos_src "FreeRTOS/src/*.cpp" "FreeRTOS/src/*.c")
#file(GLOB freertos_port "FreeRTOS/port/*.S" "FreeRTOS/port/*.c")

# collect the CMSIS files
#file(GLOB cmsis_device_src "cmsis/Device/ARM/ARMCM4/Source/*.c")

# collect the Teensy files
file(GLOB teensy_src "platform/cores/teensy3/*.c" "platform/cores/teensy3/*.cpp" "platform/cores/teensy3/*.h" "platform/cores/teensy3/*.h")

# collect the application files
file(GLOB src "src/*.cpp")

# add top-level pathto executable
include_directories("platform/cores/teensy3")
#include_directories("platform/")
#include_directories("FreeRTOS/include")
#include_directories("FreeRTOS/port")
#include_directories("cmsis/Device/ARM/ARMCM4/Include")
#include_directories("cmsis/CMSIS/Include")

# choose the compiler
set(CMAKE_C_COMPILER "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER "/usr/bin/arm-none-eabi-as")

# set up the compiler settings
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/platform/mk20dx256.ld")
#set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/platform/cmsis_armcm4.ld")
set(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT} -Os -Wl,--gc-sections,--defsym=__rtc_localtime=0 --specs=nano.specs -mcpu=cortex-m4 -mthumb")

set(ARCH_OPTIONS "-D__MK20DX256__ -DF_CPU=96000000 -DUSB_SERIAL -DLAYOUT_US_ENGLISH")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Os -mcpu=cortex-m4 -mthumb -MMD ${ARCH_OPTIONS}")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "${CMAKE_C_FLAGS} -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti")
set(CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS} "-mcpu=cortex-m4 -mthumb")

# compile the executable
#add_executable(teensy-freertos ${cmsis_device_src} ${newlib_port} ${freertos_port} ${freertos_src} ${src})
add_executable(teensy-freertos ${teensy_src} ${src})
