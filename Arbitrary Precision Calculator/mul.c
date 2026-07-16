#include"apc.h"


status mul(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR)
{
  
    int pos=0; //for adding trailing zeros for more than one digit number

    Dlist*headRT=NULL;
    Dlist*tailRT=NULL;
    Dlist*headT=NULL;
    Dlist*tailT=NULL;
           
        
    while(tail2!=NULL)
    {

  
        do_mul(head1,tail1,tail2->data,&headT,&tailT,pos);
        pos++;
     
        add(headT,*headR,tailT,*tailR,&tailRT,&headRT);
        
        tail2= tail2->prev;

      
  
        
         delet_list(tailR,headR);
         *headR=headRT;
         *tailR=tailRT;
         headRT=NULL;
         tailRT=NULL;

         delet_list(&tailT,&headT);
    
    }

    return success;

}

status do_mul(Dlist*head1,Dlist*tail1,int data,Dlist**headT,Dlist**tailT,int pos)
{


    int carry=0;
    int res=0;

    while(pos>0)
    {
        if(result_Dlist(headT,tailT,0));
        pos--;
    }


    while(tail1!=NULL)
    {   

        
        res=(tail1->data*data)+carry;
        //printf("%d ",sum);
        if(res>9)
        {
            carry=res/10;
            res=res%10;
        
        }
        else
        {
            carry=0;
        }
    
        if(result_Dlist(headT,tailT,res))
        {
            return failure;
        }

        tail1=tail1->prev;
    
    }

    if(carry==1)
    {
        if(result_Dlist(headT,tailT,carry))
        {
            return failure;
        }
    }


        return success;
}