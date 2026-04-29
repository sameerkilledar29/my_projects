#include<stdio.h>
#include<string.h>
#include "functions.h"

int main()
{

    int i=1 ,opt,flag=0;
    struct AddressBook addressBook;
    
        
    FILE * s_data=fopen("student_data1.csv","r+");
    

    int ch;
    fscanf(s_data,"%d",&ch);
    if(s_data!=NULL)
    {

       if(ch)
        {
            rewind(s_data);
            fscanf(s_data,"%d\n",&addressBook.size);
            
            for(int i=0;i<addressBook.size;i++)
            {
                fscanf(s_data,"%[^,],",addressBook.arr[i].name);
                fscanf(s_data,"%[^,],",addressBook.arr[i].add);
                fscanf(s_data,"%[^,],",addressBook.arr[i].gmail);
                fscanf(s_data,"%[^\n]\n",addressBook.arr[i].mob);

            }
 

        }
        else
         addressBook.size=0;
        
       fclose(s_data);
        
    while(i)
    {
        printf("Please select below options\n");
        printf("1. Add new studen\n" 
            "2. Edit Student\n"
            "3. Delet Student\n"
            "4. Search Student\n"
            "5. Print all students\n"
            "6. Sort Contacts\n"
            "7. Save changes\n"
            "8. Exit\n");
            scanf("%d",&opt);

            switch(opt)
            {
                case 1:
                {
                    add_contact(&addressBook);
                    printf("Contact Added !!\n");
                
                }
                break;
                
                case 2:
                 edit_contact(&addressBook);
                 printf("Contact Edited !!\n");
                break;

                case 3:
                   delete_contact(&addressBook);
                  
                break;

                case 4:
                    search_contact(&addressBook);
                break;
                
                case 5:
                   list_contact(&addressBook);
                break;

                
                case 6:
                {

                    sort(&addressBook);
                    printf("Contacts Sorting Succeffully!!\n");
                }
                break;

                case 7:
                    {
                        int opt4;

                        printf("1. Yes\n"
                            "2. NO\n");
                            scanf("%d",&opt4);

                        switch (opt4)
                        {
                            case 1:
                            {
                            FILE * s_data=fopen("student_data1.csv","w+");
                             fprintf(s_data,"%d\n",addressBook.size);
    
                              for(int i=0;i<addressBook.size;i++)
                            {
                                                            
                            if(i==0)
                             {
                            fprintf(s_data,"\n");

                             }

                                fprintf(s_data,"%s,",addressBook.arr[i].name);
                                fprintf(s_data,"%s,",addressBook.arr[i].add);
                                fprintf(s_data,"%s,",addressBook.arr[i].gmail);
                                fprintf(s_data,"%s\n",addressBook.arr[i].mob);
                             }

                                fclose(s_data);
                        
                                 printf("Changes Saved\n");
                             }
                             break;

                             case 2:
                             {
                                i=1;
                             }
                        }
                    }
                break;

                case 8:
                {
                    int opt2;
                    
                    printf("1. Save & Exit\n"
                           "2. Discard & Exit\n");

                           scanf("%d",&opt2);
                    switch(opt2)
                    {
                        case 1:
                        {
                             s_data=fopen("student_data1.csv","w+");
                             fprintf(s_data,"%d\n",addressBook.size);
    
                              for(int i=0;i<addressBook.size;i++)
                            {
                                                            
                            if(i==0)
                             {
                            fprintf(s_data,"\n");

                             }

                                fprintf(s_data,"%s,",addressBook.arr[i].name);
                                fprintf(s_data,"%s,",addressBook.arr[i].add);
                                fprintf(s_data,"%s,",addressBook.arr[i].gmail);
                                fprintf(s_data,"%s\n",addressBook.arr[i].mob);
                             }

                                fclose(s_data);
                        
                                 printf("Saved\n");
                                flag=1;
                        }
                        break;

                        case 2:
                        {
                            flag=1;
                        }
                        break;

                    }

                }
                break;

                
                default:
                printf("Invalid option Please select valid option ");
            }
            printf("\n");
            
            if(flag==1)
            {
                i=0;
            }
            else i=1;

    }
    printf("Thank you!!!\n");
    


}
else
{
        printf("File not exists");
}



}
