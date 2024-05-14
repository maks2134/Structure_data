#include "IdWork.h"
#include <stdio.h>
#include <stdlib.h>
#include "systemTech.h"

char* nameInfo() { //Ввод фамилии пользователя
    char* name = (char*) calloc(101, sizeof(char)); // выделение 101 байта памяти
    printf("\n Введите вашу фамилию(на английской раскладке):");
    scanf("%s", name);

    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        Exit();
    }

    // Записываем сгенерированный ID в файл в новой строке с номером
    fprintf(file, "%s\n", name);
    return name;
}

void timeInfo() {
    // Фиксация в файле
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    // Запрос времени
    int hour;
    printf("Выберите время:\n");

    for (hour = 8; hour <= 23; hour++) {
        printf("%d. %02d:00\n", hour - 7, hour);
    }

    int choice;
    printf("Введите номер выбранного времени: ");
    scanf("%d", &choice);

    // Проверка валидности выбора
    if (choice < 1 || choice > 16) {
        printf("Неверный выбор.\n");
        fclose(file);
        return;
    }

    // Запись времени в файл
    fprintf(file, "%02d:00\n", choice + 7);

    fclose(file);
    printf("Время успешно записано в файл.\n");
}

void DataComplictation() {
    // Список 10 заведений
    char* places[10] = {"Place 1", "Place 2", "Place 3", "Place 4", "Place 5", "Place 6", "Place 7", "Place 8", "Place 9", "Place 10"};

    // Запрос места
    int choice;
    printf("Выберите место из списка:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, places[i]);
    }
    printf("Введите номер выбранного места: ");
    scanf("%d", &choice);

    // Проверка валидности выбора
    if (choice < 1 || choice > 10) {
        printf("Неверный выбор.\n");
        return;
    }

    // Фиксация в файле
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    fprintf(file, "%s\n", places[choice - 1]);

    fclose(file);
    printf("Место успешно записано в файл.\n");
}

void delimeter(){
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        Exit();
    }
    fprintf(file, "\n");
}

void UserGeneration(){ //основная функция генерации пользователя

    IdGenerate();
    ClearConsole();
    char* name = nameInfo();
    ClearConsole();
    DataComplictation();
    ClearConsole();
    timeInfo();
    ClearConsole();
    delimeter();
    ClearConsole();
    printf("Информация успешно записана");

    free(name);
}