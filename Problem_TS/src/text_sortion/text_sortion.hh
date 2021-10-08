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
#include "my_str.hh"

auto print = [](const int& n) { std::cout << n << std::endl; };

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
void sort(TextHandler* txt_handler, int (*comp)(const void* lhs, const void* rhs));

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

#endif /* TEXT_SORTION */

