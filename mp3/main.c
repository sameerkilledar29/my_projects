#include<stdio.h>
#include"mp3.h"

int main(int argc, char * argv[])
{
    content mp3_data;

    if(argc==2)
    {
    if(!(strcmp(argv[1],"--help")))
    {
        help();
        return success;
    }

    }
    if(argc<3||argc>5)
    {
         printf("ERROR: Invalid arguments\n");
                printf("ERROR: To get help pass like: ./a.out --help\n");
    
        return failure;
    }

    //checking what operation need to do
    if(check_operation(argv)==view)
    {
        
        if(valid_file_name(argv,&mp3_data))
        {
            printf("ERROR: To get help pass like: ./a.out --help\n");
            return failure;
        }
       

        if(view_tag(&mp3_data))
        {
            
            printf("ERROR: To get help pass like: ./a.out --help\n");
            return failure;
        }

          

       
    }
    else if(check_operation(argv)==edit)
    {
        
        if(valid_file_name(argv,&mp3_data))
        {
           
            printf("ERROR: To get help pass like: ./a.out --help\n");
            return failure;
        }

        if(edit_tag(argv,&mp3_data))
        {
 
            printf("ERROR: To get help pass like: ./a.out --help\n");     
            return failure;
        }

    }
    else
    {
        printf("ERROR: Invalid Commands\n");
        
         printf("ERROR: To get help pass like: ./a.out --help\n");
        
    
        return failure;
    }
 
fclose(mp3_data.fptr_src);

}


void help()
{
        printf("1. To view please pass like: ./a.out -v mp3_Filename\n"
                "2. To edit please pass like: ./a.out -e -t/-a/-A/-y/-m/-c changing_text mp3_Filename\n"
                "       2.1. -t -> to edit song title\n"
                "       2.2. -a -> to edit song artist name\n"
                "       2.3. -A -> to edit song album name\n"
                "       2.4. -y -> to edit song year\n"
                "       2.5. -m -> to edit song content type\n"
                "       2.6. -c -> to edit song composer\n");

}