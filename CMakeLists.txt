cmake_minimum_required(VERSION 3.5)
project(GBCEmu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_COMPILER  clang++)

#set(SFML_ROOT "/usr/local/include")
#set(SFML_INCLUDE_PATH "/usr/local/include")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake_modules)

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.4 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES src/main.cpp src/CPU.cpp src/CPU.hpp src/MemoryManager.cpp src/MemoryManager.hpp src/Cartridge.cpp src/Cartridge.hpp src/GPU.cpp src/GPU.hpp src/GameBoy.cpp src/GameBoy.hpp src/Log.hpp src/Audio.cpp src/Audio.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(GBCEmu ${SOURCE_FILES})
target_link_libraries(GBCEmu ${SFML_LIBRARIES})