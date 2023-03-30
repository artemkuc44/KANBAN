cmake_minimum_required(VERSION 3.24)
project(assignment3 C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment3 main.c displayMenu.c displayMenu.h defaultBoard.c defaultBoard.h loadFile.c loadFile.h)
