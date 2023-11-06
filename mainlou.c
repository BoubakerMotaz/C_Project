#include <stdio.h>
#include <string.h>
#include "doctor.h"

int main() {
    doctor d1 = {"123", "louey barouni", "o", 0 , "", "200", "123", {0, 1, 1, 1}};
    doctor d2 = {"111", "lala baba", "b", 1 , "250", "01", {1, 1, 1, 1}};
    doctor d3;

    int x = add("doctor.txt", d1);
    
    if (x == 1) {
        printf("\nAjout du docteur avec succès");
    } else {
        printf("\nÉchec de l'ajout");
    }

    x = modify("doctor.txt", "123", d2);

    if (x == 1) {
        printf("\nModification du docteur avec succès");
    } else {
        printf("\nÉchec de la modification");
    }

    x = Delete("doctor.txt", "123");

    if (x == 1) {
        printf("\nSuppression du docteur avec succès");
    } else {
        printf("\nÉchec de la suppression");
    }

    d3 = search("doctor.txt", "123");

    if (strcmp(d3.DonationID, "") == 0) {
        printf("\n Introuvable\n");
    } else {
        printf("Docteur trouvé: CIN = %s, Fullname = %s\n", d3.CIN, d3.Fullname);
    }

    return 0;
}

