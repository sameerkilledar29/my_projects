#include<stdio.h>
#include<string.h>
#include "functions.h"
void delete_contact(struct AddressBook *addressBook)
{ 
    int opt,flag=0,i=1;
  
printf("Enter Valid Id to delet\n");
int ind = search_contact(addressBook);
while(i)
{
if(ind>=0)
{
printf("1. Delet above Contact\n2. Exit to main Menu\n");
scanf("%d",&opt);
switch (opt)
{
    case 1:
    {
        
            for(int i=ind;i<=(addressBook->size);i++)
            {
                addressBook->arr[i]=addressBook->arr[i+1];

            }

    

    
             printf("Contact Deleted !!\n");

        (addressBook->size)--;

        i=0;
    }
    break;

    case 2:
    {
        printf("Contact not Deleted!!");
        i=0;
    }
    break;

    default:
    printf("Invalid Input");
    
}
}
}
}



