#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "systemTech.h"
#include "hookUsers.h"

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

void GenerateReport() {
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

        // Обновление колличества мест
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

        // Обновление колличества времени
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

    // Выделение самых посещаемых мест
    int maxPlaceCount = 0;
    int mostVisitedPlace = 0;
    for (int i = 0; i < placeCountSize; i++) {
        if (placeCounts[i].count > maxPlaceCount) {
            maxPlaceCount = placeCounts[i].count;
            mostVisitedPlace = placeCounts[i].place;
        }
    }

    // Выделение самого популярного времени
    int maxTimeCount = 0;
    char mostPopularTime[6] = "";
    for (int i = 0; i < timeCountSize; i++) {
        if (timeCounts[i].count > maxTimeCount) {
            maxTimeCount = timeCounts[i].count;
            strcpy(mostPopularTime, timeCounts[i].time);
        }
    }
    ClearConsole();
    // Генерация отчёта в виде таблицы
    printf("|----------------------|------------------|\n");
    printf("| Most visited place   | Most popular time|\n");
    printf("|----------------------+------------------|\n");
    printf("| Place %d              | %-16s |\n", mostVisitedPlace, mostPopularTime);
    printf("|-----------------------------------------|\n\n\n\n");

    int choise;
    printf("Желаете отсортировать места по популрности?\n1-Да\t2-нет\n");
    scanf("%d",&choise);
    if(choise){
        sortingData();
    }else{
        return;
    }

}
