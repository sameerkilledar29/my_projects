#include <stdio.h>
#include "decode.h"
#include "types.h"
#include<string.h>


Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
  
  int valid_extn;

  //validate source file name and store in variable
   char *check_bmp= strstr(argv[2],".bmp");
 
    if(check_bmp!=NULL)
    {
 
      valid_extn=strlen(check_bmp);
    
      if(valid_extn==4)
      {
        
        decInfo->stego_image_fname=argv[2];
   
      }
      else return e_failure;
    }
    else return e_failure;





    //validate Decoded file 
    if(argv[3]!=NULL)
    {
        char * check_decode_file=strstr(argv[3],".txt");
      
        if(check_decode_file!=NULL && valid_extn)
        {
          decInfo->decode_fname=argv[3];
        }
    }
    else
    {
      decInfo->decode_fname="decode.txt";
    }


     return e_success;
 

}







Status open_dfiles(DecodeInfo *decInfo)
{
    // Src stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
    // Do Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

    	return e_failure;
    }

    // Secret file decoded
    decInfo->fptr_decode = fopen(decInfo->decode_fname, "w");
    // Do Error handling
    if (decInfo->fptr_decode == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decode_fname);

    	return e_failure;
    }


    // No failure return e_success
    return e_success;
}

//decode magic string
Status decode_magic_string(DecodeInfo *decInfo)
{
   rewind(decInfo->fptr_stego_image);
  fseek(decInfo->fptr_stego_image,54,SEEK_SET);
  for(int i=0;i<2;i++)
  {
    fread(decInfo->image_data,8,1,decInfo->fptr_stego_image);

    //calling encoding function
   if(decode_byte_to_lsb(decInfo->secret_data,decInfo->image_data))
   {
    return e_failure;
   }
   else
   {
      //fwrite(decInfo->secret_data,1,1,decInfo->fptr_decode);
      decInfo->magic_string[i]=decInfo->secret_data[0];
     }
    
  }
  return e_success;
}

//decode extn of file

Status decode_secret_file_extn(DecodeInfo *decInfo)
 {
  
    fread(decInfo->image_data,8,1,decInfo->fptr_stego_image);
    
    
    //calling encoding function
   if(decode_byte_to_lsb(decInfo->secret_data,decInfo->image_data))
   {
    return e_failure;
   }
   else
   { 
    decInfo->size_secret_extn=decInfo->secret_data[0];


   }


    //encoding file extention
    for(int i=0;i<decInfo->size_secret_extn;i++)
    {
    fread(decInfo->image_data,8,1,decInfo->fptr_stego_image);
  
   if(decode_byte_to_lsb(decInfo->secret_data,decInfo->image_data))
   {
   return e_failure;
   }
   else
   {
  decInfo->extn_secret_file[i]=decInfo->secret_data[0];
   }
    
   
  }
 return e_success;
 
}




Status decode_secret_file_size( DecodeInfo *decInfo)
 {
for(int i=0;i<sizeof(int);i++)
{
    
    fread(decInfo->image_data,8,1,decInfo->fptr_stego_image);
    
       if(decode_byte_to_lsb(decInfo->secret_data,decInfo->image_data))
      {
         return e_failure;
      }
      else
      {
        char * ptr=(char*)&decInfo->size_secret_file;
         *(ptr+i)=decInfo->secret_data[0];
       
   }
  }
  
   return e_success;
  }

//decode the secrete file data
Status decode_secret_file_data(DecodeInfo *decInfo)
{
fseek(decInfo->fptr_stego_image,8,SEEK_CUR);
    for(int i=0;i<decInfo->size_secret_file;i++)
    {
      fread(decInfo->image_data,8,1,decInfo->fptr_stego_image);   
        
        if(decode_byte_to_lsb(decInfo->secret_data,decInfo->image_data))
        {
          return e_failure;  
        }
         else
        {
            fwrite(decInfo->secret_data,1,1,decInfo->fptr_decode);
        }
        
    }
  return e_success;
}





Status decode_byte_to_lsb(char *data, char *image_buffer)
{

    data[0]=data[0]&0;
   for(int j=0;j<8;j++)
    {

      int mask= image_buffer[j] & 1;
      mask=mask<<j;
      
      data[0]=data[0]|mask;
    }

    return e_success;
}
