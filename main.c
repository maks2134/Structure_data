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

void changeData(){

}

void addData(){
    printf("Выберите какой сервис вас инетресует: \n");

}

void removeData(){

}

void checkData(){

}

void printData(){

}

void questionData(){
    int questionDataBool;
    printf("Выберите нужный функционал:\n");
    printf("1:Добавить новую запись \n 2:Удалить запись \n 3:Изменить запись");
    scanf("%d", questionDataBool);

    switch (questionDataBool) {
        case 1:
            addData();
        case 2:
            removeData();
        case 3:
            changeData();
    }

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
