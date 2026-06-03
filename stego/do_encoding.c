#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<string.h>
#include "common.h"


Status do_encoding(EncodeInfo *encinfo)
{
    const char *magic_string=MAGIC_STRING;
    printf("INFO: Opening required files\n");
    if(open_files(encinfo))
        {
        
            return e_failure;
        }
        else
        {
            printf("INFO: Done\n");
        }


        printf("INFO: ## Encoding Started ##\n");
        printf("INFO: Checking Image capacity and File Size\n");
        encinfo->image_capacity= get_image_size_for_bmp(encinfo->fptr_src_image);
        encinfo->size_secret_file=get_file_size(encinfo->fptr_secret);


        //Check image capacity to store the secret file data
        
    if(check_capacity(encinfo))
        {
          printf("INFO: ERROR!!\n");
        }
     else
        {
          printf("INFO: Done\n");  
        }

        printf("INFO: Copying header file\n");
        //copying first 54 header bytes
    if(copy_bmp_header(encinfo->fptr_src_image,encinfo->fptr_stego_image))
    {
        printf("INFO: ERROR!!\n");
    }
    else
    {
        
        printf("INFO: Done\n");
    }



        
    
        printf("INFO: Encoding Magic String\n");
    
    //encoding magic string
    if(encode_magic_string(magic_string,encinfo))
    {
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
    }





        printf("INFO: Encoding Secrete file extention\n");
    
    //encoding secrete file extn
    char *file_extn=strstr(encinfo->secret_fname,".");

    //printf("file extn = %d",file_extn_len);


    if(encode_secret_file_extn(file_extn,encinfo))
    {
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
    }




        printf("INFO: Encoding Secrete file size\n");
    
    //encode secrete file size;
    if(encode_secret_file_size(encinfo->size_secret_file,encinfo))
    {
    
        printf("INFO: ERORR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
        
    }


        printf("INFO: Encoding Secrete file Data\n");
    
        if(encode_secret_file_data(encinfo))
    {
    
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
        
    }



    
        printf("INFO: Copying left over Data\n");
    
    if(copy_remaining_img_data(encinfo->fptr_src_image,encinfo->fptr_stego_image))
    {
    
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
        
    } 
    
    return e_success;


}
