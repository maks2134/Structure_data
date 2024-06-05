#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "systemTech.h"
#include "hookUsers.h"

#define MAX_PLACES 100
#define MAX_TIMES 100

typedef struct PlaceNode {
    int place;
    int count;
    struct PlaceNode *left;
    struct PlaceNode *right;
} PlaceNode;

typedef struct TimeNode {
    char time[6];
    int count;
    struct TimeNode *left;
    struct TimeNode *right;
} TimeNode;

PlaceNode* createPlaceNode(int place) {
    PlaceNode *newNode = (PlaceNode*) malloc(sizeof(PlaceNode));
    newNode->place = place;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

PlaceNode* insertPlaceNode(PlaceNode *root, int place) {
    if (root == NULL) {
        return createPlaceNode(place);
    }
    if (place < root->place) {
        root->left = insertPlaceNode(root->left, place);
    } else if (place > root->place) {
        root->right = insertPlaceNode(root->right, place);
    } else {
        root->count++;
    }
    return root;
}

TimeNode* createTimeNode(char *time) {
    TimeNode *newNode = (TimeNode*) malloc(sizeof(TimeNode));
    strcpy(newNode->time, time);
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TimeNode* insertTimeNode(TimeNode *root, char *time) {
    if (root == NULL) {
        return createTimeNode(time);
    }
    int cmp = strcmp(time, root->time);
    if (cmp < 0) {
        root->left = insertTimeNode(root->left, time);
    } else if (cmp > 0) {
        root->right = insertTimeNode(root->right, time);
    } else {
        root->count++;
    }
    return root;
}

void findMaxPlace(PlaceNode *root, int *maxCount, int *mostVisitedPlace) {
    if (root != NULL) {
        findMaxPlace(root->left, maxCount, mostVisitedPlace);
        if (root->count > *maxCount) {
            *maxCount = root->count;
            *mostVisitedPlace = root->place;
        }
        findMaxPlace(root->right, maxCount, mostVisitedPlace);
    }
}

void findMaxTime(TimeNode *root, int *maxCount, char *mostPopularTime) {
    if (root != NULL) {
        findMaxTime(root->left, maxCount, mostPopularTime);
        if (root->count > *maxCount) {
            *maxCount = root->count;
            strcpy(mostPopularTime, root->time);
        }
        findMaxTime(root->right, maxCount, mostPopularTime);
    }
}

void freePlaceTree(PlaceNode *root) {
    if (root != NULL) {
        freePlaceTree(root->left);
        freePlaceTree(root->right);
        free(root);
    }
}

void freeTimeTree(TimeNode *root) {
    if (root != NULL) {
        freeTimeTree(root->left);
        freeTimeTree(root->right);
        free(root);
    }
}

void GenerateReport() {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\admin.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    PlaceNode *placeRoot = NULL;
    TimeNode *timeRoot = NULL;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int place;
        char time[6];
        sscanf(line, "Place %d %5s", &place, time);

        placeRoot = insertPlaceNode(placeRoot, place);
        timeRoot = insertTimeNode(timeRoot, time);
    }

    fclose(file);

    int maxPlaceCount = 0;
    int mostVisitedPlace = 0;
    findMaxPlace(placeRoot, &maxPlaceCount, &mostVisitedPlace);

    int maxTimeCount = 0;
    char mostPopularTime[6] = "";
    findMaxTime(timeRoot, &maxTimeCount, mostPopularTime);

    ClearConsole();
    // Генерация отчёта в виде таблицы
    printf("|----------------------|------------------|\n");
    printf("| популярное место     |  популярное время|\n");
    printf("|----------------------+------------------|\n");
    printf("| Place %d              | %-16s |\n", mostVisitedPlace, mostPopularTime);
    printf("|-----------------------------------------|\n\n\n\n");

    int choise;
    printf("Желаете отсортировать места и время по популрности?\n1-Да\t2-нет\n\n");
    scanf("%d",&choise);
    if(choise){
        sortingData();
    }else{
        return;
    }

}
