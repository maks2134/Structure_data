#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct temporarry_struct{
    int id;
    char name;
    int date;
    char user;
    int hoock;
};

void addData(){

}

void removeData(){

}

void checkData(){

}

void printData(){

}

void txtInit(char txtName[]){
    FILE *data;

    if((data = fopen(txtName, "r"))==NULL){
        printf("Не Удалось открыть БД!");
        getchar();
        exit(1);
    }
        fclose(data);
        getchar();
}

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    char txtName[] = "data.txt";
    txtInit(txtName);
    return 0;
}
