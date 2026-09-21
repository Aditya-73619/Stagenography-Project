#ifndef DECODE_H
#define DECODE_H

#include<stdio.h>
#include "types.h"

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 5

typedef struct _DecodeInfo
{
    /* Output secret file info(decode.txt) */
    char decode_fname[50];
    FILE *fptr_decode;
    // char extn_deocode_file[MAX_FILE_SUFFIX];
    char decode_data[MAX_SECRET_BUF_SIZE];
    long size_decode_file;

    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

} DecodeInfo;

/* Decoding function prototype */

/* Check operation type */
OperationType check_operation_type(char opt);

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[],DecodeInfo *decInfo);

/* Perform the encoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_files(DecodeInfo *decInfo);



#endif