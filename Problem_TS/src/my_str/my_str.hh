#ifndef MY_STR_HH
#define MY_STR_HH

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include <iostream>

/**
 * @brief 
 */
enum ALLOCA_PARAMS {
    DELTA = 50,
    
    FLAG_LESS = 0,
    FLAG_MORE = 1
};

const size_t START_SIZE = 512;

/**
 * @brief 
 * 
 */
struct my_str { 
    char* begin;
    size_t size;
};

/**
 * @brief 
 * 
 * @param arr 
 * @param size 
 * @param cur_str 
 * @param capacity 
 * @param flag 
 */
void my_str_push(my_str* arr, size_t* size, my_str* cur_str);

/**
 * @brief 
 * 
 * @param str_array 
 * @param str_arr_size 
 * @param flag 
 */
void str_arr_realloc(my_str* arr, size_t* size, enum ALLOCA_PARAMS flag);

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

#endif /* MY_STR_HH */
