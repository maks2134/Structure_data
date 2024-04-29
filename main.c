#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "struct.h"
#include "systemTech.h"
#include "userInfo.h"
#include "IdWork.h"

void changeData(){

}

void addData(){


}

void removeData(){

}

void checkData(){

}

void printData(){

}

void sortingData();

void questionData(){
    changeConsoleTextColor(FOREGROUND_GREEN);
    int questionDataBool;
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1:Добавить новую запись \n 2:Удалить запись \n 3:Изменить запись");
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

void txtInit(char txtName[]) {
    FILE *file = fopen(txtName, "w"); // Открываем файл с переданным именем для записи

    if (file == NULL) { //Проверка на существования файла
        printf("Не удалось открыть файл!");
        getchar();
        exit(1);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8); //Устанавливаем формат кодировки
    char* txtName = "C:\\Users\\maks2\\CLionProjects\\Structure_data\\test.txt";
    txtInit(txtName); //Инициализируем работу с текстовым файлом
    printf("------------------------------------------------ СИСТЕМА РЕГИСТРАЦИИ ------------------------------------------------");

    questionData();
    return 0;
}
