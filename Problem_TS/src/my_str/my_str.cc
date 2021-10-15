#include "my_str.hh"


void my_str_push(my_str* arr, size_t* size, my_str* cur_str) {

    assert(arr);
    assert(cur_str);
    
    arr[*size].begin = cur_str->begin;
    arr[*size].size = cur_str->size;

    (*size)++;

#if 0 
    if (flag == FLAG_MORE) {

        if (is_need_allocate(*size, *capacity, FLAG_MORE))   
            str_arr_realloc(arr, capacity, FLAG_MORE);
    
    }
    else if (flag == FLAG_LESS) {
                
        if (is_need_allocate(*size, *capacity, FLAG_LESS))
            str_arr_realloc(arr , size, FLAG_LESS);
    }
#endif
}

void str_arr_realloc(my_str* arr, size_t* size, enum ALLOCA_PARAMS flag) {

    assert(arr);
    assert(size);

    if (flag)
        *size <<= 1; 
    
    my_str* new_arr = (my_str*) realloc(arr, sizeof(new_arr[0]) * (*size));
    assert(new_arr);

    arr = new_arr;
}