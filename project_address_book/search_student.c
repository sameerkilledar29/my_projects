#include<stdio.h>
#include<string.h>
#include "functions.h"


int search_contact(struct AddressBook *addressBook)
{
    int k=1,ind;
    while(k)
    {
    printf("Select search by option\n");
    printf("1. Search by Name\n"
    "2. Search by Mobile number\n"
    "3. Search by Email\n");

    int opt,flag=0,count=0 ;
    scanf("%d",&opt);
    getchar();

    switch(opt)
    {
        case 1:
        {
            do
            {
                count=0,flag=0;
            printf("Enter the Name to search\n");
          
            char name_search[50];
            scanf("%[^\n]",name_search);
            getchar();

               
            
            for(int i=0;i<addressBook->size;i++)
            {
              
            char* ptr_name;
            ptr_name=strstr((addressBook->arr[i].name),name_search);
          
                if(ptr_name!=NULL)
                {
                    if(i<1)
                    {
                    printf("Contact Found!!\n");
                    }
                    printf("----------------------------------------------------------------\n");
                    printf("%s, ",addressBook->arr[i].name);
                    
                    printf("%s, ",addressBook->arr[i].mob);
                    
                    printf("%s, ",addressBook->arr[i].gmail);
                    
                    printf("%s\n",addressBook->arr[i].add);
                    
                    printf("-----------------------------------------------------------------\n");
                    ind=i;
                    count++;
                }
                else
                {
                    flag++;
                    
                 }
             }

            if(flag==addressBook->size)
            {
                printf("Contact not found\n");
                
            }

            if(count>1)
            {
                printf("Similar names found please enter full name\n");
            }
       

            }while(count>1);

          
        }
        break;

        case 2:
        {
            
            do
            {
                count=0,flag=0;
            printf("Enter the Mobile number to search\n");
            char mob_search[50];
            scanf("%[^\n]",mob_search);
            getchar();

            
                printf("\n");

            for(int i=0;i<addressBook->size;i++)
            {
               // printf("%s",arr[i].name);
            char* ptr_name =strstr((addressBook->arr[i].mob),mob_search);
                if(ptr_name!=NULL)
                {
                      if(i<1)
                    {
                    printf("Contact Found!!\n");
                    }
                   printf("-----------------------------------------------------------------\n"); 
                    printf("%s, ",addressBook->arr[i].name);
                    
                    printf("%s, ",addressBook->arr[i].mob);
                    
                    printf("%s, ",addressBook->arr[i].gmail);
                    
                    printf("%s\n",addressBook->arr[i].add);
                    
                    printf("-----------------------------------------------------------------\n");
                    ind=i;
                    count++;
                }
                else
                {
                    flag++;
                    
                 }
                }

                  if(flag==addressBook->size)
                    {
                    printf("Contact not found\n");
                    }
                    
                   if(count>1)
                     {
                        printf("Similar names found please enter full name\n");
                     }

                }while(count>1);

                
               
                    
        
        }
        break;

        
        case 3:
        {
           do
           {
            count=0,flag=0;
            printf("Enter the Email ID to search\n");
            char mail_search[50];
            scanf("%[^\n]",mail_search);
            getchar();

            
                printf("\n");

            for(int i=0;i<addressBook->size;i++)
            {
               // printf("%s",arr[i].name);
            char* ptr_name =strstr((addressBook->arr[i].gmail),mail_search);
                if(ptr_name!=NULL)
                {
                      if(i<1)
                    {
                    printf("Contact Found!!\n");
                    }
                    printf("-----------------------------------------------------------------\n");
                    printf("%s, ",addressBook->arr[i].name);
                    
                    printf("%s, ",addressBook->arr[i].mob);
                    
                    printf("%s, ",addressBook->arr[i].gmail);
                    
                    printf("%s\n",addressBook->arr[i].add);
                    
                   printf("-----------------------------------------------------------------\n"); ind=i;
                    
                   count++;
                }
                else
                {
                    flag++;
                    
                 }
             }
            if(flag==addressBook->size)
            {
                printf("Contact not found\n");
                
            }

               if(count>1)
            {
                printf("Similar names found please enter full name\n");
            }
       

            }while(count>1);
            
            
               
        
        }
        break;



 
    }
    if(count==1)
    {
        k=0;
    }
        
    }
    
    return ind;
}

