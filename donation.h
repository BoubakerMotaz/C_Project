#ifndef DONATION_H_INCLUDED
#define DONATION_H_INCLUDED

#include <stdio.h>

struct DonationSheet {
    int sheet_id;        // Donation sheet ID
    int donor_cin;       // Donor's Cin (assuming "Cin" is an ID number)
    int donation_type;   // Donation type (you may use an enumeration for specific types)
    char blood_type;     // Blood type (A, B, AB, O, +/-, etc.)
    int donation_date;   // Donation date (you may use a date structure)
    int health_info;     // Health information
    char disease_entry[100];  // A character array for disease entry, adjust the size as needed
};

int addDonationSheet(char *, struct DonationSheet);
int modifyDonationSheet(char *, int, struct DonationSheet);
int removeDonationSheet(char *, int);
struct DonationSheet searchDonationSheet(char *, int);

#endif // DONATION_H_INCLUDED

