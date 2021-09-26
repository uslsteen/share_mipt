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


}