#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_number(struct AddressBook *addressBook,int ind)                    //Function for adding new student
{

   // FILE* s_data=fopen("student_data1.txt","a+");

int i=1;
int flag=0;
getchar();


                    //user input mobile number and validation of it 
i=1;

while(i)
{
    flag=0;
    printf("Enter mobile number : ");       
scanf("%[^\n]",addressBook->arr[ind].mob);
getchar();
if(strlen(addressBook->arr[ind].mob)==10 && digit(addressBook->arr[ind].mob))                          //logic to validate mobile number
{
flag=0;
break;
}
else flag=1;


if(flag==1)
{
    printf("Invalid Mobile number please enter valid mobile number\n");
    
}else i=0;
}

printf("Edited");
}