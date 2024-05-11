#include <windows.h>
#include <stdlib.h>

void changeConsoleTextColor(int color) { //выбор цвета текста консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ClearConsole() { //очищение консоли
    system("cls");
}

void Exit(){ //Выход из программы
    exit(1);
}