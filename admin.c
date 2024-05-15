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

void loginAdmin();

void loginCheck(const char *login, const char *password) {
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\adminData.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    char line[256];
    int isValidLogin = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *savedLogin = strtok(line, " ");
        char *savedHash = strtok(NULL, " ");

        // Удаление символа новой строки из сохраненного хэша
        savedHash[strcspn(savedHash, "\n")] = '\0';

        // Проверка совпадения логина
        if (strcmp(login, savedLogin) == 0) {
            struct sha256 sha;
            char hash_hex[65];

            // Инициализация SHA-256
            sha256_init(&sha);

            // Добавление пароля в хэш-функцию
            sha256_append(&sha, password, strlen(password));

            // Завершение хэширования
            sha256_finalize_hex(&sha, hash_hex);

            // Проверка совпадения хэшей
            if (strcmp(savedHash, hash_hex) == 0) {
                isValidLogin = 1;
                break;
            }
        }
    }

    fclose(file);

    if (isValidLogin) {
        printf("Вход выполнен успешно.\n");
        // Вызов функции для работы с панелью администратора
    } else {
        printf("Ошибка входа. Проверьте логин и пароль.\n");
        // Запрос на повторный ввод логина и пароля
        loginAdmin();
    }
}

void loginAdmin() {
    char login[100];
    char password[100];

    printf("Введите логин: ");
    scanf("%s", login);

    printf("Введите пароль: ");
    scanf("%s", password);

    loginCheck(login, password);
}

void registrationInfo() {
    struct adminData* adminData = malloc(sizeof(struct adminData));
    printf("Создайте логин: (логин должен быть более 8 символов)\n");
    adminData->login = malloc(100);  // Выделение памяти для строки name
    scanf("%s", adminData->login);

    printf("Придумайте пароль: (пароль должен быть более 8 символов)\n");
    adminData->password = malloc(100);  // Выделение памяти для строки name
    scanf("%s", adminData->password);

    printf("Введите уникальный код: \n");
    adminData->code = malloc(100); //выделение памяти для кода
    scanf("%s", adminData->code);

    // Открытие файла с кодами для чтения
    FILE *codeFile = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\code.txt", "r");
    if (codeFile == NULL) {
        printf("Ошибка открытия файла с кодами.\n");
        return;
    }

    char code[100];
    int isValidCode = 0;

    // Считывание кодов из файла и сравнение с введенным кодом
    while (fgets(code, sizeof(code), codeFile) != NULL) {
        // Удаление символа новой строки из считанной строки
        code[strcspn(code, "\n")] = '\0';

        if ((strcmp(adminData->code, code) == 0) && (strlen(adminData->login) > 8) && (strlen(adminData->password) > 8)) {
            isValidCode = 1;
            break;
        }
    }

    // Закрытие файла с кодами
    fclose(codeFile);

    if (isValidCode) {
        registrationAdmin(adminData->password, adminData->login, adminData->code);
    } else {
        printf("%s %s %s",adminData->password, adminData->login, adminData->code);
        printf("Ошибка верификации, проверьте вводимые данные\n");
        registrationInfo();
    }

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
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\Structure_data\\adminData.txt", "a");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    // Запись хэша в файл
    fprintf(file, "%s %s\n", login, hash_hex);

    // Закрытие файла
    fclose(file);

    printf("Регистрация администратора завершена.\n");
    loginAdmin();

}


void startAdminPanel(){
    ClearConsole();
    printf("Добрый день, вы являетесь админом или только присоединились к команде? \n(1-являюсь) \n(2-не являюсь)");
    int confirm;
    scanf("%d", &confirm);
    switch (confirm) {
        case 1:
            ClearConsole();
            printf("------------------------------------------------ ВХОД В УЧЁТНУЮ ЗАПИСЬ ------------------------------------------------\n");
            loginAdmin();
            break;
        case 2:
            ClearConsole();
            printf("------------------------------------------------ РЕГИСТРАЦИЯ НОВОГО АДМИНА ---------------------------------------------\n");
            registrationInfo();
            break;
        default:
            printf("Неверный ввод!\n");
            break;
    }
}