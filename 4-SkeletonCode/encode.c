#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "types.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

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


Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    
    char *dot = strchr(argv[2],'.');        //source file extension validation

    if(dot==NULL || (strcmp(dot,".bmp") != 0)){     
        printf("Error : Source image file must be .bmp file\n");
        return e_failure;
    }

    encInfo->src_image_fname = argv[2];     //storing src file name 

    encInfo->secret_fname = argv[3];        //storing secret file name

    if(argv[4]==NULL){                      //storing output/stego file name
        encInfo->stego_image_fname = "output.bmp";
    }
    else{
        dot = strchr(argv[4],'.');          //output file extension validation

        if(dot==NULL || (strcmp(dot,".bmp") != 0)){
            printf("Error : Output file must be .bmp file\n");
            return e_failure;
        }

        encInfo->stego_image_fname = argv[4];
    }

    if(open_files(encInfo) == e_failure){
        printf("File not opened\n");
        return e_failure;
    }
    
    return e_success;
}

Status open_files(EncodeInfo *encInfo)
{
    //Src file open
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname,"r");    
    if(encInfo->fptr_src_image == NULL){
        printf("Error : Src file not opened\n");
        return e_failure;
    }

    //Secret file open
    encInfo->fptr_secret = fopen(encInfo->secret_fname,"r");
    if(encInfo->fptr_secret == NULL){
        printf("Error : Secret file not opened\n");
        return e_failure;
    }

    //Stego file open
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname,"w");
    if(encInfo->fptr_stego_image == NULL){
        printf("Error : Output file not opened\n");
        return e_failure;
    }

    return e_success;
}


Status do_encoding(EncodeInfo *encInfo)
{
    //capacity check for .bmp file and secret file
    if(check_capacity(encInfo) == e_failure){
        printf("Error : ");
        return e_failure;
    }

    //copy .bmp header to stego
    copy_bmp_header(encInfo->fptr_src_image,encInfo->fptr_stego_image)

    /*
        // call check_capacity(&encInfo) == e_failure
            print error msg, return e_failure

        -> call copy_bmp_header(fptr_src_image(.bmp file), fptr_dest_image()) == e_failure
            print error msg, return e_failure

        -> call encode_magic_string(MAGIC_STRING,endInfo) == e_failure
            print error, return e_failure

        -> call encode_secret_file_extn_size(encInfo) == e_failure
            print error, return e_failure
    */
}


Status check_capacity(EncodeInfo *encInfo)
{
    //storing size of src.bmp file
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);

    //storing size of secret file
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    if(encInfo->image_capacity < (14 + encInfo->size_secret_file * 8)){
        printf("Error : Secret file size is bigger than .bmp file\n");
        return e_failure;
    }

    return e_success;
}

uint get_file_size(FILE *fptr)
{
    fseek(fptr,0,SEEK_END);
    return ftell(fptr);
}


Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    rewind(fptr_src_image);
    rewind(fptr_dest_image);
    /*
        declare the buffer  of 54 bytes
        read 54 butes form src file
        write those 54 butes to dest file

        return e_success
    */
}

Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    /*
        declare a buff of 8 bytes
        for(int i=0;i<(length of magic string)2;i++){
            read 8 bytes from the src file into buff
            encode_byte_to_lsb(magic_string[1] (#), buff)

            write the encoded buff to output.bmp file
        }
        -> return e_success
    */
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i=7;i>=0;i--){
        /*
            get ith bit 
            if set, set the LSB of image_buffer[7-i]
            if clear, clear the LSB of image_buffer[7-i]
        */
    }
}

Status encode_secret_file_extn_size(EncodeInfo *encInfo)
{
    /*
        -> char *dot = strchr(secret_file_name,'.')
        -> strcpy(extn_secret_file,dot);

        -> declare a buff[32]

        -> read 32 bytes from src_file into buff
        -> call encode_size_to_lsb(strlen(extn_secret_file),data);
    */
}

Status encode_size_to_lsb(int size,char *image_buffer)
{
    /*

    */
}
