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

    size_t str_arr_size = START_SIZE; 

    txt_handler->str_array = (my_str *) calloc(str_arr_size, sizeof(my_str));
    assert(txt_handler->str_array);

    char* prev_str_end = nullptr;
    ssize_t new_byte_size = txt_handler->byte_size;

    size_t cur_str_size = 0;
    
    char* str_start = txt_handler->text_buffer;;
    char* str_end = (char*) memchr(str_start, '\n', new_byte_size); 


    for (; str_end != NULL; ++cur_str_size) {
        
        if (str_end - 1 == prev_str_end && *prev_str_end == '\n')
            while (!isalpha(*str_end))
                ++str_end;

        txt_handler->str_array[cur_str_size].begin = str_start;
        txt_handler->str_array[cur_str_size].size = str_end - str_start + 1;

        new_byte_size = new_byte_size - (str_start - txt_handler->text_buffer);
        str_start = str_end + 1;

        prev_str_end = str_end;
        str_end = (char*)memchr(str_start, '\n', new_byte_size);
    
        if (is_need_allocate(cur_str_size, str_arr_size))   
            str_array_realloc(txt_handler->str_array, &str_arr_size); 
    }

    txt_handler->str_arr_size = cur_str_size;
}