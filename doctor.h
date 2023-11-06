#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include <stdio.h>

typedef struct
{
    char CIN[8];
    char Fullname[20];
    char BloodType[20];
    char sign[10];
    char BTC[20];
    int Quantity;
    char DonationID[20];
    int Cases[4];
} doctor;

int add(char *filename, doctor d);
int modify(char *filename, char DonationID[], doctor nouv);
int Delete(char *filename, char DonationID[]);
doctor search(char *filename, char DonationID[]);
int isNumerical(const char *input);
int isAlphabetic(const char *input);

#endif // DOCTOR_H_INCLUDED

