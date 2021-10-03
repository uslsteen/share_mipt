#include "my_str.hh"


void my_str_push(my_str* arr, size_t* pos, char* beg, size_t str_size, size_t* size, size_t* capacity, ALLOCA_PARAMS flag) {

    assert(arr);
    assert(beg);
    assert(pos);
    assert(size);
    assert(capacity);
    
    arr[*pos].begin = beg;
    arr[*pos].size = str_size;
    (*pos)++;
    
    if (flag == FLAG_MORE) {

        if (is_need_allocate(*pos, *capacity, FLAG_MORE))   
            str_arr_realloc(arr, capacity, FLAG_MORE);    
    }
    else if (flag == FLAG_LESS) {
        
        *size = *pos;

        if (is_need_allocate(*pos, *capacity, FLAG_LESS))
            str_arr_realloc(arr , size, FLAG_LESS);
    }
}

/*
void str_arr_constr(my_str* str_arr, size_t* capacity) {

    *capacity = START_SIZE; 
    str_arr = (my_str*)calloc(START_SIZE, sizeof(str_arr[0]));
    assert(str_arr);
}*/

void str_arr_realloc(my_str* arr, size_t* size, enum ALLOCA_PARAMS flag) {

    assert(arr);
    assert(size);

    if (flag)
        *size <<= 1; 
    
    my_str* new_arr = (my_str*) realloc(arr, sizeof(my_str) * (*size));
    assert(new_arr);

    arr = new_arr;
}

