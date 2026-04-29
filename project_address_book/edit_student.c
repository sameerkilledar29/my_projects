#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_contact(struct AddressBook *addressBook)
{

    int opt,opt2,i=1,flag=0;
    int ind=search_contact(addressBook);

    if(ind>=0)
    {   
        printf("1.Do you want to edit above contact \n2.No\n");
        scanf("%d",&opt);
        switch (opt)
            {
            case 1:
                {

                    printf("Select edit options\n");


                     while(i)
                         {   
                            printf("1.Edit Name\n"
                            "2.Edit E-Mail address\n"
                            "3.Edit Location\n"
                            "4.Edit Mobile number\n"
                            "5.Edit all\n");

                                scanf("%d",&opt2);

                                switch(opt2)
                                {
                                    case 1:
                                    {
                                        edit_name(addressBook,ind);
                                            i=0;
                                    }
                                     break;
            
                                    case 2:
                                    {
                                        edit_mail(addressBook,ind);
                                        i=0;
                                    }
                                    break;
            
                                    case 3:
                                    {
                                        edit_location(addressBook,ind);
                                        i=0;
                                    }
                                    break;
                
                                    case 4:
                                    {
                                        edit_number(addressBook,ind);
                                        i=0;
                                    }
                                    break;
                                    
                                    case 5:
                                    {
                                        edit_all(addressBook,ind);
                                        i=0;
                                    }
                                    break;

                                    default:
                                    {
                                        printf("Invalid input");
                                        i=1;
                                    }

                                    
                                }

                                


                            }
                            
                        
                    }
                    break;

                     case 2:
                        {
                         i=0;
                        }

            }



 
    }

}

