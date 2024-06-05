cmake_minimum_required(VERSION 3.26)
project(practica C)

include_directories(${CMAKE_SOURCE_DIR}/libs/include)
link_directories(${CMAKE_SOURCE_DIR}/libs/lib)

set(CMAKE_C_STANDARD 11)

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
        removeUser.c
        remove.h
        changeUser.c
        changeUser.h
        sorting.c
        sorting.h
        serverControl.c
        serverControl.h
)

target_link_libraries(practica curl winmm)