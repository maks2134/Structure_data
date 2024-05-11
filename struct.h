#ifndef PRACTICA_STRUCT_H
#define PRACTICA_STRUCT_H

struct temporary_struct {
    char* id;
    char* name;
    int hock;
    struct time_struct {
        int Days;
        int hours;
        char* Month;
    } time_info;
};

#endif