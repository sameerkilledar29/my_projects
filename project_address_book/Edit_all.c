#include<stdio.h>
#include<string.h>
#include "functions.h"

void edit_all(struct AddressBook *addressBook,int ind)                    //Function for adding new student
{

   // FILE* s_data=fopen("student_data1.txt","a+");

int i=1;
int flag=0;
getchar();


//Enter name and validation of name 
char a[]="a";
while(i)
{
    int flag=0;
printf("Enter the name : ");                                        //user input : Name

scanf("%[^\n]",addressBook->arr[ind].name);
getchar();

char  cpy_name1[100];
char *ptr_name1=cpy_name1;
strcpy(ptr_name1,addressBook->arr[ind].name);
int len =strlen(cpy_name1);
char delim[]=" ";
char * t_name1=strtok(cpy_name1,delim);
char * t_surname1 =strtok(NULL,delim);


if(strtok(NULL,delim)!=NULL)
{
    flag=1;
    goto name_end;   
}

 printf("%s \n",t_name1);
     printf("%s \n",t_surname1);
 int name_len=strlen(t_name1);
int surname_len=strlen(t_surname1);

for(int i=0;i<name_len;i++)
{
    if(t_name1[0]>=65&&t_name1[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_name1[i]>=97&&t_name1[i]<=122)==0)
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
    if(t_surname1[0]>=65&&t_surname1[0]<=90)
    {

        continue;
    }
    else
    {
        flag=1;
        break;
    }

    if((t_surname1[i]>=97&&t_surname1[i]<=122)==0)
    {
        flag=1;
        break;
    }
    
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
scanf("%[^\n]",addressBook->arr[ind].gmail);
getchar();
char cpy_mail1[100];
char * ptr_mail1=cpy_mail1;
strcpy(ptr_mail1,addressBook->arr[ind].gmail);
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



//Enter the location


printf("Enter the location : ");                               //user input home address
scanf("%[^\n]",addressBook->arr[ind].add);
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


}
