cmake_minimum_required(VERSION 3.6)
project(Army)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Anmyy/Units/Unit.h Anmyy/Units/Unit.cpp Anmyy/Abilities/UnitState.cpp Anmyy/Abilities/UnitState.h Anmyy/Units/UnitExceptions.h)
add_executable(Army ${SOURCE_FILES})