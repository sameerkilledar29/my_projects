#include<stdio.h>
#include"types.h"
#include"encode.h"
#include<string.h>
#include"decode.h"

int main(int argc, char *argv[])
{
    EncodeInfo  encinfo;
    uint image_size;
    DecodeInfo decinfo;

    //open User input mode -e or -d

    //Validate Enough arguments
    if(argc<3||argc>5)
    {
        printf("ERROR: Invalid Arguments\n");
        return e_failure;
    }
 
    
    //Check for operations to perform
   if( check_operation_type(argv)==e_encode)
    {
        printf("INFO: Validation of files\n");
        //read and validate the inputs from CLA
        if(read_and_validate_encode_args(argv,&encinfo))
        {
            printf("INFO: Invalid file names\n");
            return 0;
        }
        else
        {
            printf("INFO: Valid files names\n");
        }

        
        //Encoding process
        
         if(do_encoding(&encinfo))
         {
            printf("INFO: Encoding Unsuccesfull\n"); 
         }
         else
         {
               printf("INFO: ## Encoding done succesfull ##\n");    
         }
     
         
         fclose(encinfo.fptr_src_image);
         fclose(encinfo.fptr_stego_image);
         fclose(encinfo.fptr_secret);
     
    }
    else if(check_operation_type(argv)==e_decode)
    {
        if(read_and_validate_decode_args(argv,&decinfo))
        {
            printf("ERROR: Invalid file names\n");
            return 0;
        }
        else
        {
            printf("INFO: Valid files names\n");
        }
 

         //Encoding process
         if(do_decoding(&decinfo))
         {
            printf("ERORR: Decoding Unsuccesfull\n"); 
         }
         else
         {
               printf("INFO: ## Decoding Succesfull ##\n");    
         }
         fclose(decinfo.fptr_decode);
         fclose(decinfo.fptr_stego_image);
     
    }
    else
    {
        printf("ERROR: Enter Correct ARGS\n");
    }


}
