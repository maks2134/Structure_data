#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInfo.h"

void changeUsers() {
    int question;
    printf("Вы уверены, что хотите изменить бронь?\n");
    printf("1-Да, уверен(а)\n");
    printf("2-Нет, не уверен(а)\n");
    scanf("%d", &question);

    if (question == 1) {
        char ID[20];
        printf("Введите свой ID для подтверждения изменения брони: ");
        scanf("%s", ID);

        FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
        if (file == NULL) {
            printf("Ошибка при открытии файла.\n");
            return;
        }

        // Временный файл для записи новых данных
        FILE *tempFile = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\temp.txt", "w");
        if (tempFile == NULL) {
            printf("Ошибка при создании временного файла.\n");
            fclose(file);
            return;
        }

        char line[256];
        int found = 0;

        while (fgets(line, sizeof(line), file)) {
            // Проверяем, содержит ли строка указанный ID
            if (strstr(line, ID) == NULL) {
                // Если не содержит, записываем строку в временный файл
                fputs(line, tempFile);
            } else {
                found = 1;
            }
        }

        fclose(file);
        fclose(tempFile);

        // Удаляем оригинальный файл и переименовываем временный файл
        remove("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt");
        rename("C:\\Users\\maks2\\CLionProjects\\Structure_data\\temp.txt",
               "C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt");

        if (found) {
            UserGeneration();
        } else {
            printf("ID не найден.\n");
        }
    }
}