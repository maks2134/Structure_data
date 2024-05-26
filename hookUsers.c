#include "userInfo.h"
#include "systemTech.h"
#include "remove.h"
#include "admin.h"
#include "changeUser.h"
#include "sorting.h"

void addData(){
    ClearConsole();
    UserGeneration();
}

void removeData(){
    ClearConsole();
    removeUser();
}

void checkData(){
    ClearConsole();
    startAdminPanel();
}


void sortingData(){
    sorting();
}

void changeData(){
    ClearConsole();
    changeUsers();
}