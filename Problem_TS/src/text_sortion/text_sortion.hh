#ifndef TEXT_SORTION
#define TEXT_SORTION

#include <iostream>

#include <assert.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct my_str { /* renamed  my_str --> naive_str */ 
    char* begin;
    size_t size;

};

struct TextHandler {

    char* text_buffer = nullptr;
    size_t byte_size = 0;

    my_str* str_array = nullptr;
};


inline int ErrProcess(char *str_err)
{
    perror("Error occured : ");
    perror(str_err);
    return errno;
}

/*
struct ErrHandler {
    char* err_msg;

};
*/

int buf_load(TextHandler* txt_handler, const char* pathname);

int my_str_arr_construct(TextHandler* txt_handler);

#endif /* TEXT_SORTION */
