#include "btc.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
int i;
int isAllNonDigits(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 0; 
        }
        str++;
    }
    return 1; 
}
int i;

int is_numeric(const char *chaine) {
    for (int i = 0; i < strlen(chaine); i++)
    {
        if (!isdigit(chaine[i])) 
	{
            return 0;
        }
    }
    return 1;
}

int Add(char *filename, char *ID, btc b)
{
    FILE * f=fopen(filename, "w");
    if(f!=NULL)
    {
	do{
		  fprintf(f,"%s \n",b.ID);
	}while(isAllNonDigits(b.ID)==1);

	fprintf(f,"%s \n",b.Region);

	fprintf(f,"%d \n",b.Type);

	do{
		  fprintf(f,"%s \n",b.Mail);
	}while(isAllNonDigits(b.Mail)==0);

	do{
	          fprintf(f,"%s \n",b.Phone);
	}while(isAllNonDigits(b.Phone)==1);

	do{
		 fprintf(f,"%s \n",b.Adress);
	}while(isAllNonDigits(b.Adress)==0);

	fprintf(f,"%d \n",b.capacity);

	for (i = 0; i < 2; i++) {
    	fprintf(f, "%d \n", b.Options[i]);
	}

	for (i = 0; i < 2; i++) {
	fprintf(f, "%d \n", b.Equipements[i]);
	}

	fclose(f);
        return 1;
    }
    else return 0;
}

int Modify(char *filename, char *ID, btc New)
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("New.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %s %d %d %d %d %d \n",b.ID ,b.Region ,&b.Type ,b.Mail ,b.Phone ,b.Adress ,&b.capacity ,&b.Options[1] ,&b.Options[2] ,&b.Equipements[1], &b.Equipements[2])!=EOF)
        { 
            if(strcmp(b.ID, ID)== 0)
            {

		fprintf(f2,"%d \n",b.Type);

		do{
		  fprintf(f2,"%s \n",New.Mail);
		}while(isAllNonDigits(New.Mail)==1);

		do{
	          fprintf(f2,"%s \n",New.Phone);
		}while(isAllNonDigits(New.Phone)==1);

		do{
		 fprintf(f2,"%s \n",New.Adress);
		}while(isAllNonDigits(New.Adress)==1);

		fprintf(f2,"%d \n",New.capacity);
		
		for (i = 0; i < 2; i++) {
  		  fprintf(f, "%d \n", b.Options[i]);
			}

		for (i = 0; i < 2; i++) {
   		  fprintf(f, "%d \n", b.Equipements[i]);
			}
                tr=1;
            }
            else
                fprintf(f2, "%s %s %d %s %s %s %d %d %d %d %d\n", b.ID, b.Region, b.Type, b.Mail, b.Phone, b.Adress, b.capacity, b.Options[0], b.Options[1], b.Equipements[0], b.Equipements[1]);


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;

}
int Delete(char *filename, char *ID)
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %s %d %d %d %d %d\n",b.ID ,b.Region ,&b.Type ,b.Mail ,b.Phone ,b.Adress ,&b.capacity ,&b.Options[0] ,&b.Options[1] ,&b.Equipements[0], &b.Equipements[1])!=EOF)
        {
            if(strcmp(b.ID, ID)== 0)
                tr=1;
            else
               fprintf(f2, "%s %s %d %s %s %s %d %d %d %d %d\n", b.ID, b.Region, b.Type, b.Mail, b.Phone, b.Adress, b.capacity, b.Options[0], b.Options[1], b.Equipements[0], b.Equipements[1]);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;
}
btc Search(char *filename, char *ID)
{
    btc b;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %s %s %d %d %d %d %d\n",b.ID ,b.Region ,&b.Type ,b.Mail ,b.Phone ,b.Adress ,&b.capacity ,&b.Options[1] ,&b.Options[2] ,&b.Equipements[1], &b.Equipements[2])!=EOF)
        {
            if(strcmp(b.ID, ID)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(b.ID, "");
    return b;

}


