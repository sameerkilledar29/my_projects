#ifndef DECODE_H
#define DECODE_H
#include "types.h"
#include<stdio.h>

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 6


typedef struct _DecodeInfo
{
    /* Secret File Info */
    char *decode_fname;
    FILE *fptr_decode;
    char extn_secret_file[MAX_FILE_SUFFIX];
    char secret_data[MAX_SECRET_BUF_SIZE];
    int size_secret_file;
    int size_secret_extn;
    char image_data[MAX_IMAGE_BUF_SIZE];
    char magic_string[10];
     /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

} DecodeInfo;

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the encoding */
Status do_decoding(DecodeInfo *decInfo);


/* Get File pointers for i/p and o/p files */
Status open_dfiles(DecodeInfo *decInfo);

Status decode_magic_string(DecodeInfo *decInfo);

/* decode secret file e                   xtenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/* decode secret file size */
Status decode_secret_file_size( DecodeInfo *decInfo);

/* decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);


/* decode a byte into LSB of image data array */
Status decode_byte_to_lsb(char *data, char *image_buffer);



#endif