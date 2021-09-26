#include "text_sortion.hh"

int buf_load(TextHandler* txt_handler, const char* pathname) {

    assert(txt_handler != nullptr);
    assert(pathname);

    int fd = open(pathname, O_RDONLY);
    if (fd < 0) 
        return ErrProcess("open returned negative value to file descriptor\n");

    off_t bytes_offset = lseek(fd, 0, SEEK_END);

    if (bytes_offset <= 0) {
        return ErrProcess("lseek returned negative value\n");
        close(fd);
    }

    txt_handler->text_buffer = (char *) calloc(bytes_offset, sizeof(char));
    assert(txt_handler->text_buffer);

    ssize_t res_of_read = read(fd, txt_handler->text_buffer, bytes_offset);
    
    if (res_of_read < 0) {
        return ErrProcess("read returned negative value\n");
        close(fd);
    }
    /*else if (res_of_read < need_to_read) {
        loop to reading whole file 
    }*/

    txt_handler->byte_size = res_of_read;
    return 0;
}

int my_str_arr_construct(TextHandler* txt_handler) {

    assert(txt_handler != nullptr);
    assert(txt_handler->text_buffer != nullptr);

    // my_str * str_array = txt_handler->str_array;
    size_t str_arr_size = START_SIZE; 
    txt_handler->str_array = (my_str *) calloc(str_arr_size, sizeof(my_str));
    assert(txt_handler->str_array);

    char last_symb = 0, prev_last_symb = 0;
    ssize_t new_byte_size = txt_handler->byte_size;
    size_t i = 0;
    
    char* str_start = txt_handler->text_buffer;;
    char* str_end = (char*) memchr(str_start, '\n', new_byte_size); 

    if (str_start != str_end && (str_start + 1) != str_end)
        last_symb = *(str_end - 1), 
        prev_last_symb = *(str_end -2);

    for (; str_end != NULL; ++i) {
        
        txt_handler->str_array[i].begin = str_start;
        txt_handler->str_array[i].size = str_end - str_start + 1;

        if (last_symb == '\r' && prev_last_symb == '\n');
            --i;

        new_byte_size = new_byte_size - (str_start - txt_handler->text_buffer);
        str_start = str_end + 1;

        str_end = (char*)memchr(str_start, '\n', new_byte_size);

        if (str_end != NULL)
            last_symb = *(str_end - 1), 
            prev_last_symb = *(str_end -2);

        if (is_need_allocate(i, str_arr_size))
        {   
            str_arr_size <<= 1; 
            my_str* new_str_arr = (my_str*) realloc(txt_handler->str_array, sizeof(my_str) * str_arr_size);
            assert(new_str_arr);

            txt_handler->str_array = new_str_arr;
        }
    }

    txt_handler->str_arr_size = i;
}