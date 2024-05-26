#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLACES 100
#define MAX_TIMES 100

typedef struct {
    int place;
    int count;
} PlaceCount;

typedef struct {
    char time[6];
    int count;
} TimeCount;

void swapPlaceCount(PlaceCount *a, PlaceCount *b) {
    PlaceCount temp = *a;
    *a = *b;
    *b = temp;
}

void swapTimeCount(TimeCount *a, TimeCount *b) {
    TimeCount temp = *a;
    *a = *b;
    *b = temp;
}

int partitionPlace(PlaceCount arr[], int low, int high) {
    int pivot = arr[high].count;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].count > pivot) { // Сортировка по убыванию
            i++;
            swapPlaceCount(&arr[i], &arr[j]);
        }
    }
    swapPlaceCount(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionTime(TimeCount arr[], int low, int high) {
    int pivot = arr[high].count;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].count > pivot) { // Сортировка по убыванию
            i++;
            swapTimeCount(&arr[i], &arr[j]);
        }
    }
    swapTimeCount(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortPlace(PlaceCount arr[], int low, int high) {
    if (low < high) {
        int pi = partitionPlace(arr, low, high);

        quickSortPlace(arr, low, pi - 1);
        quickSortPlace(arr, pi + 1, high);
    }
}

void quickSortTime(TimeCount arr[], int low, int high) {
    if (low < high) {
        int pi = partitionTime(arr, low, high);

        quickSortTime(arr, low, pi - 1);
        quickSortTime(arr, pi + 1, high);
    }
}

void sorting() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    PlaceCount placeCounts[MAX_PLACES] = {0};
    TimeCount timeCounts[MAX_TIMES] = {0};
    int placeCountSize = 0;
    int timeCountSize = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int place;
        char time[6];
        sscanf(line, "Place %d %5s", &place, time);

        // Обновление количества мест
        int placeFound = 0;
        for (int i = 0; i < placeCountSize; i++) {
            if (placeCounts[i].place == place) {
                placeCounts[i].count++;
                placeFound = 1;
                break;
            }
        }
        if (!placeFound && placeCountSize < MAX_PLACES) {
            placeCounts[placeCountSize].place = place;
            placeCounts[placeCountSize].count = 1;
            placeCountSize++;
        }

        // Обновление количества времени
        int timeFound = 0;
        for (int i = 0; i < timeCountSize; i++) {
            if (strcmp(timeCounts[i].time, time) == 0) {
                timeCounts[i].count++;
                timeFound = 1;
                break;
            }
        }
        if (!timeFound && timeCountSize < MAX_TIMES) {
            strcpy(timeCounts[timeCountSize].time, time);
            timeCounts[timeCountSize].count = 1;
            timeCountSize++;
        }
    }

    fclose(file);

    // Сортировка мест и времени по популярности
    quickSortPlace(placeCounts, 0, placeCountSize - 1);
    quickSortTime(timeCounts, 0, timeCountSize - 1);

// Вывод отсортированных данных по местам
    printf("|---------------------|------------------|\n");
    printf("|      Место          | Количество       |\n");
    printf("|---------------------|------------------|\n");

    for (int i = 0; i < placeCountSize; i++) {
        printf("| Place %-13d | %-16d |\n", placeCounts[i].place, placeCounts[i].count);
    }

    printf("|----------------------------------------|\n\n");

    // Вывод отсортированных данных по времени
    printf("|---------------------|------------------|\n");
    printf("|      Время          | Количество       |\n");
    printf("|---------------------|------------------|\n");

    for (int i = 0; i < timeCountSize; i++) {
        printf("| %-19s | %-16d |\n", timeCounts[i].time, timeCounts[i].count);
    }

    printf("|----------------------------------------|\n\n");
    printf("Места и время успешно отсортированы по популярности.\n");
}