#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_mail(struct AddressBook *addressBook,int ind)                    //Function for adding new student
{

   // FILE* s_data=fopen("student_data1.txt","a+");

int i=1;
int flag=0;
getchar();


i=1;

 while(i)
 {
   
flag=0;
 printf("Enter the Gmail : ");                                      //user input name only user name
scanf("%[^\n]",addressBook->arr[ind].gmail);
getchar();
char * cpy_mail1;
strcpy(cpy_mail1,addressBook->arr[ind].gmail);
int len =strlen(cpy_mail1);
char delim[]="@";
char * local1=strtok(cpy_mail1,delim);
char *domain1 =strtok(NULL,delim);


if(strtok(NULL,delim)!=NULL)
{
    flag=1;
    goto mail_end;
}

 printf("%s \n",domain1);
     printf("%s \n",local1);




 int local_len=strlen(local1);
int domain_len=strlen(domain1);

                                                                                 //logic for validation
 for(int i=0;i<local_len;i++)
 {
    if(((local1[i]>=97&&local1[i]<=122)||
    (local1[i]>=48&&local1[i]<=57) || 
    (local1[i]=='_' || local1[i]=='.'||local1[i]=='+',local1[i]=='-')) && 
    (local1[i]!=' ' &&(local1[0]!='.' && local1[local_len-1]!='.' )))
    {
     
    }  
    else 
    {
        flag=1;
        goto mail_end;
    }
  

     if(i>0)
        {
            if((local1[i]=='.' && local1[i-1])=='.')
            {
                flag=1;
                goto mail_end;
            }
        }
        
}

if(flag==1)
{
goto mail_end;
}


 printf("%s %d\n",domain1,domain_len);
     printf("%s %d\n",local1,local_len);
int cnt_dot=0;

 for(int j=0;j<domain_len;j++)
{
     if(((domain1[j]>=97&&domain1[j]<=122)||
     (domain1[j]>=48&&domain1[j]<=57)||domain1[j]=='.'||domain1[j]=='-') &&
     ((domain1[0]!='.' && domain1[domain_len-1]!='.') &&
    ((domain1[0]!='-' && domain1[domain_len-1]!='-')&&
    domain1[j]!=' ')))
   {

      if(j>0)
      {
        if(domain1[j]=='.' && domain1[j-1]=='.')
        {
         flag=1;
         break;
         
        }

  
     }
     
        if(domain1[j]=='.')
        {
            cnt_dot++;
        }
    
    } else
    {
         flag=1;
         goto mail_end; 
    }
}

if(flag==1)
{
    goto mail_end;
}

if(cnt_dot>1 || cnt_dot<1)
{
    flag=1;
    goto mail_end;
}



mail_end:
if(flag==0)
{
    i=0;
}
else
  printf("Invalid Input\n");
 
}

printf("Edited");
}
