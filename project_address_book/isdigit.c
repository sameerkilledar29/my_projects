#include<stdio.h>
#include<string.h>
#include "functions.h"
int flag=0;
int digit(char * mob)
{
for(int i=0;i<10;i++)
{
if((mob[i])>=48 && (mob[i])<=57)
{
    flag=0;
    
}
else
{
flag=1;
break;
}
}

if(flag==1)
{
    return 0;
}
else 
return 1;

}