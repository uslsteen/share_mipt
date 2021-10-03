#ifndef TEXT_SORTION
#define TEXT_SORTION

#include <iostream>

#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "m_qsort.hh"
#include "err_proc.hh"

auto print = [](const int& n) { std::cout << n << std::endl; };

const int START_SIZE = 512;

/**
 * @brief 
 */
enum ALLOCA_PARAMS {
    DELTA = 50,
    
    FLAG_LESS = 0,
    FLAG_MORE = 1
};

/**
 * @brief 
 */
struct TextHandler {
    char* text_buffer = nullptr;
    ssize_t byte_size = 0;

    my_str* str_array = nullptr;
    size_t str_arr_size = 0;
};



/**
 * @brief 
 * 
 * @param txt_handler 
 * @param pathname 
 * @return int 
 */
int buf_load(TextHandler* txt_handler, const char* pathname, ErrProc* err_handler);

/**
 * @brief 
 * 
 * @param txt_handler 
 * @return int 
 */
int my_str_arr_construct(TextHandler* txt_handler, ErrProc* err_handler);

/**
 * @brief 
 * 
 * @param txt_handler 
 */
void sort(TextHandler* txt_handler);

/**
 * @brief 
 * 
 * @param str_array 
 * @param str_arr_size 
 * @param flag 
 */
void str_array_realloc(my_str* str_array, size_t* str_arr_size, enum ALLOCA_PARAMS flag);

/**
 * @brief Get the sorted txt object
 * 
 * @param txt_handler 
 * @param pathname 
 */
int get_sorted_txt(const char* pathname, TextHandler* txt_handler, ErrProc* err_handler);

/**
 * @brief 
 * 
 * @param txt_handler 
 */
void destructor(TextHandler* txt_handler);

/**
 * @brief 
 * 
 * @param size 
 * @param capacity 
 * @param flag 
 * @return true 
 * @return false 
 */
inline bool is_need_allocate(size_t size, size_t capacity, enum ALLOCA_PARAMS flag) {
    if (!flag)    // FLAG_LESS
        return (size != capacity);      /* if size != capacity => return false => allocate is need */
    return !((capacity - size) > DELTA);
}
#endif /* TEXT_SORTION */

