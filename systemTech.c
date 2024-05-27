#include <windows.h>
#include <stdlib.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void changeConsoleTextColor(int color) { // выбор цвета текста консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ClearConsole() { // очищение консоли
    system("cls");
}

void Exit() { // Выход из программы
    exit(1);
}

void Music() { //Работа с аудио для фона консоли
    PlaySound("C:\\Users\\maks2\\CLionProjects\\Structure_data\\uy.wav", NULL, SND_FILENAME | SND_ASYNC);
}