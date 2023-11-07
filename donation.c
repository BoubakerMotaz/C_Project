#include <stdio.h>
#include <string.h>
#include "donation.h"

int addDonationSheet(char *filename, struct DonationSheet sheet)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%d %d %d %c %d %d %s\n",
                sheet.sheet_id, sheet.donor_cin, sheet.donation_type, sheet.blood_type, sheet.donation_date, sheet.health_info, sheet.disease_entry);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifyDonationSheet(char *filename, int sheet_id, struct DonationSheet newSheet)
{
    int found = 0;
    struct DonationSheet sheet;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %d %c %d %d %99[^\n]\n",
                     &sheet.sheet_id, &sheet.donor_cin, &sheet.donation_type, &sheet.blood_type, &sheet.donation_date, &sheet.health_info, sheet.disease_entry) != EOF)
        {
            if (sheet.sheet_id == sheet_id)
            {
                fprintf(f2, "%d %d %d %c %d %d %s\n",
                        newSheet.sheet_id, newSheet.donor_cin, newSheet.donation_type, newSheet.blood_type, newSheet.donation_date, newSheet.health_info, newSheet.disease_entry);
                found = 1;
            }
            else
            {
                fprintf(f2, "%d %d %d %c %d %d %s\n",
                        sheet.sheet_id, sheet.donor_cin, sheet.donation_type, sheet.blood_type, sheet.donation_date, sheet.health_info, sheet.disease_entry);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return found;
}

int removeDonationSheet(char *filename, int sheet_id)
{
    int found = 0;
    struct DonationSheet sheet;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %d %c %d %d %99[^\n]\n",
                     &sheet.sheet_id, &sheet.donor_cin, &sheet.donation_type, &sheet.blood_type, &sheet.donation_date, &sheet.health_info, sheet.disease_entry) != EOF)
        {
            if (sheet.sheet_id != sheet_id)
            {
                fprintf(f2, "%d %d %d %c %d %d %s\n",
                        sheet.sheet_id, sheet.donor_cin, sheet.donation_type, sheet.blood_type, sheet.donation_date, sheet.health_info, sheet.disease_entry);
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

struct DonationSheet searchDonationSheet(char *filename, int sheet_id)
{
    struct DonationSheet sheet;
    int found = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%d %d %d %c %d %d %99[^\n]\n",
                     &sheet.sheet_id, &sheet.donor_cin, &sheet.donation_type, &sheet.blood_type, &sheet.donation_date, &sheet.health_info, sheet.disease_entry) != EOF)
        {
            if (sheet.sheet_id == sheet_id)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(f);
    if (found == 0)
    {
        sheet.sheet_id = -1; // Indicates not found
    }
    return sheet;
}
