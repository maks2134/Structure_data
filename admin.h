#ifndef PRACTICA_ADMIN_H
#define PRACTICA_ADMIN_H

void startAdminPanel();
void registrationAdmin(const char *password, const char* login, const char* code);
void loginAdmin();
void deleteAdmin();

struct adminData{
    char* login;
    char* password;
    char* code;
};

#endif