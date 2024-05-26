#include <stdio.h>
#include <windows.h>
#include "hookUsers.h"
#include "systemTech.h" //функции для работы с системой
#include "checking.h"

enum {START ,ADD, REMOVE, CHANGE, CHECK, END};

void questionData(){
    changeConsoleTextColor(FOREGROUND_GREEN); // Выбираем цвет текста консоли (определено в systemTech.h)

    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\n Выберите нужный функционал:\n");
    printf("\n 1: Добавить новую запись \n 2: Удалить запись \n 3: Изменить запись \n 4: Проверить запись (доступно только для Админа) \n ");
    scanf("%d", &questionDataBool); // Считываем переменную, имитирующую логику выбора
    switch (questionDataBool) {
        case ADD:
            addData(); // Функция добавления данных
            break;
        case REMOVE:
            removeData(); // Функция удаления данных
            break;
        case CHANGE:
            changeData(); // Функция изменения данных
            break;
        case CHECK:
            checkData(); // Функция проверки данных
            break;
        case END:
            GenerateReport(); // Функция для генерации отчета
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода
            break;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем UTF-8 кодировку
    Music();
    printf("------------------------------------------------ СИСТЕМА РЕГИСТРАЦИИ ------------------------------------------------");
    int choice;
    do { //зацикливаем main
        questionData(); // Переходим к выбору функционала
        printf("\nЖелаете продолжить? (1: Да, 0: Нет): ");
        scanf("%d", &choice); // Спрашиваем пользователя, хочет ли он продолжить
        ClearConsole();
    } while (choice != 0); // Продолжаем цикл до тех пор, пока пользователь не решит завершить программу
    return 0; // Завершаем программу
}
