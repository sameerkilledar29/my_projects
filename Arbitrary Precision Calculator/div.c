#include"apc.h"

status divd(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR,int l1,int l2)
{
  int flag=0;
  if(head1==NULL)
  {
    result_Dlist(headR,tailR,0);
    return success;
  }
  else if(head2==NULL)
  {
    printf("ERROR: Cannot divide by Zero '0' \n");
    return failure;
  }
  else if(campare(head1,head2,l1,l2)==0)
  {
    result_Dlist(headR,tailR,1);
    return success;
  }
  else if(campare(head1,head2,l1,l2)==-1)
  {
    result_Dlist(headR,tailR,0);
    return success;
  }

    Dlist*cur_head=NULL;
    Dlist*cur_tail=NULL;
    Dlist*temp_headR=NULL;
    Dlist*temp_tailR=NULL;
    int count=0;
    int cur_len;
    Dlist*temp_cur_head=NULL;
    int cmp=0;

    //logic for division by long division method
    while(head1!=NULL)
    {
        cur_len=0;
        count=0;
        read_Dlist(&cur_head,&cur_tail,head1->data);
        temp_cur_head=cur_head;   
        Dlist* temp=temp_cur_head;
      

        while(temp_cur_head!=NULL)  //to get the lenfth of curent list
        {
          if(cur_head->data==0)
          {
            temp_cur_head=temp_cur_head->next;
            continue;

          }
            cur_len++;
            temp_cur_head=temp_cur_head->next;
        }

              
        //if current list is greater than the divisor than the divided is subtracted till it is lesser than the divisor
        while(((cmp=campare(cur_head,head2,cur_len,l2)))>=0)
          { 
           //logic to repeatedly sub if still current list is greater 
              sub(cur_head,head2,cur_tail,tail2,&temp_tailR,&temp_headR);
              count++;
              remove_leading_zero(&temp_headR,&temp_tailR);
              delet_list(&cur_head,&cur_tail);
              cur_head=temp_headR;
              cur_tail=temp_tailR;
              temp_tailR=NULL;
              temp_headR=NULL;
              cur_len=0;
              temp_cur_head=cur_head;

              while(temp_cur_head!=NULL)
                  {
                      cur_len++;
                      temp_cur_head=temp_cur_head->next;
                    }
                  
                }
              read_Dlist(headR,tailR,count);
              head1=head1->next;
    }    
      


return success;
}
