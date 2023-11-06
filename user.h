#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <stdio.h>

struct User {
    char username[50];
    char password[50];
    char confirm_password[50];
    char cin_or_id[50];
    char first_name[50];
    char last_name[50];
    char email[50];
    char phone_number[50];
    char specialization[50];
    int date_of_birth;
    int BTC;
    int employment_status;
    int experience_years;
    int role;
};

int addUser(char *, struct User);
int modifyUser(char *, char *, struct User);
int removeUser(char *, char *);
struct User searchUser(char *, char *);

#endif // USER_H_INCLUDED

