#include<stdio.h>
#include "mp3.h"
#include<string.h>
status check_operation(char * argv[])
{
    if((strcmp(argv[1],"-v"))==0)
    {
        return view;
    }
    else if((strcmp(argv[1],"-e"))==0)
    {
        return edit;
    }
    else
    {
        return unsupported;
    }
}

//validate the file name and store it file name
status valid_file_name(char *argv[],content *mp3_data)
{
   // printf("INFO: Validating file name\n");
    char * extn_ptr;
    if(!strcmp(argv[1],"-v"))
    {
    extn_ptr=strstr(argv[2],".mp3");
    if(extn_ptr==NULL)
    {
        printf("ERROR: Invalid File name\n");
        return failure;
    }
    int cmp=strcmp(extn_ptr,".mp3");
    if(cmp!=0)
    {
        printf("ERROR: Invalid File name\n");
        return failure;
    }


    strcpy(mp3_data->file_name,argv[2]);
    

            mp3_data->fptr_src=fopen(mp3_data->file_name,"r+");

            if(mp3_data->fptr_src==NULL)
            {
               printf("ERROR: File is Empty or not available\n");
                return failure;
            }
    
    }
    else
    {
        //validation of file name for editing


        extn_ptr=strstr(argv[4],".mp3");
         if(extn_ptr==NULL)
    {
        printf("ERROR: Invalid File name\n");
        return failure;
    }
    int cmp=strcmp(".mp3",extn_ptr);
  
    if(cmp!=0)
    {
        printf("ERROR: Invalid file name\n");
    
        return failure;
    }

    strcpy(mp3_data->file_name,argv[4]);

  
    //validation the fram TAG
     char *edit_opt[]={"-t","-a","-A","-m","-c","-y"};
    int flag=1;
    for(int i=0;i<6;i++)
    {
        flag=strcmp(edit_opt[i],argv[2]);
        if(flag==0)
        {
            break;
        }
    }
        if(flag)
        {
            printf("ERROR: Invalid tag command\n"); 
            return failure;
        }
        
    
        
        
            mp3_data->fptr_src=fopen(mp3_data->file_name,"r+");

            if(mp3_data->fptr_src==NULL)
            {
               printf("ERROR: File is empty or not available\n");
    
                return failure;
            }


  
    }


    return success;
}

status view_tag(content * mp3_data)
{
    
    mp3_data->frame_head[4]='\0';
    mp3_data->frame_size=0;

    // validation of version
    if(valid_version(mp3_data))
    {
        return failure;
    }

    //reading title of song
   
    if(read_TIT2(mp3_data))
    {
        return failure;
    }

    //reading Artist name
    if(read_TPE1(mp3_data))
    {
         return failure;
    }

    //reading Album name
    if(read_TALB(mp3_data))
    {
         return failure;
    }

    //reading year of production
    if(read_TYER(mp3_data))
    {
         return failure;
    }

    //reading Song type
    if(read_TCON(mp3_data))
    {
        return failure;
    }

    //read Composer
    if(read_TCOM(mp3_data))
    {
         return failure;
    }

    printf("------------------------------------Selected view details-------------------------------------\n");
    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
     printf("                           MP3 tag reader and editor for ID3v3\n");
      printf("----------------------------------------------------------------------------------------------\n");
   
             printf("                  Title      :       %s\n",mp3_data->TIT2+ENOCDE_BYTE);
             printf("                  Artist     :       %s\n",mp3_data->TPE1+ENOCDE_BYTE);
             printf("                  Album      :       %s\n",mp3_data->TALB+ENOCDE_BYTE);
             printf("                  Year       :       %s\n",mp3_data->TYER+ENOCDE_BYTE);
             printf("                  Content    :       %s\n" ,mp3_data->TCON+ENOCDE_BYTE);
             printf("                  Composer   :       %s\n",mp3_data->TCOM+ENOCDE_BYTE);
       
    
    printf("----------------------------------------------------------------------------------------------\n");
    printf("----------------------------Details displayed succesfully-------------------------------------\n\n");
        return success;
}