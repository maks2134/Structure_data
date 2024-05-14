#include <stdio.h>
#include <windows.h>
#include "hookUsers.h"
#include "systemTech.h"

enum {START ,ADD, REMOVE, CHANGE, CHECK, END};

void questionData(){
    changeConsoleTextColor(FOREGROUND_GREEN); //Выбираем цвет текста консоли вызывается в написанном заголовочном файле systemTech.h

    int questionDataBool; //объявляем переменную иммитирующую логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1:Добавить новую запись \n 2:Удалить запись \n 3:Изменить запись \n 4:Проверить запись(доступно только для Admin) \n ");
    scanf("%d", &questionDataBool); //считываем переменную иммитирующую логику выбора
    switch (questionDataBool) { //объявляем условную конструкцию switch
        case ADD:
            addData(); //Функция добавления данных
            break;
        case REMOVE:
            removeData(); //Функция удаления данных
            break;
        case CHANGE:
            changeData(); //Проверка данных
            break;
        case CHECK: //изменение данных
            checkData();
            break;
        default:
            printf("Неверный ввод"); //Работа программу на случай неверного ввода
            break;
    }

}

int main() {
    SetConsoleOutputCP(CP_UTF8); //Устанавливаем формат кодировки
    printf("------------------------------------------------ СИСТЕМА РЕГИСТРАЦИИ ------------------------------------------------");
    questionData(); // переходим к выбору функционала
    return 0; //завершаем работу программы
}
