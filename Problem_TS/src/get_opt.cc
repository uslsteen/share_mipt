#include <unistd.h>
#include <iostream>
#include "text_sortion.hh"
#include "m_qsort.hh"

/**
 * @brief 
 * 
 * @param pathname 
 * @return int 
 */
int print_usage(char* pathname) {
    printf("USAGE: %s input output algorithm sort_mode\n", pathname);
    printf("input  -<path/to/input stream>\n"
           "output - <path/to/output_stream>\n"
           "\nalgorithm:\n"
           "    custom   - m_qsort realisation\n"
           "    standart - standart qsort\n"
           "\nsort_mode:\n"
           "    forward  - sorting from beginning\n"
           "    backward - sorting from ending\n");

    return ERR_EXIT;
}

/**
 * @brief 
 * 
 * @param argv 
 * @param m_txt_hndler 
 * @return int 
 */
int my_get_opt(char** argv, TextHandler* m_txt_hndler) {

    assert(argv);
    assert(m_txt_hndler);

    char sort_type = *argv[3];
    char mode = *argv[4];

    if (sort_type == 'c') {

        if (mode == 'b')
            qsort(m_txt_hndler->str_array, m_txt_hndler->str_arr_size, sizeof(my_str), backward_compare);

        else if (mode = 'f')
            qsort(m_txt_hndler->str_array, m_txt_hndler->str_arr_size, sizeof(my_str), forward_compare);
        
        else return print_usage(argv[0]);
    }
    else if (sort_type == 's') {

        if (mode == 'b')
            sort(m_txt_hndler, backward_compare);

        else if (mode = 'f')
            sort(m_txt_hndler, forward_compare);
        
        else print_usage(argv[0]);
    }
    else print_usage(argv[0]);

    return 0;
}


