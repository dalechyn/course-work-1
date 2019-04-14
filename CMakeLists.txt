cmake_minimum_required(VERSION 3.13)
project(0-coursework C)

set(CMAKE_C_STANDARD 99)

add_executable(0-coursework main.c SortingVector.c SortingVector.h Measurement.c Measurement.h Common.c Common.h SortingArray3D.c SortingArray3D.h menu.c menu.h)
 target_link_libraries(0-coursework m curses)