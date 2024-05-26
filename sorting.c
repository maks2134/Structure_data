#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLACES 100

typedef struct {
    int place;
    int count;
} PlaceCount;

void swap(PlaceCount *a, PlaceCount *b) {
    PlaceCount temp = *a;
    *a = *b;
    *b = temp;
}

int partition(PlaceCount arr[], int low, int high) {
    int pivot = arr[high].count;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].count > pivot) { // Сортировка по убыванию
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(PlaceCount arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sorting() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    PlaceCount placeCounts[MAX_PLACES] = {0};
    int placeCountSize = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int place;
        sscanf(line, "Place %d", &place);

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
    }

    fclose(file);

    // Сортировка мест по популярности
    quickSort(placeCounts, 0, placeCountSize - 1);

    // Вывод отсортированных данных в виде таблицы
    printf("\n");
    printf("|---------------------|--------------------|\n");
    printf("|      Место          | Количество броней  |\n");
    printf("|---------------------|--------------------|\n");

    for (int i = 0; i < placeCountSize; i++) {
        printf("| Place %d             | %d                  |\n", placeCounts[i].place, placeCounts[i].count);
    }

    printf("|------------------------------------------|\n\n");
    printf("Места успешно отсортированы по популярности.\n");
}