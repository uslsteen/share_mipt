#include "text_sortion.hh"

int print_usage(char* pathname);
int my_get_opt(char** argv, TextHandler* m_txt_hndler);

int main(int argc, char** argv) {

    if (argc < 5) 
        return print_usage(argv[0]);

    TextHandler m_txt_hndler = {};
    ErrProc m_err_hndler = {};
    m_err_hndler.type = NONE;

    buf_load(&m_txt_hndler, argv[1], &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return ERR_EXIT;
    }

    my_str_arr_construct(&m_txt_hndler, &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return ERR_EXIT;
    }

    if (my_get_opt(argv, &m_txt_hndler) == ERR_EXIT)
    {
        destructor(&m_txt_hndler);
        return ERR_EXIT;
    }
 
    get_sorted_txt(argv[4], &m_txt_hndler, &m_err_hndler);

    if (m_err_hndler.type != NONE) {
        err_proc(&m_err_hndler, &m_txt_hndler);
        destructor(&m_txt_hndler);
        return ERR_EXIT;
    }

    destructor(&m_txt_hndler);
    return 0;
}   