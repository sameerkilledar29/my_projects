#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_location(struct AddressBook *addressBook,int ind)                    //Function for adding new student
{

   // FILE* s_data=fopen("student_data1.txt","a+");
printf("Enter the location : ");   
getchar();                            //user input home address
scanf("%[^\n]",addressBook->arr[ind].add);
getchar();

printf("Edited");
}