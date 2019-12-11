cmake_minimum_required(VERSION 3.8)

project(Amber C)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

add_executable(amber amber.c)
 
