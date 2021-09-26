#include "text_sortion.hh"

void print_usage() {

}

int main(int argc, char** argv) {
    if (argc != 2) {
        print_usage();
        return -1; // delete magic consts    
    }

    TextHandler m_txt_hndler{};

    buf_load(&m_txt_hndler, argv[1]);
    my_str_arr_construct(&m_txt_hndler);
}