cmake_minimum_required(VERSION 3.23)
project(HeatSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(HeatSim main.cpp HeatSystem.cpp HeatSystem.h Matrix.cpp Matrix.h)
