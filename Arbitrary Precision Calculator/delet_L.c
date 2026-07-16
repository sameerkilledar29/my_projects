#include"apc.h"

status delet_list(Dlist ** head,Dlist ** tail)
{
    if((*head)==NULL)
    {
        return success;
    }

    Dlist* temp;

    while(*tail!=NULL)
    {
        temp=*tail;
         (*tail)->next=NULL;
        *tail=(*tail)->prev;
       
        free(temp);
    }
*head=NULL;



  return success;
}