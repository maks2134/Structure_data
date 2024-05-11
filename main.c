#include <stdio.h>
#include <windows.h>
#include "hookUsers.h"
#include "systemTech.h"

void questionData(){
    changeConsoleTextColor(FOREGROUND_GREEN); //Выбираем цвет текста консоли вызывается в написанном заголовочном файле systemTech.h
    int questionDataBool; //объявляем переменную иммитирующую логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1:Добавить новую запись \n 2:Удалить запись \n 3:Изменить запись \n ");
    scanf("%d", &questionDataBool); //считываем переменную иммитирующую логику выбора
    switch (questionDataBool) { //объявляем условную конструкцию switch
        case 1:
            addData(); //Функция добавления данных
            break;
        case 2:
            removeData(); //Функция удаления данных
            break;
        case 3:
            changeData(); //Проверка данных
            break;
        default:
            printf("Неверный ввод"); //Работа программу на случай неверного ввода
            break;
    }

}

int main() {
    SetConsoleOutputCP(CP_UTF8); //Устанавливаем формат кодировки
    char* txtName = "C:\\Users\\maks2\\CLionProjects\\Structure_data\\test.txt";
    printf("------------------------------------------------ СИСТЕМА РЕГИСТРАЦИИ ------------------------------------------------");
    questionData(); // переходим к выбору функционала
    return 0; //завершаем работу программы
}
