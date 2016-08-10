cmake_minimum_required(VERSION 3.5)
project(GBCEmu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/CPU.cpp src/CPU.hpp src/MemoryManager.cpp src/MemoryManager.hpp src/Cartridge.cpp src/Cartridge.hpp)
add_executable(GBCEmu ${SOURCE_FILES})