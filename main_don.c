#include <stdio.h>
#include <string.h>
#include "donation.h"

int main()
{
    struct DonationSheet sheet1 = {1, 123456, 1, 'A', 20231107, 1, "No health issues"};
    struct DonationSheet sheet2 = {2, 789012, 2, 'B', 20231108, 0, "High blood pressure"};

    int result = addDonationSheet("donation.txt", sheet1);

    if (result == 1)
        printf("\nDonation sheet added successfully");
    else
        printf("\nFailed to add donation sheet");

    struct DonationSheet newSheet = {3, 456789, 3, 'AB', 20231109, 1, "No health issues"};

    result = modifyDonationSheet("donation.txt", 1, newSheet);

    if (result == 1)
        printf("\nDonation sheet modified successfully");
    else
        printf("\nFailed to modify donation sheet");

    result = removeDonationSheet("donation.txt", 2);

    if (result == 1)
        printf("\nDonation sheet removed successfully");
    else
        printf("\nFailed to remove donation sheet");

    struct DonationSheet foundSheet = searchDonationSheet("donation.txt", 3);

    if (foundSheet.sheet_id == -1)
        printf("\nDonation sheet not found");
    else
        printf("\nDonation sheet found: Sheet ID %d", foundSheet.sheet_id);

    return 0;
}
