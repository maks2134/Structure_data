#include <stdio.h>
#include <stdlib.h>
#include "systemTech.h"
#include "sha256.h"
#include <string.h>

void registrationAdmin(const char *password, const char* login, const char* code);

struct adminData {
    char* login;
    char* password;
    char* code;
};

void loginAdmin(){

}

void registrationInfo() {
    struct adminData* adminData = malloc(sizeof(struct adminData));

    printf("Создайте логин: \n");
    adminData->login = malloc(100);  // Выделение памяти для строки name
    scanf("%s", adminData->login);

    printf("Придумайте пароль: \n");
    adminData->password = malloc(100);  // Выделение памяти для строки name
    scanf("%s", adminData->password);

    printf("Введите уникальный код: \n");
    adminData->code = malloc(100);
    scanf("%s", adminData->code);

    registrationAdmin(adminData->password,adminData->login,adminData->code);
    // Освобождение памяти, когда она больше не нужна
    free(adminData->login);
    free(adminData->password);
    free(adminData->code);
    free(adminData);
}

void registrationAdmin(const char *password, const char* login, const char* code) {
    struct sha256 sha;
    char hash_hex[65];

    // Инициализация SHA-256
    sha256_init(&sha);

    // Добавление пароля в хэш-функцию
    sha256_append(&sha, password, strlen(password));

    // Завершение хэширования
    sha256_finalize_hex(&sha, hash_hex);

    // Открытие файла для записи хэша
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\adminData.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    // Запись хэша в файл
    fprintf(file, "%s", hash_hex);

    // Закрытие файла
    fclose(file);

    printf("Регистрация администратора завершена.\n");
}


void startAdminPanel(){
    ClearConsole();
    printf("Добрый день, вы являетесь админом или только присоеденились к команде? \n(1-являюсь) \n(2-не являюсь)");
    int confirm;
    scanf("%d", &confirm);
    switch (confirm) {
        case 1:
            ClearConsole();
            printf("Войдите в учётную запись: \n");
            loginAdmin();
            break;
        case 2:
            ClearConsole();
            printf("Регистрация учётной записи: \n");
            registrationInfo();
            break;
        default:
            printf("Неверный ввод!");
            break;
    }

}
