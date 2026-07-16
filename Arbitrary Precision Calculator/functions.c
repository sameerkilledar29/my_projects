#include"apc.h"


status valid_argv(char * argv[],Dlist **head1,Dlist **head2,Dlist ** tail1,Dlist **tail2,int sign[],int *count_l1,int *count_l2)
{

    int i=0;
    *count_l1=0;
    *count_l2=0;
            //validation operator    

    if(argv[2][0]!='+' && argv[2][0]!='-' && argv[2][0]!='x' && argv[2][0]!='/')
    {
        printf("ERROR: Invalid operator pass operator as per given below\n"
                "./a.out <operand1> + <operand2> --->Addition\n"
                "./a.out <operand1> - <operand2> --->Substraction\n"
            "./a.out <operand1> x <operand2> --->Multiplication\n"
        "./a.out <operand1> / <operand2> --->Division\n");
        return failure;
    }


    //validation of head1/1st operand and reading the list
    
    int flag=0;
    while(argv[1][i]!='\0')
    {
        if((argv[1][i]-'0'>=0&&argv[1][i]-'0'<=9)||(argv[1][i]=='-'||argv[1][i]=='+'))
        {   
            if(argv[1][i]=='-'&&i==0)
            {
                sign[0]=1;
                i++;
                continue;
            }
            else if(argv[1][i]=='+')
            {
             i++;
              continue;
            }

         
            int data=(argv[1][i]-'0'); 
            if(data == 0  && flag==0)
            {
                i++;
                continue;
            }
            else flag=1;


             if(read_Dlist(head1,tail1,data))
             {
                return failure;
             }
             (*count_l1)++;
         }
        else
        {
            printf("ERROR: Invalid operands please pass only digits as operand\n");
            return failure;
        }
        i++;
    }

        //validation of head1/1st operand and reading the list
    flag=0;
    i=0;
     while(argv[3][i]!='\0')
    {
      

        if((argv[3][i]-'0'>=0&&argv[3][i]-'0'<=9)||(argv[3][i]=='-'||argv[3][i]=='+'))
        {   

            if(argv[3][i]=='-'&&i==0)
            {
            sign[1]=1;
            i++;
            continue;
            }
        else if(argv[3][i]=='+')
            {
             i++; 
             continue;
            }

            
            int data=(argv[3][i]-'0'); 
            
            if(data == 0  && flag==0)
            {
                i++;
                continue;
            }
            else flag=1;

             if(read_Dlist(head2,tail2,data))
             {
                return failure;
             }
             
        (*count_l2)++;
         }
        else
        {
            printf("ERROR: Invalid operands please pass only digits as operand\n");
            
            return failure;
        }
        i++;
    }

    return success;
 }



 //function to read the list insert last;
status read_Dlist(Dlist **head,Dlist **tail,int data)
{

    if(*head==NULL)
    {
            
        if(data==0)
        {
            return success;
        }

            Dlist *new=malloc(sizeof(Dlist));
            if(new==NULL)
            {
                return failure;
            }
            new->data=data;
            new->next=NULL;
            new->prev=NULL;
            *head=new;
            *tail=new;
            return success;
    }

    
     Dlist *new=malloc(sizeof(Dlist));
     if(new==NULL)
        {
            return failure;
        }   
        new->data=data;
        new->next=NULL;
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;

        return success;

}


//reading the nodes for result list inset first
status result_Dlist(Dlist ** headR,Dlist** tailR,int data)
{

    
    if(*headR==NULL)
    {
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            printf("ERROR: Node is empty\n");
            return failure;
        }
        
    
        new->data=data;
        new->next=NULL;
        new->prev=NULL;
        *headR=new;
        *tailR=new;
        return success;
    }

    
     Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL)
        {
            printf("ERROR: Node is empty\n");
            return failure;
        }   
         new->data=data;
        new->next=*headR;
        new->prev=NULL;
        (*headR)->prev=new;
        *headR=new; 

            return success;

}
   

//function to campare the two lists to get largest number
int campare(Dlist*head1,Dlist*head2,int l1,int l2)
{

    if(l1>l2)
    {
        return 1;
    }
    else if(l2>l1)
    {
        return -1;
    }
    else
    {

        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->data>head2->data)
            {
                return 1;
            }
            else if(head1->data<head2->data)
            {
                return -1;
            }
            
            head1=head1->next;
            head2=head2->next;
        }

        return success;
    }
}

//function for removing leading zeros
status remove_leading_zero(Dlist**head,Dlist**tail)
{
    if(*head==NULL)
    {
        return failure;
    }

    Dlist*temp=*head;

    int flag=0;
    while(temp!=NULL)
    {
        
        if(temp->data==0&&flag==0)
        {
            if((temp==*tail && temp->data==0))
            {
                *head=temp;
                (*head)->prev=NULL;
                return success;
            }
            *head=(*head)->next;
            (*head)->prev=NULL;
            free(temp);
        }
        else flag=1;
        temp=*head;


          if(flag==1)
        {
         return success;
        }
    }
return success;
}