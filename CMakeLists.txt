cmake_minimum_required(VERSION 3.26)
project(practica C)

set(CMAKE_C_STANDARD 11)

#include_directories(C:\\Users\\maks2\\CLionProjects\\libxlsxwriter-RELEASE_1.1.7\\include)
#
#link_directories(C:\\Users\\maks2\\CLionProjects\\libxlsxwriter-RELEASE_1.1.7\\lib)
#


add_executable(practica main.c
        userInfo.h
        userInfo.c
        systemTech.h
        systemTech.c
        IdWork.h
        IdWork.c
        hookUsers.h
        hookUsers.c
        admin.h
        admin.c
        sha256.h
        sha256.c
        checking.c
        checking.h
)

#target_link_libraries(practica xlsxwriter)