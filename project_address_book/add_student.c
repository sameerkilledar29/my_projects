#include<stdio.h>
#include<string.h>
#include "functions.h"

void add_contact(struct AddressBook *addressBook)                    //Function for adding new student
{


    
int i=1;
int flag=0;
getchar();

while(i)
{
//Enter name and validation of name 
 i=1;
while(i)
{
    int flag=0;
printf("Enter name and surname only: ");                                        //user input : Name
scanf("%[^\n]",addressBook->arr[addressBook->size].name);
getchar();

char cpy_name[100];
char * ptr_name=cpy_name;
strcpy(ptr_name,addressBook->arr[addressBook->size].name);
char * t_name;
char * t_surname;
char delim[]=" ";

t_name=strtok(cpy_name,delim);
t_surname =strtok(NULL,delim);
//printf("%s %s %s",strstr(cpy_name," "),t_name,t_surname);


if(strtok(NULL,delim)!=NULL)
{
    flag=1;
    goto name_end;   
}
if(t_name !=NULL && t_surname!=NULL)
{

 int name_len=strlen(t_name);
int surname_len=strlen(t_surname);

for(int i=0;i<name_len;i++)
{
    if(t_name[0]>=65&&t_name[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_name[i]>=97&&t_name[i]<=122)==0)
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
    if(t_surname[0]>=65&&t_surname[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_surname[i]>=97&&t_surname[i]<=122)==0)
    {
        flag=1;
        break;
    }
    
}

}
else
{
flag=1;
}


name_end:
if(flag==1)
{
    printf("Invalid input\n");
}
else i=0;

}


//Enter the mail and validation of mail

i=1;

 while(i)
 {
   
flag=0;
 printf("Enter the Gmail : ");                                      //user input name only user name
scanf("%[^\n]",addressBook->arr[addressBook->size].gmail);
getchar();
char cpy_mail[100];
char * ptr_mail=cpy_mail;
strcpy(ptr_mail,addressBook->arr[addressBook->size].gmail);
char * local;
char *domain;

char delim[]="@";

local=strtok(ptr_mail,delim);
domain =strtok(NULL,delim);


if(strtok(NULL,delim)!=NULL)
{
    flag=1;
    goto mail_end;
}

if(local!=NULL && domain!=NULL)
{

 int local_len=strlen(local);
int domain_len=strlen(domain);                                                                                 //logic for validation
 for(int i=0;i<local_len;i++)
 {
    if(((local[i]>=97&&local[i]<=122)||
    (local[i]>=48 && local[i]<=57) || 
    local[i]=='_' || local[i]=='.'||local[i]=='+'||local[i]=='-') && 
    (local[i]!=' ' &&(local[0]!='.' && local[local_len-1]!='.' )))
    {
     
    }  
    else 
    {
        flag=1;
        goto mail_end;
    }
  

     if(i>0)
        {
            if((local[i]=='.' && local[i-1])=='.')
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
int cnt_dot=0;

 for(int j=0;j<domain_len;j++)
{
     if(((domain[j]>=97&&domain[j]<=122)||
     (domain[j]>=48&&domain[j]<=57)||domain[j]=='.'||domain[j]=='-') &&
     ((domain[0]!='.' && domain[domain_len-1]!='.') &&
    ((domain[0]!='-' && domain[domain_len-1]!='-')&&
    domain[j]!=' ')))
   {

      if(j>0)
      {
        if(domain[j]=='.' && domain[j-1]=='.')
        {
         flag=1;
         break;
         
        }

  
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



}
else
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



//Enter the location


printf("Enter the location : ");                               //user input home address
scanf("%[^\n]",addressBook->arr[addressBook->size].add);
getchar();





                    //user input mobile number and validation of it 
i=1;

while(i)
{
    flag=0;
    printf("Enter mobile number : ");       
scanf("%[^\n]",addressBook->arr[addressBook->size].mob);
getchar();
if(strlen(addressBook->arr[addressBook->size].mob)==10 && digit(addressBook->arr[addressBook->size].mob))                          //logic to validate mobile number
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




 (addressBook->size)++;


 
    if(flag==1)
    {
        i=1;
    }
    else i=0;

}

}
