cmake_minimum_required(VERSION 3.4)

project(TeensyFreeRTOSPort)

# collect the FreeRTOS files
file(GLOB freertos_src "freertos/FreeRTOS/Source/*.c")
set(freertos_port "${CMAKE_SOURCE_DIR}/freertos/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c")

# collect the Teensy files
#file(GLOB teensy_src "platform/cores/teensy3/*.c" "platform/cores/teensy3/*.cpp" "platform/cores/teensy3/*.h" "platform/cores/teensy3/*.h")
set(platform_src "${CMAKE_SOURCE_DIR}/platform/mk20dx128.c")

# collect the application files
file(GLOB src "src/*.cpp")

# add top-level pathto executable
include_directories("platform/cores/teensy3")
include_directories("platform/")
include_directories("freertos/FreeRTOS/Source/include")
include_directories("freertos/FreeRTOS/Source/portable/GCC/ARM_CM3")
include_directories("cmsis/CMSIS/Include")
include_directories("cmsis/Device/ARM/ARMCM4/Include")

# choose the compiler
set(CMAKE_C_COMPILER "/usr/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER "/usr/bin/arm-none-eabi-as")

# set up the compiler settings
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/platform/mk20dx256.ld")
#set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/platform/cmsis_armcm4.ld")
set(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT} -Wl,--gc-sections,--defsym=__rtc_localtime=0 --specs=nano.specs -mcpu=cortex-m3")

set(ARCH_OPTIONS "-D__MK20DX256__ -DF_CPU=96000000 -DUSB_SERIAL -DLAYOUT_US_ENGLISH -mthumb -mcpu=cortex-m3")
set(CMAKE_C_FLAGS "-Wall -MMD ${ARCH_OPTIONS}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti")
set(CMAKE_ASM_FLAGS "${ARCH_OPTIONS}")

# compile the executable
add_executable(teensy-freertos ${freertos_port} ${freertos_src} ${platform_src} ${teensy_src} ${src})
