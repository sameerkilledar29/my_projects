#include"apc.h"
int main(int argc,char*argv[])
{
   
    Dlist * head1=NULL;
    Dlist * head2=NULL;
    Dlist * tail1=NULL;
    Dlist * tail2=NULL;
    Dlist * headR=NULL;
    Dlist * tailR=NULL;
   int sign[]={0,0,0};
   int rsign=0;
   int L1;
   int L2;
    

    if(argc>4||argc<4)
    {
      
        printf("ERROR: Invalid command line arguments pass like\n"
            "<operand1> <operator>('+' / '-' / 'x' / '/') <operand2>\n");
        return failure;
    }

    if(valid_argv(argv,&head1,&head2,&tail1,&tail2,sign,&L1,&L2))
    {
        
        return failure;
    }

    switch (argv[2][0])
    {
             //calling Adddition
      case '+':
      {
      
          if(sign[0]==0&&sign[1]==0)
          {
              if(add(head1,head2,tail1,tail2,&tailR,&headR))
              return failure;
              
          }
          else if(sign[0]==1&&sign[1]==1)
          {
              int cmp=campare(head1,head2,L1,L2);
            if(cmp==-1)
            {
              if(add(head2,head1,tail2,tail1,&tailR,&headR))
              return failure;

              rsign=1;
            }
            else if(cmp==1||cmp==0)
            {
              if(add(head1,head2,tail1,tail2,&tailR,&headR))
              return failure;

              rsign=0;
            }
          }
          else if((sign[0]^sign[1]))
          {
          
              int cmp=campare(head1,head2,L1,L2);
            if(cmp==-1)
            {
              if(sub(head2,head1,tail2,tail1,&tailR,&headR))
              return failure;
              rsign=1;
            }
            else if(cmp==1)
            {
              if(sub(head1,head2,tail1,tail2,&tailR,&headR))
              return failure;
              rsign=0;
            }
            else
            {
              if(sub(head1,head2,tail1,tail2,&tailR,&headR))
              return failure;
              rsign=3;
            }
          }

      }
      break;
        
        
          //calling Substraction
      case '-':
      {
          if(sign[0]==0&&sign[1]==0)
          {
              int cmp=campare(head1,head2,L1,L2);
              if(cmp==1)
              {
                if(sub(head1,head2,tail1,tail2,&tailR,&headR))
                {
                return failure;
                }
                rsign=0;
              }
              else if(cmp==-1)
              {
                if(sub(head2,head1,tail2,tail1,&tailR,&headR))
                {
                return failure;
                }
                sign[1]=1;
                rsign=1;
              }
              else
              {
                if(sub(head2,head1,tail2,tail1,&tailR,&headR))
                {
                return failure;
                }
                rsign=3;
              }
            }
          else if(sign[0]==1&&sign[1]==1)
            {
                /// printf("%d %d",sign[0],sign[1]);
              int cmp=campare(head1,head2,L1,L2);
              if(cmp==-1)
              {
                if(sub(head2,head1,tail2,tail1,&tailR,&headR))
                return failure; 
                rsign=3;
              }
              else if(cmp==1||cmp==0)
              {
                if(sub(head1,head2,tail1,tail2,&tailR,&headR))
                return failure;
                if(cmp==1)
                rsign=1;
                else
                rsign=3;
              }
            }
            else if((sign[0]^sign[1]))
            {
          
              int cmp=campare(head1,head2,L1,L2);
              if(cmp==-1)
              {
                if(add(head2,head1,tail2,tail1,&tailR,&headR))
                return failure;
                if(sign[0]==1)
                rsign=0;
                else
                rsign=3;

              }
              else if(cmp==1)
              {
                if(add(head1,head2,tail1,tail2,&tailR,&headR))
                return failure;
                if(sign[0]==1)
                rsign=0;
                else
                rsign=3 ;
              }
              else
              {
                
                if(add(head1,head2,tail1,tail2,&tailR,&headR))
                return failure;
                if(sign[0]==1)
                rsign=0;
                else
                rsign=3;

              }
            }

      }
      break;
      
      case 'x':
        {
            if(sign[0]==0 &&sign[1]==0)
            {
                int cmp=campare(head1,head2,L1,L2);
                if(cmp==1)
                {
                if(mul(head1,head2,tail1,tail2,&tailR,&headR))
                {
                return failure;
                }
                rsign=3;
              }
              else if(cmp==-1)
              {
                if(mul(head2,head1,tail2,tail1,&tailR,&headR))
                {
                return failure;
                }
                rsign=3;
              }
              else
              {
                if(mul(head2,head1,tail2,tail1,&tailR,&headR))
                {
                return failure;
                }
                rsign=3;
              }
            }
            else if(sign[0]==1&&sign[1]==1)
            {
              /// printf("%d %d",sign[0],sign[1]);
              int cmp=campare(head1,head2,L1,L2);
              if(cmp==-1)
              {
                if(mul(head2,head1,tail2,tail1,&tailR,&headR))
                return failure;
                rsign=3;
              }
              else if(cmp==1||cmp==0)
              {
                if(mul(head1,head2,tail1,tail2,&tailR,&headR))
                return failure;
                rsign=3;
              }
            }
            else if((sign[0]^sign[1]))
            {
          
                int cmp=campare(head1,head2,L1,L2);
                if(cmp==-1)
                {
                  if(mul(head2,head1,tail2,tail1,&tailR,&headR))
                  return failure;
                  if(sign[0]==1)
                  rsign=0;
                  else
                  rsign=1;

                }
                else if(cmp==1)
                {
                  if(mul(head1,head2,tail1,tail2,&tailR,&headR))
                  return failure;
                  if(sign[0]==1)
                  rsign=0;
                  else
                  rsign=1 ;
                }
                else
                {
                
                if(mul(head1,head2,tail1,tail2,&tailR,&headR))
                  return failure;
                if(sign[0]==1)
                rsign=0;
                else
                rsign=1;

                }
              }

      }
      break;

      case '/':
        {
            if(sign[0]==0 &&sign[1]==0)
            {
                
                if(divd(head1,head2,tail1,tail2,&tailR,&headR,L1,L2))
                return failure;
                rsign=3;
            }
            else if(sign[0]==1&&sign[1]==1)
            {

             if(divd(head1,head2,tail1,tail2,&tailR,&headR,L1,L2))
             return failure;
                rsign=3;

            }
          else if((sign[0]^sign[1]))
            {
              if(divd(head1,head2,tail1,tail2,&tailR,&headR,L1,L2))
              return failure;
            
              if(sign[0]==1)
              rsign=0;
              else
              rsign=1;

            }
              
      }
      break;

      default:
        printf("ERROR: Invalid Operator \n");
      break;
      
    } 








     remove_leading_zero(&headR,&tailR);    
     printf("   %s %c %s\n",argv[1],argv[2][0],argv[3]);
   
      printf("Result->: "); 
      if(sign[rsign]==1)
        {
            printf("-");
        }

        if(headR==NULL)
            {
            printf("0");
          return success;  
            }

      while(headR!=NULL)
      {
            
            
            printf("%d",headR->data);
            headR=headR->next;
      }
       printf("\n");

       return success;
}