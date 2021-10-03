#include "text_sortion.hh"

void print_usage(char* pathname) {
    printf("USAGE: %s src_file\n", pathname);
}

int main(int argc, char** argv) {

    TextHandler m_txt_hndler{};
    ErrProc m_err_hndler{};
    m_err_hndler.type = NONE;

    buf_load(&m_txt_hndler, "/home/uslsteen/Code/share_mipt/Problem_TS/hello.txt", &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return -1;
    }

    my_str_arr_construct(&m_txt_hndler, &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return -1;
    }

#if 0
    qsort(m_txt_hndler.str_array, m_txt_hndler.str_arr_size, sizeof(my_str), forward_compare);
#endif

    sort(&m_txt_hndler);
    
    get_sorted_txt("/home/uslsteen/Code/share_mipt/Problem_TS/sorted_text.txt", &m_txt_hndler, &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return -1;
    }

    destructor(&m_txt_hndler);
    return 0;
}