#include <stdio.h>
#include <string.h>
#include "user.h"


int addUser(char *filename, struct User user)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                user.phone_number, user.specialization, user.date_of_birth, user.BTC, user.employment_status, user.experience_years, user.role);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifyUser(char *filename, char *username, struct User newUserInfo)
{
    int found = 0;
    struct User user;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                     user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                     user.phone_number, user.specialization, &user.date_of_birth, &user.BTC, &user.employment_status, &user.experience_years, &user.role) != EOF)
        {
            if (strcmp(user.username, username) == 0)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                        newUserInfo.username, newUserInfo.password, newUserInfo.confirm_password, newUserInfo.cin_or_id, newUserInfo.first_name, newUserInfo.last_name, newUserInfo.email,
                        newUserInfo.phone_number, newUserInfo.specialization, newUserInfo.date_of_birth, newUserInfo.BTC, newUserInfo.employment_status, newUserInfo.experience_years, newUserInfo.role);
                found = 1;
            }
            else
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                        user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                        user.phone_number, user.specialization, user.date_of_birth, user.BTC, user.employment_status, user.experience_years, user.role);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return found;
}

int removeUser(char *filename, char *username)
{
    int found = 0;
    struct User user;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                     user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                     user.phone_number, user.specialization, &user.date_of_birth, &user.BTC, &user.employment_status, &user.experience_years, &user.role) != EOF)
        {
            if (strcmp(user.username, username) != 0)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                        user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                        user.phone_number, user.specialization, user.date_of_birth, user.BTC, user.employment_status, user.experience_years, user.role);
            }
            else
            {
                found = 1;
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return found;
}

struct User searchUser(char *filename, char *username)
{
    struct User user;
    int found = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %d %d %d %d %d\n",
                     user.username, user.password, user.confirm_password, user.cin_or_id, user.first_name, user.last_name, user.email,
                     user.phone_number, user.specialization, &user.date_of_birth, &user.BTC, &user.employment_status, &user.experience_years, &user.role) != EOF)
        {
            if (strcmp(user.username, username) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(f);
    if (found == 0)
    {
        strcpy(user.username, "Not Found");
    }
    return user;
}
