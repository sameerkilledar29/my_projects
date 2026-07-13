#include "mp3.h"

static int flag=0;
status valid_version(content *mp3_data)
{

    rewind(mp3_data->fptr_src);
    fread(mp3_data->ID3,3,1,mp3_data->fptr_src);
 
    if((strcmp(mp3_data->ID3,"ID3"))==0)
    {
    
    }
    else 
    {
     
        return failure;
    }
    short ver;
     
     fread(mp3_data->ver,2,1,mp3_data->fptr_src);
     memcpy(&ver,mp3_data->ver,2);
    
     if(ver!=3)
     {
       printf("ERROR: Invalid version please provide ID3 version 3 file\n");
        return failure;
     }
     
     return success;
}

   //CHECKING TIT2
status read_TIT2(content * mp3_data)   
{
    char tag_name[4]="TIT2";

    if(read_tag(tag_name,mp3_data->TIT2,mp3_data))
    {
        return failure;
    }
    return success;

}

   //CHECKING TPE1
status read_TPE1(content * mp3_data)   
{ 
    char tag_name[4]="TPE1";

    if(read_tag(tag_name,mp3_data->TPE1,mp3_data))
    {
        return failure;
    }
    return success;


}


   //CHECKING TALB
 status read_TALB(content * mp3_data)   
{

    char tag_name[4]="TALB";

    if(read_tag(tag_name,mp3_data->TALB,mp3_data))
    {
        return failure;
    }
    return success;
}


   //CHECKING TYER
 status read_TYER(content * mp3_data)   
{
    char tag_name[4]="TYER";

    if(read_tag(tag_name,mp3_data->TYER,mp3_data))
    {
        return failure;
    }
    return success;
}


//read the content type
status read_TCON(content * mp3_data)   
{
    char tag_name[4]="TCON";

    if(read_tag(tag_name,mp3_data->TCON,mp3_data))
    {
        return failure;
    }
    return success;
}

 

//read the comment
status read_TCOM(content * mp3_data)   
{
    char tag_name[4]="TCOM";

    if(read_tag(tag_name,mp3_data->TCOM,mp3_data))
    {
        return failure;
    }
    return success;
}


//function to search given tag
 status search_tag(char *tag_name,content *mp3_data)
{
    rewind(mp3_data->fptr_src);
    fseek(mp3_data->fptr_src,10,SEEK_CUR);
    for(int i=0;i<TOTAL_TAG;i++)
    {
        fread(mp3_data->frame_head,4,ENOCDE_BYTE,mp3_data->fptr_src);
        if(strcmp(tag_name,mp3_data->frame_head))
        {
             fread(mp3_data->size_byt,4,1,mp3_data->fptr_src);
              mp3_data->size_buffer=(char *)&mp3_data->frame_size;
             int ind=3;
            for(int i=0;i<4;i++)
            {
                *(mp3_data->size_buffer+i)=mp3_data->size_byt[ind];
                ind--;
            }

            fseek(mp3_data->fptr_src,(FLAG+mp3_data->frame_size),SEEK_CUR);
           
        }
        else
        {
            return success;
        }
    }

    return failure;
}


//readding the tags function
 status read_tag(char *tag_name,char* tag_cont, content *mp3_data)
{

    if(search_tag(tag_name,mp3_data))
    {
        return failure;
    }


 
        fread(mp3_data->size_byt,TAG_SIZE,ENOCDE_BYTE,mp3_data->fptr_src);

           //  fread(mp3_data->size_byt,4,1,mp3_data->fptr_src);
              mp3_data->size_buffer=(char *)&mp3_data->frame_size;
             int ind=3;
                    for(int i=0;i<4;i++)
            {
                *(mp3_data->size_buffer+i)=mp3_data->size_byt[ind];
                ind--;
            }
                        
            //fetching the TIT2 content
                fseek(mp3_data->fptr_src,2,SEEK_CUR);
                fread(tag_cont,mp3_data->frame_size,1,mp3_data->fptr_src);
                tag_cont[mp3_data->frame_size]='\0';
    return success;
}