#ifndef BTC_H_INCLUDED
#define BTC_H_INCLUDED
#include <stdio.h>
#include <string.h>
typedef struct
{
        char ID[20];
 	char Region[20];
	int Type;
        char Mail[50];
        char Phone[8];
        char Adress[50];
	int capacity;
        int Options[2];
        int Equipements[2];
} btc;
int is_numeric(const char *chaine);
int isAllNonDigits( const char *str);
int Add(char *filename, char *ID, btc b);
int Modify(char *filename, char *ID, btc New);
int Delete(char *filename, char *ID);
btc Search(char *filename, char *ID);


#endif // BTC_H_INCLUDED

