#include<stdio.h>
#include<string.h>
#include "functions.h"


void list_contact(struct AddressBook *addressBook)
{
   printf("%-6s|","Sr.No");
   printf("%-30s|","Name");
   printf("%-30s|","Email");
   printf("%-15s|","Mobile number");
   printf("%-25s|","Address");
   printf("\n");
     
printf("--------------------------------------------------------------------------------------------------------------------\n");

         for(int i=0;i<(addressBook->size);i++)
         {
            int n=i+1;
    
    printf("%-6d|%-30s|%-30s|%-15s|%-25s|\n",n,addressBook->arr[i].name,addressBook->arr[i].gmail,addressBook->arr[i].mob,addressBook->arr[i].add);
       
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    
    }