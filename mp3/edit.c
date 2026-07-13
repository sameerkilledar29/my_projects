#include"MP3.h"
status  edit_tag(char* argv[],content *mp3_data)
{
//checking the edit comand aand excecuting
    if(!strcmp(argv[2],"-t"))
    {
        if(edit_TIT2(argv,mp3_data))
        {
           
            return failure;
        }
    }
    else if(!strcmp(argv[2],"-a"))
    {
         if(edit_TPE1(argv,mp3_data))
        {
           
            return failure;
        }
    }
      else if(!strcmp(argv[2],"-A"))
    {
         if(edit_TALB(argv,mp3_data))
        {
           
            return failure;
        }
    } 
     else if(!strcmp(argv[2],"-y"))
    {
      
         if(edit_TYER(argv,mp3_data))
        {
           
            return failure;
        }
    }  
    else if(!strcmp(argv[2],"-m"))
    {
         if(edit_TCON(argv,mp3_data))
        {
       
            return failure;
        }
    }  
    else if(!strcmp(argv[2],"-c"))
    {
         if(edit_TCOM(argv,mp3_data))
        {
            return failure;
        }
    }
    else return failure;


      printf("------------------------------------Selected edit details-------------------------------------\n");
          printf("-------------------------------------Editing successfull--------------------------------------\n");
    printf("\n");
    return success;
}

status edit_TIT2(char*argv[],content * mp3_data)
{

    char tag_name[]="TIT2";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;

    return success;
}

status edit_TPE1(char*argv[],content * mp3_data)
{

    char tag_name[]="TPE1";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;
    
    return success;
}



status edit_TALB(char*argv[],content * mp3_data)
{
    char tag_name[]="TALB";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;

    return success;
}

status edit_TYER(char*argv[],content * mp3_data)
{

    char tag_name[]="TYER";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;
    
    return success;
}

status edit_TCOM(char*argv[],content * mp3_data)
{
    char tag_name[]="TCOM";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;

    return success;
}

status edit_TCON(char*argv[],content * mp3_data)
{
    char tag_name[]="TCON";
    if(edit_comn(tag_name,argv,mp3_data))
    return failure;
    
    return success;
}

status edit_comn(char tag_name[],char* argv[],content *mp3_data)
{
    
    if(search_tag(tag_name,mp3_data))
    return failure;
        fread(mp3_data->size_byt,TAG_SIZE,ENOCDE_BYTE,mp3_data->fptr_src);

    
              mp3_data->size_buffer=(char *)&mp3_data->frame_size;
             int ind=3;
                    for(int i=0;i<4;i++)
            {
                *(mp3_data->size_buffer+i)=mp3_data->size_byt[ind];
                ind--;
            }

            fseek(mp3_data->fptr_src,2,SEEK_CUR);
                char zero[mp3_data->frame_size];
                zero[mp3_data->frame_size]='\0';
            fread(zero,(mp3_data->frame_size),1,mp3_data->fptr_src);
            for(int i=1;i<mp3_data->frame_size;i++)
            {
                zero[i]=zero[i]&0;
            }

            strcpy(zero+ENOCDE_BYTE,argv[3]);
              fseek(mp3_data->fptr_src,-(mp3_data->frame_size),SEEK_CUR);
            
            fwrite(zero,mp3_data->frame_size,1,mp3_data->fptr_src);

return success;
}

