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
void my_str_arr_construct(TextHandler* txt_handler, ErrProc* err_handler);

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
void get_sorted_txt(const char* pathname, TextHandler* txt_handler, ErrProc* err_handler);

/**
 * @brief Get the orig txt object
 * 
 */
void get_orig_txt(TextHandler* txt_handler, ErrProc* err_handler);

/**
 * @brief Get the str num object
 * 
 * @param txt_handler 
 */
void get_str_num(TextHandler* txt_handler);

/**
 * @brief 
 * 
 * @param txt_handler 
 * @param err_handler 
 * @param argv 
 * @return int 
 */
int constructor(TextHandler* txt_handler, ErrProc* err_handler, char** argv);

/**
 * @brief 
 * 
 * @param txt_handler 
 */
void destructor(TextHandler* txt_handler);

#endif /* TEXT_SORTION */

