#include <string.h>
#include <stdio.h>
#include <time.h>

int GetNextId(); //шаблон функции для нового id на новой строке

void IdGenerate() {
    char id[20]; //инициализируем полу id
    time_t current_time;
    struct tm* time_info;

    // Получаем текущее время
    time(&current_time);
    time_info = localtime(&current_time);

    // Форматируем время в строку
    strftime(id, sizeof(id), "%Y%m%d%H%M%S", time_info);

    // Открываем файл для записи в режиме добавления данных (append)
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "a");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    // Записываем сгенерированный ID в файл в новой строке с номером
    fprintf(file, "%s ", id);

    // Закрываем файл
    fclose(file);

    printf("\n Уникальный ID записан в файл admin.txt.\n");
}

int GetNextId() {
    FILE* file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
    if (file == NULL) {
        return 1;  // Если файл не существует, начинаем с единицы
    }

    int count = 0;
    char line[100];

    // Подсчитываем количество строк в файле
    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
    }

    // Закрываем файл
    fclose(file);

    return count + 1;  // Возвращаем следующий номер
}
