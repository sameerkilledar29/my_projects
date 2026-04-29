#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_name(struct AddressBook *addressBook,int ind)                    //Function for adding new student
{

   // FILE* s_data=fopen("student_data1.txt","a+");

int i=1;
int flag=0;
getchar();


//Enter name and validation of name 
while(i)
{
    int flag=0;
printf("Enter the name : ");                                        //user input : Name

scanf("%[^\n]",addressBook->arr[ind].name);
getchar();

char * cpy_name1;
strcpy(cpy_name1,addressBook->arr[ind].name);
int len =strlen(cpy_name1);
char delim[]=" ";
char * t_name1=strtok(cpy_name1,delim);
char * t_surname1 =strtok(NULL,delim);


if(strtok(NULL,delim)!=NULL)
{
    flag=1;
    goto name_end;   
}

 int name_len=strlen(t_name1);
int surname_len=strlen(t_surname1);

for(int i=0;i<name_len;i++)
{
    if(t_name1[0]>=65&&t_name1[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_name1[i]>=97&&t_name1[i]<=122)==0)
    {
        flag=1;
        break;
    }
    
}

if(flag==1)
{
    goto name_end;
}


for(int i=0;i<surname_len;i++)
{
    if(t_surname1[0]>=65&&t_surname1[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_surname1[i]>=97&&t_surname1[i]<=122)==0)
    {
        flag=1;
        break;
    }
    
}



name_end:
if(flag==1)
{
    printf("Invalid input\n");
}
else i=0;

}

}