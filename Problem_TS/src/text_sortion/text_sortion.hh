#ifndef TEXT_SORTION
#define TEXT_SORTION

#include <iostream>

#include <assert.h>
#include <string.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct my_str { /* renamed  my_str --> naive_str */ 
    char* begin;
    size_t size;

};


enum ALLOCA_PARAMS {
    START_SIZE = 512,
    DELTA = 100
};

struct TextHandler {
    char* text_buffer = nullptr;
    ssize_t byte_size = 0;

    my_str* str_array = nullptr;
    size_t str_arr_size = 0;
};


inline int ErrProcess(char *str_err)
{
    perror("Error occured : ");
    perror(str_err);
    return errno;
}

int buf_load(TextHandler* txt_handler, const char* pathname);
int my_str_arr_construct(TextHandler* txt_handler);

inline bool is_need_allocate(size_t size, size_t capacity) {
    return (capacity - size) < DELTA;
}

/*
struct ErrHandler {
    char* err_msg;

};
*/

#endif /* TEXT_SORTION */

