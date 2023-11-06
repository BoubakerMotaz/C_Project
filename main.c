#include <stdio.h>
#include <string.h>
#include "btc.h"

int main()
{
    btc b1= {"34647836","Manouba",1,"manoubabtc@gmail.com","90340111","rue de carthage",5,{0,0},{1,1}},b2= {"34567836","Ariana",2,"arianaabtc@gmail.com","90340112","rue de republic",10,{1,1},{1,0}},b3;
    int x=Add("btc.txt", b1);
    
    if(x==1)
	{
        printf("\n Adding successful");
	}
    else
	{
	printf("\n Error adding");
	}
        
    x=Modify("btc.txt","34567836",b2 );

    if(x==1)
	{
        printf("\n Modification successful");
	}
    else 
	{
	printf("\n Error Modification");
	} 
   
    x=Delete("btc.txt","34647836" );

    if(x==1)
	{
        printf("\n Deleteion successful");
	}
    else 
	{
	printf("\n Error deletion");
	}

    b3=Search("btc.txt","2345678");

    if(strcmp(b3.ID,"") == 0 )
	{
        printf("Not found");
	}

    return 0;
}
