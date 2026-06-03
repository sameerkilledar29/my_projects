#include <stdio.h>
#include "decode.h"
#include "types.h"
#include<string.h>
#include "common.h"
#include "decode.h"


Status do_decoding(DecodeInfo *decInfo)
{
     char *magic_string;
     printf("INFO: Opening Required files\n");
    if(open_dfiles(decInfo))
        {
           return e_failure;
        }
        else
        {
            printf("INFO: Done\n");
        }

         //encoding magic string
         
        printf("INFO: ## Decoding Started ##\n");
     
        printf("INFO: Decoding Magic String\n");
    
    if(decode_magic_string(decInfo))
    {
       printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
    }

     
    //decoding secrete file extn
    
    printf("INFO: Decoding Secrete file extention\n");
    
    if(decode_secret_file_extn(decInfo))
    {
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
    }


    
    //decode secrete file size;
    
     printf("INFO: Decoding Secrete file size\n");
    
    if(decode_secret_file_size(decInfo))
    {
    
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
        
    }


        printf("INFO: Decoding Secrete file Data\n");
    
        if(decode_secret_file_data(decInfo))
    {
    
        printf("INFO: ERROR!!\n");
    }
    else
    {
        printf("INFO: Done\n");
        
    }



 return e_success; 


}