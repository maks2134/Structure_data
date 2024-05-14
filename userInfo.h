#ifndef PRACTICA_USERINFO_H
#define PRACTICA_USERINFO_H

void UserGeneration();
void nameInfo();
void timeInfo();
void UserAuth();
void DataComplictation();
void delimeter();

struct userInfo{
    char* name;
    int id;
    double time;
    char* places;

};
#endif