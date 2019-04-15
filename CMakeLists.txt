cmake_minimum_required(VERSION 3.13)
project(0-coursework C)

set(CMAKE_C_STANDARD 99)

add_executable(0-coursework main.c sortingVector.c sortingVector.h measurement.c measurement.h common.c common.h sortingArray3D.c sortingArray3D.h menu.c menu.h)
 target_link_libraries(0-coursework m curses)