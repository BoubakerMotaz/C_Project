#include "doctor.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int add(char *filename, doctor d)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %s %s %s %d %s %d %d %d %d \n", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, d.Quantity, d.DonationID, d.Cases[0], d.Cases[1], d.Cases[2], d.Cases[3]);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modify(char *filename, char DonationID[], doctor nouv)
{
    int tr = 0;
    doctor d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %d %s %d %d %d %d", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, &d.Quantity, d.DonationID, &d.Cases[0], &d.Cases[1], &d.Cases[2], &d.Cases[3]) != EOF)
        {
            if (strcmp(d.DonationID, DonationID) == 0)
            {
                fprintf(f2, "%s %s %s %s %s %d %s %d %d %d %d\n", nouv.CIN, nouv.Fullname, nouv.BloodType, nouv.sign, nouv.BTC, nouv.Quantity, nouv.DonationID, nouv.Cases[0], nouv.Cases[1], nouv.Cases[2], nouv.Cases[3]);
                tr = 1;
            }
            else
                fprintf(f2, "%s %s %s %s %s %d %s %d %d %d %d\n", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, d.Quantity, d.DonationID, d.Cases[0], d.Cases[1], d.Cases[2], d.Cases[3]);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int Delete(char *filename, char DonationID[])
{
    int tr = 0;
    doctor d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %d %s %d %d %d %d", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, &d.Quantity, d.DonationID, &d.Cases[0], &d.Cases[1], &d.Cases[2], &d.Cases[3]) != EOF)
        {
            if (strcmp(d.DonationID, DonationID) == 0)
                tr = 1;
            else
                fprintf(f2, "%s %s %s %s %s %d %s %d %d %d %d\n", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, d.Quantity, d.DonationID, d.Cases[0], d.Cases[1], d.Cases[2], d.Cases[3]);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

doctor search(char *filename, char DonationID[]) {
    doctor d;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    
    if (f != NULL) {
        while (tr == 0 && fscanf(f, "%s %s %s %s %s %d %s %d %d %d %d", d.CIN, d.Fullname, d.BloodType, d.sign, d.BTC, &d.Quantity, d.DonationID, &d.Cases[0], &d.Cases[1], &d.Cases[2], &d.Cases[3]) != EOF) {
            if (strcmp(d.DonationID, DonationID) == 0)
                tr = 1;
        }
        fclose(f);
    }

    if (tr == 0) {
        strcpy(d.DonationID, "");
    }
    return d;
}
