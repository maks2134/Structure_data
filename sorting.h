#ifndef PRACTICA_SORTING_H
#define PRACTICA_SORTING_H

typedef struct {
    int place;
    int count;
} PlaceCount;

void quickSort(PlaceCount arr[], int low, int high);
void sorting();
#endif
