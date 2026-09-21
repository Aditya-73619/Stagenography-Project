#include<stdio.h>
#include<string.h>
#include "encode.h"
#include "decode.h"
#include "common.h"
#include "types.h"


Status read_and_validate_decode_args(char *argv[],DecodeInfo *decInfo){
    //stego file Extension validation
    char *dot = strchr(argv[2],'.');

    if((dot == NULL) || (strcmp(dot,".bmp") != 0)){
        printf("Error : Output file must be .bmp file\n");
        return e_failure;
    }

    //storing stego file name
    decInfo->stego_image_fname = argv[2];

    //storing output secret/decode.txt file name
    if(argv[3] == NULL){
        strcpy(decInfo->decode_fname,"decode.txt");
    }
    else{
        char decode_name[50];

        //storing name of decode file till '.'
        sscanf(argv[3],"%[^.]",decode_name);

        strcpy(decInfo->decode_fname,decode_name);
        strcat(decInfo->decode_fname,".txt");   //storing .txt in the end
    }

    //open all files
    if(open_files(decInfo) == e_failure){
        printf("File not opened\n");
        return e_failure;
    }

    //Signature(BM) validation
    char signature[2];

    //reading first 2 bytes of stego image
    if(fread(signature,2,1,decInfo->fptr_stego_image) == 0)
        return e_failure;

    if(signature[0] != 'B' || signature[1] != 'M'){
        printf("Error : Signature is wrong\n");
        return e_failure;
    }


    return e_success;
}

Status open_files(DecodeInfo *decInfo){
    //stego file open
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname,"r");
    if(decInfo->fptr_stego_image == NULL){
        printf("Error : Stego file not opened\n");
        return e_failure;
    }

    //decode file open
    decInfo->fptr_decode = fopen(decInfo->decode_fname,"w");
    if(decInfo->fptr_decode == NULL){
        printf("Error : Decode file not opened\n");
        return e_failure;
    }

    return e_success;
}

Status do_decoding(DecodeInfo *decInfo)
{

}