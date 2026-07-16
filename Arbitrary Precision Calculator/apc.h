#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node
{

  int data;
  struct node *next;
 struct node *prev;


}Dlist;

typedef enum status_
{
    success,
    failure
}status; 

status valid_argv(char * argv[],Dlist **head1,Dlist **head2,Dlist ** tail1,Dlist **tail2,int sign[],int *count_l1,int *count_l2);
status read_Dlist(Dlist **head,Dlist ** tail,int data);
status add(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR);
status sub(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR);
status mul(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR);
status divd(Dlist*head1,Dlist*head2,Dlist*tail1,Dlist*tail2,Dlist**tailR,Dlist**headR,int l1,int l2);
status do_mul(Dlist*head1,Dlist*tail1,int data,Dlist**headR,Dlist**tailR,int pos);
status result_Dlist(Dlist **  headR,Dlist** tailR,int data);
 int campare(Dlist*head1,Dlist*head2,int l1,int l2);  
status delet_list(Dlist ** head,Dlist ** tail);
status remove_leading_zero(Dlist**head,Dlist**tail);

#endif
