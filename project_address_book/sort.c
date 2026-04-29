#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"functions.h" 

void sort(struct AddressBook *addressBook)
{

    int opt;
    printf("1. Sort by name\n"
        "2. Sort by E-Mail \n");
      
        
        scanf("%d",&opt);

        switch (opt)
        {
        case 1:
            {
                 for(int i=0;i<addressBook->size;i++)
                {
                    for(int j=0;j<addressBook->size-1-i;j++)
                    {           
          
                        
                        if((strcmp(addressBook->arr[j].name,addressBook->arr[j+1].name))>0)
                        {
                        
                           struct student t;
                           
                           t=addressBook->arr[j];
                            addressBook->arr[j]=addressBook->arr[j+1];
                            addressBook->arr[j+1]=t;
                                
                        }
            

                    }
        
                }
            }
            break;

          
            case 2:
            {
                 for(int i=0;i<addressBook->size;i++)
                {
                    for(int j=0;j<addressBook->size-1-i;j++)
                    {           
          
                        
                        if((strcmp(addressBook->arr[j].gmail,addressBook->arr[j+1].gmail))>0)
                        {
                           struct student t2;
                           
                           t2=addressBook->arr[j];
                            addressBook->arr[j]=addressBook->arr[j+1];
                            addressBook->arr[j+1]=t2;
            

                        }
        
                    }
                 }
            }
            break;
        
            default:
            {
            printf("Invalid Input!!");
            }
            
            }


    }

