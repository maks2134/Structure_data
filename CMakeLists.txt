cmake_minimum_required(VERSION 3.26)
project(practica C)

set(CMAKE_C_STANDARD 11)

add_executable(practica main.c struct.h
        userInfo.h
        userInfo.c
        systemTech.h
        systemTech.c
        IdWork.h
        IdWork.c)

target_link_libraries(practica PRIVATE winmm)