#include "btc.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
int i;
/*int isAllNonDigits(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 0; 
        }
        str++;
    }
    return 1; 
}*/

/*int is_numeric(const char *chaine) {
    for (int i = 0; i < strlen(chaine); i++)
    {
        if (!isdigit(chaine[i])) 
	{
            return 0;
        }
    }
    return 1;
}*/

int Add(char *filename, btc b)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
	
	fprintf(f,"%s \n",b.ID);

	fprintf(f,"%s \n",b.Region);

	fprintf(f,"%d \n",b.Type);

	
	fprintf(f,"%s \n",b.Mail);
	

	
	          fprintf(f,"%s \n",b.Phone);
	

	
		 fprintf(f,"%s \n",b.Adress);
	

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

int Modify(char *filename, char ID[], btc New)
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("New.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %s %d %d %d %d %d \n",b.ID ,b.Region ,&b.Type ,b.Mail ,b.Phone ,b.Adress ,&b.capacity ,&b.Options[0] ,&b.Options[1] ,&b.Equipements[0], &b.Equipements[1])!=EOF)
        { 
            if(strcmp(b.ID, ID)== 0)
            {

		fprintf(f2,"%d \n",New.Type);

		
		  fprintf(f2,"%s \n",New.Mail);
		

		
	          fprintf(f2,"%s \n",New.Phone);
	

		
		 fprintf(f2,"%s \n",New.Adress);
		

		fprintf(f2,"%d \n",New.capacity);
		
		for (i = 0; i < 2; i++) {
  		  fprintf(f, "%d \n", New.Options[i]);
			}

		for (i = 0; i < 2; i++) {
   		  fprintf(f, "%d \n", New.Equipements[i]);
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
    rename("New.txt", filename);
    return tr;

}
int Delete(char *filename, char ID[])
{
    int tr=0;
    btc b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("New.txt", "w");
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
    rename("New.txt", filename);
    return tr;
}
btc Search(char *filename, char ID[])
{
    btc b;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %s %s %d %d %d %d %d\n",b.ID ,b.Region ,&b.Type ,b.Mail ,b.Phone ,b.Adress ,&b.capacity ,&b.Options[0] ,&b.Options[1] ,&b.Equipements[0], &b.Equipements[1])!=EOF)
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


