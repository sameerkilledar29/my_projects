#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<string.h>

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */






/* Read and validate Encode args from argv */

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
  
  int valid_extn;

  //validate source file name and store in variable
   char *check_bmp= strstr(argv[2],".bmp");
 
 if(check_bmp!=NULL)
 {
 
    valid_extn=strlen(check_bmp);
    
     if(valid_extn==4)
      {
        
        encInfo->src_image_fname=argv[2];
   
      }
      else
      {
         return e_failure;
      }

 }
 else 
 {
  printf("INFO: Source file not mentioned. mention '.bmp' file\n") ; 
  return e_failure;
 }

 
  //validate secrete file name and store in variable
  char *check_secret_file=strstr(argv[3],".");
 
 if(check_secret_file!=NULL)
 {
    if(valid_extn==4)
      {
        encInfo->secret_fname=argv[3];
       
      }
      else return e_failure;
  }
  else
  {
      printf("INFO: Secrete file not mentioned. Mention '.txt' file\n");
       return e_failure;

  }




 //validate and store the stego file if user input or create one file name
 if(argv[4]!=NULL)
 {
    char * check_stego_file=strstr(argv[4],".");
  
    if(check_stego_file!=NULL && valid_extn)
    {
      encInfo->stego_image_fname=argv[4];
    }
 }
 else
 {
  encInfo->stego_image_fname="stego.bmp";
 }


 return e_success;
 
}



//image size cpacity
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    //printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    //printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;



}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */



Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }
    else
    {
      printf("INFO: opened %s\n",encInfo->src_image_fname);
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }
    else
    {
      printf("INFO: opened %s\n",encInfo->secret_fname);
    }


    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }
    else    
    {
      printf("INFO: opened %s\n",encInfo->stego_image_fname);
    }


    // No failure return e_success
    return e_success;
}




//get file size in bytes
uint get_file_size(FILE *fptr)
{

  fseek(fptr,0,SEEK_END);
  long int size= ftell(fptr);
  return size;

}




//check the image capacity to hold secrert data
Status check_capacity(EncodeInfo *encoInfo)
{
  if(encoInfo->image_capacity>(encoInfo->size_secret_file*8))
  {
    return e_success;
  }
  else
  {
    return e_failure;
  }
}



Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{

  rewind(fptr_src_image);
  char buffer[60];
  fread(buffer,54,1,fptr_src_image);
  fwrite(buffer,54,1,fptr_dest_image);
  return e_success;
}




//encode magic string
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
  int magic_stg_len=strlen(magic_string);
  for(int i=0;i<magic_stg_len;i++)
  {
    fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
   encInfo->secret_data[0]=magic_string[i];
    
    //printf("%s\n",encInfo->secret_data);
    //printf("%s\n",encInfo->image_data);
    //calling encoding function
   if(encode_byte_to_lsb(encInfo->secret_data[0],encInfo->image_data))
   {
    return e_failure;
   }
   else
   {
      fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);     
   }
    
  }
  // printf("magic srtn Success byte encoding\n");
  return e_success;
}



//encode secrete file extn .txt

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    int file_extn_len=strlen(file_extn);

     //encoding file extn size
    fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
    encInfo->secret_data[0]=file_extn_len;
    
    //calling encoding function
    if(encode_byte_to_lsb(encInfo->secret_data[0],encInfo->image_data))
    {
      // printf("EROR file size BYTE Encoding\n ");
      return e_failure;
    }
    else
    {
      fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);    
    }


    
    //encoding file extention
    for(int i=0;i<file_extn_len;i++)
        {
          fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
        
          encInfo->secret_data[0]=file_extn[i];
        
         // printf("extn data =%c\n",encInfo->secret_data[0]);
          if(encode_byte_to_lsb(encInfo->secret_data[0],encInfo->image_data))
          {
            return e_failure;
          }
          else
          {
              fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);   
          }
  
        }
  return e_success;
 
}


Status encode_secret_file_size(int file_size, EncodeInfo *encInfo)
{
    char * size_ptr=(char*)&file_size;
    int n=1;
    for(int i=0;i<file_size;i++)
    {
      
      int file_size2;
      char *data=(char *)&file_size2;
      *(data+i)=*(size_ptr+i);
      fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
    
        if(encode_byte_to_lsb(size_ptr[i],encInfo->image_data))
        {
        return e_failure;
        }
        else
        {
          fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);
        }
      }

    return e_success;
}


Status encode_secret_file_data(EncodeInfo *encInfo)
{
  rewind(encInfo->fptr_secret);
    for(int i=0;i<encInfo->size_secret_file;i++)
    {
    
        fread(encInfo->secret_data,1,1,encInfo->fptr_secret);
     
        fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
     
        
        if(encode_byte_to_lsb(encInfo->secret_data[0],encInfo->image_data))
        {
          return e_failure;
        }
         else
        {
            fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);
        }
        
    }
  return e_success;
}


Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{ 
  int a;
  int b;
  a=ftell(fptr_src);
  fseek(fptr_src,0,SEEK_END);
  b=ftell(fptr_src);
  int c=b-a;
  fseek(fptr_src,-c,SEEK_CUR);
  char ch[c];
  fread(ch,c,1,fptr_src);
  fwrite(ch,c,1,fptr_dest);

  return e_success;
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{

   for(int j=0;j<8;j++)
    {

      int mask= data & 1<<j;
      mask=mask>>j;
      image_buffer[j]=(image_buffer[j] & 0xFE)|mask;
    }

  return e_success;
}


