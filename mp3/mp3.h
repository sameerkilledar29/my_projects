#ifndef  MP3_H
#define MP3_H
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#define FLAG 2
#define ENOCDE_BYTE 1
#define TAG_SIZE 4
#define TOTAL_TAG 12
typedef enum  
{
    success,
    failure
} status;

typedef enum _operation
{
    view,
    edit,
    unsupported
} operation;


typedef struct _mp3
{
    FILE * fptr_src;
    char file_name[30];
    char TIT2[100];
    char TALB[100];
    char TPE1[100];
    char TYER[5];
    char TCON[100];
    char TCOM[100];
    char ID3[3];
    char ver[2];
    char size_byt[4];
    int frame_size;
   char frame_head[5];
    char* size_buffer;
   

}
content;


status check_operation(char *argv[]);
status valid_file_name(char *argv[],content *mp3_data);
status view_tag(content * mp3_data);
status valid_version(content *mp3_data);
status read_TIT2(content * mp3_data);
status read_TPE1(content * mp3_data);
status read_TALB(content * mp3_data);
status read_TYER(content * mp3_data);
status read_TCON(content * mp3_data);
status read_TCOM(content * mp3_data);
status print_all(content *mp3_data);
status read_tag(char * tag_name,char* tag_cont,content *mp3_data);
status search_tag(char * tag_name,content *mp3_data);

//editing functions

status edit_tag(char*argv[],content *mp3_data);
status edit_TIT2(char* argv[],content * mp3_data);
status edit_TPE1(char* argv[],content * mp3_data);
status edit_TALB(char* argv[],content * mp3_data);
status edit_TYER(char* argv[],content * mp3_data);
status edit_TCON(char* argv[],content * mp3_data);
status edit_TCOM(char* argv[],content * mp3_data);
status edit_comn(char tag_name[],char* argv[],content* mp3_data);
void help();

#endif

