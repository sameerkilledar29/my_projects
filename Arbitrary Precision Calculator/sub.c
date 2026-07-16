#include"apc.h"

status sub(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR)
{
int borrow=0;
int diff=0;


while(tail1!=NULL&&tail2!=NULL)
{   
    diff=(tail1->data-borrow)-tail2->data;
   // printf("%d ",diff);
    if(diff<0)
    {
        diff=10+diff;
       borrow=1;
    }
    else
    {
        borrow=0;
    }
 
    if(result_Dlist(headR,tailR,diff))
    {
        return failure;
    }

   tail1=tail1->prev;
   tail2=tail2->prev;
}


while(tail1!=NULL)
{   
    diff=tail1->data-borrow;
  
    if(diff<0)
    {
        diff=10+diff;
        borrow=1;
    }
    else
    {
        borrow=0;
    }

   if(result_Dlist(headR,tailR,diff))
   {
    return failure;
   }

   tail1=tail1->prev;

}
 

while(tail2!=NULL)
{
     diff=tail2->data-borrow;
  
    if(diff<0)
    {
        diff=10+diff;
        borrow=1;
    }
    else
    {
        borrow=0;
    }

   if(result_Dlist(headR,tailR,diff))
   {
    return failure;
   }

   tail2=tail2->prev;

}

return success;
}
