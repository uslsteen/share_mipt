#ifndef M_QSORT
#define M_QSORT

#include "ctype.h"

#include <iostream>

#include <assert.h>
#include <string.h>

#include "my_str.hh"

typedef int (*comp)(const void* lhs, const void* rhs);

/**
 * @brief Function for comparision
*/

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 * @return int 
 */
int forward_compare(const void* lhs, const void* rhs);

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 * @return int 
 */
int backward_compare(const void* lhs, const void* rhs);

/**
 * @brief quick sort algorithm realization
*/

/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @param comp 
 */
void q_sort(my_str* arr, size_t low, size_t high, int (*comp)(const void* lhs, const void* rhs));

/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @param comp 
 * @return unsigned 
 */
size_t partition(my_str* arr, size_t low, size_t high, int (*comp)(const void* lhs, const void* rhs));

/**
 * @brief 
 * 
 * @param lhs 
 * @param rhs 
 */
void swap(my_str* lhs, my_str* rhs);

inline bool is_end_line(char symbol) {
    return (symbol == '\n') || (symbol == '\0');
}

#endif /* M_QSORT */