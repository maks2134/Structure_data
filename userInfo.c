#include "IdWork.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "systemTech.h"

void nameInfo() {
    char* name = (char*) calloc(101, sizeof(char));
    printf("\nВведите вашу фамилию (на английской раскладке): ");
    scanf("%s", name);

    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    fprintf(file, "%s ", name); // Записываем имя в строку
    fclose(file);
    free(name);
}

void timeInfo() {
    int hour;
    printf("Выберите время:\n");

    for (hour = 8; hour <= 23; hour++) {
        printf("%d. %02d:00\n", hour - 7, hour);
    }

    int choice;
    printf("Введите номер выбранного времени: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 16) {
        printf("Неверный выбор.\n");
        return;
    }

    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    fprintf(file, "%02d:00 ", choice + 7); // Записываем время в строку
    fclose(file);
}

void DataComplictation() {
    char* places[10] = {"Place 1", "Place 2", "Place 3", "Place 4", "Place 5", "Place 6", "Place 7", "Place 8", "Place 9", "Place 10"};
    int choice;
    printf("Выберите место из списка:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, places[i]);
    }
    printf("Введите номер выбранного места: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 10) {
        printf("Неверный выбор.\n");
        return;
    }

    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    fprintf(file, "%s ", places[choice - 1]); // Записываем место в строку
    fclose(file);
}

void delimeter(){
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        Exit();
    }
    fprintf(file, "\n");
}

void ReadID() {
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        Exit();
    }

    char line[256];
    char lastLine[256];
    lastLine[0] = '\0'; // Инициализация пустой строки

    while (fgets(line, sizeof(line), file)) {
        strcpy(lastLine, line); // Сохраняем последнюю считанную строку
    }

    fclose(file);

    if (lastLine[0] != '\0') {
        char* lastID = strrchr(lastLine, ' ');
        if (lastID != NULL) {
            lastID++; // Пропускаем пробел, чтобы получить начало ID
            printf("Информация успешно записана! \nВаш ID(обязательно запомните его): %s", lastID);
        }
    } else {
        printf("Файл пуст или не удалось прочитать содержимое.\n");
    }
}

void UserGeneration() {
    DataComplictation();
    ClearConsole();
    timeInfo();
    ClearConsole();
    nameInfo();
    ClearConsole();
    IdGenerate();
    ClearConsole();
    delimeter();
    ClearConsole();
    ReadID();
}
