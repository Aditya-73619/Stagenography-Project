#include <stdio.h>
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

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
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

    // No failure return e_success
    return e_success;
}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    /* check aggv[2] (beautiful.bmp) extension ->  check .bmp
        if not , print error msg, return e_failue
        if valid then go for opening file and further operation

        encInfo -> secret_fname = argv[3];

        if(argv[4]==NUll)
            encInfo -> stego_image_fname = "output.bmp"
        else
            * validate argv[4] is ".bmp" *
                => if not ,print error msg, return e_failue
            * encInfo -> stego_image_fname =  argv[4]
    */
    open_files(encInfo);
}

Status open_files(EncodeInfo *encInfo)
{
    /*
    -> open 'encInfo -> src_image_fname' file in read mode
        if(file not opened) -> print error and return e_failure
    
        *SAME CODE*
    
    FILE *fptr_src_image = encInfo->src_image_fname;

    if(fptr_src_image == NULL){
        printf("Error");
        return e_failure;
    }
    

    ////

    -> open 'encInfo -> secret_fname' file in read mode
        if(file not opened) -> print error and return e_failure

    ////

    -> open 'encInfo -> stego_image_fname' file in write mode
        if(file not opened) -> print error and return e_failure

        validation not needed but fptr_stego_image should be updated

        -> call open)files(endInfo) == e)failure
        return e_failure
    if everything is fine
        return e_success
    */

}


Status do_encoding(EncodeInfo *encInfo)
{
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
    /*
        0> call get_image_size_for_bmp(encode -> fptr_src_image)
        encInfo -> image_capacity = get_iamge_size (upar wala)

        -> call get_file_size(encode -> fptr_secret);
        size_secret_file = get_file_size(encode -> fptr_secret);

        ->check (14 + size_secret_file * 8) > image_capacity
            return e_failure;
            
        -> return e_success;
    */
}

uint get_file_size(FILE *fptr)
{
    /*
        -> move the offset to last pos using fseek
        -> return ftell
    */
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
