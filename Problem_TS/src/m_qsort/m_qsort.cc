#include "m_qsort.hh"


int forward_compare(const void* lhs, const void* rhs) {
    
    assert(lhs);
    assert(rhs);

    /* cat const void* to char* */
    char* lhs_beg = ((my_str*)lhs)->begin;
    char* rhs_beg = ((my_str*)rhs)->begin;

    while (true) {

        /* finding first valid symbol in current string */
        while (!isalpha(*lhs_beg) && !is_end_line(*lhs_beg))
            ++lhs_beg;
        
        while (!isalpha(*rhs_beg) && !is_end_line(*rhs_beg))
            ++rhs_beg;
        
        /* if first valid symbols was found, compare it each other */
        if (toupper(*lhs_beg) != toupper(*rhs_beg) || ((is_end_line(*lhs_beg) && is_end_line(*rhs_beg))))
            break;
        
        /* if symbols are not equal, go to next symbol after these */
        ++lhs_beg, ++rhs_beg;
    }

    return ((toupper(*lhs_beg) - toupper(*rhs_beg)));
}

int backward_compare(const void* lhs, const void* rhs) {

    assert(lhs);
    assert(rhs);

    char* lhs_end = ((my_str*)lhs)->begin + ((my_str*)lhs)->size - 1;
    char* rhs_end = ((my_str*)rhs)->begin + ((my_str*)rhs)->size - 1;

    char* lhs_beg = ((my_str*)lhs)->begin;
    char* rhs_beg = ((my_str*)rhs)->begin;

    while (true) {

        while(!isalpha(*lhs_end) && lhs_end != lhs_beg && !(is_end_line(*lhs_end)))
            --lhs_end;

        while(!isalpha(*rhs_end) && rhs_end != rhs_beg && !(is_end_line(*rhs_end)))
            --rhs_end;

        if (toupper(*lhs_end) != toupper(*rhs_end) || lhs_end == lhs_beg || rhs_end == rhs_beg
                                                   || ((is_end_line(*lhs_end) || is_end_line(*rhs_end))))
			break;

        --lhs_end;
        --rhs_end;
    }

    return (toupper(*lhs_end) - toupper(*rhs_end));
}


void q_sort(my_str* arr, size_t low, size_t high, int (*comp)(const void* lhs, const void* rhs)) {

    assert(arr);
    if (low >= high)
        return;

    size_t pos = partition(arr, low, high, comp);

    if (pos > low)
        q_sort(arr, low, pos - 1, comp);

    q_sort(arr, pos + 1, high, comp);
}


size_t partition(my_str* arr, size_t low, size_t high, int (*comp)(const void* lhs, const void* rhs)) {
    
    size_t pivot = high;
    size_t prev_beg = low - 1;  
 
    for (size_t beg = low; beg <= high- 1; ++beg)
    {
        if (comp(arr + beg, arr + pivot) < 0)
        {
            ++prev_beg;
            swap(arr + prev_beg, arr + beg);
        }
    }

    swap(arr + prev_beg + 1, arr + high);
    return (prev_beg + 1);
}

void swap(my_str* lhs, my_str* rhs) {

    assert(lhs);
    assert(rhs);

    my_str temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}