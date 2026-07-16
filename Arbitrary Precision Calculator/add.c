#include"apc.h"


status add(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR)
{
int carry=0;
int sum=0;



while(tail1!=NULL&&tail2!=NULL)
{   
    sum=tail1->data+tail2->data+carry;
    //printf("%d ",sum);
    if(sum>9)
    {
        sum=sum%10;
       carry=1;
    }
    else
    {
        carry=0;
    }
 
   if(result_Dlist(headR,tailR,sum))
   {
    return failure;
   }

   tail1=tail1->prev;
   tail2=tail2->prev;
}


while(tail1!=NULL)
{   
    sum=tail1->data+carry;
  
    if(sum>9)
    {
        sum=sum%10;
        carry=1;
    }
    else
    {
        carry=0;
    }

   if(result_Dlist(headR,tailR,sum))
   {
    return failure;
   }

   tail1=tail1->prev;

}
 

while(tail2!=NULL)
{   
    sum=tail2->data+carry;
  
    if(sum>9)
    {
        sum=sum%10;
        carry=1;
    }
    else
    {
        carry=0;
    }

   if(result_Dlist(headR,tailR,sum))
   {
    return failure;
   }

   tail2=tail2->prev;
}

if(carry==1)
{
      if(result_Dlist(headR,tailR,carry))
   {
    return failure;
   }
}

return success;
}
