#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLACES 10

struct Place {
    char *name;
    int availableSeats;
};

struct PlaceControl {
    struct Place places[MAX_PLACES];
    int top;
};

// Инициализация стека мест
void initPlaceControl(struct PlaceControl *placeControl) {
    placeControl->top = -1;
}

// Проверка, пуст ли стек
bool isEmpty(struct PlaceControl *placeControl) {
    return placeControl->top == -1;
}

// Проверка, переполнен ли стек
bool isFull(struct PlaceControl *placeControl) {
    return placeControl->top == MAX_PLACES - 1;
}

// Добавление места в стек
void push(struct PlaceControl *placeControl, char *name, int availableSeats) {
    if (isFull(placeControl)) {
        printf("Стек переполнен. Невозможно добавить место.\n");
        return;
    }
    placeControl->top++;
    placeControl->places[placeControl->top].name = name;
    placeControl->places[placeControl->top].availableSeats = availableSeats;
    printf("Место %s успешно добавлено.\n", name);
}

// Удаление места из стека
void pop(struct PlaceControl *placeControl) {
    if (isEmpty(placeControl)) {
        printf("Стек пуст. Невозможно удалить место.\n");
        return;
    }
    printf("Место %s успешно удалено.\n", placeControl->places[placeControl->top].name);
    placeControl->top--;
}

// Получение информации о текущем месте в стеке
void peek(struct PlaceControl *placeControl) {
    if (isEmpty(placeControl)) {
        printf("Стек пуст.\n");
        return;
    }
    printf("Текущее место: %s, Доступные места: %d\n", placeControl->places[placeControl->top].name, placeControl->places[placeControl->top].availableSeats);
}

// Генерация случайного числа от min до max
int randomRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

int PlaceControl() {
    struct PlaceControl placeControl;
    initPlaceControl(&placeControl);

    // Сгенерируем случайное количество посадочных мест для каждого места
    char *places[] = {"Place1", "Place2", "Place3", "Place4", "Place5", "Place6", "Place7", "Place8", "Place9", "Place10"};
    int availableSeats[MAX_PLACES];

    for (int i = 0; i < MAX_PLACES; ++i) {
        availableSeats[i] = randomRange(1, 25); // Генерация случайного числа от 1 до 125
        push(&placeControl, places[i], availableSeats[i]);
    }

    // Проверка, переполнен ли стек мест
    if (isFull(&placeControl)) {
        printf("Стек мест переполнен.\n");
        return 0;
    } else {
        printf("Места еще доступны.\n");
        return 1;
    }
}

