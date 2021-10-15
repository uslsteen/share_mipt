#include "text_sortion.hh"


int buf_load(TextHandler* txt_handler, const char* pathname, ErrProc* err_handler) {

    assert(txt_handler);
    assert(pathname);

    FILE* file = fopen(pathname, "rb");
    if (file == nullptr) {
        err_handler->type = FOPEN_NEG;
        err_handler->err_msg = "fopen(...) ret nullptr in buf_load(...)\n";
    }
        //return ErrProcess("open returned negative value to file descriptor\n");

    fseek(file, 0, SEEK_END);
    long bytes_offset = ftell(file);
    rewind(file);

    if (bytes_offset <= 0) {
        err_handler->type = FSEEK_NEG;
        //return ErrProcess("fseek returned negative value\n");
        fclose(file);
    }

    txt_handler->text_buffer = (char *)calloc(bytes_offset + 1, sizeof(txt_handler->text_buffer[0]));
    assert(txt_handler->text_buffer);

    size_t res_of_read = fread(txt_handler->text_buffer, sizeof(txt_handler->text_buffer[0]), bytes_offset, file);

    if (res_of_read <= 0) {
        err_handler->type = FREAD_NEG;
        err_handler->err_msg = "fread(...) ret negative val in buf_load(...)\n";
        fclose(file);
    }

    txt_handler->byte_size = res_of_read;
    return 0;
}

void get_str_num(TextHandler* txt_handler) {

    assert(txt_handler);
    assert(txt_handler->text_buffer);

    size_t cur_size = txt_handler->byte_size;
    char* cur_str = (char*)memchr(txt_handler->text_buffer, '\n', cur_size);

    while (cur_str != NULL) {
        ++txt_handler->str_arr_size;
        cur_str = (char*)memchr(cur_str + 1, '\n', cur_size - (cur_str - txt_handler->text_buffer) - 1);
    }

    ++txt_handler->str_arr_size;
}

void my_str_arr_construct(TextHandler* txt_handler, ErrProc* err_handler) {

    assert(txt_handler);
    assert(txt_handler->text_buffer);

    get_str_num(txt_handler);

    txt_handler->str_array = (my_str*)calloc(txt_handler->str_arr_size, sizeof(my_str));
    assert(txt_handler->str_array);

    size_t i = 0;

    char *start = txt_handler->text_buffer;
    char *cur_symb = (char*)memchr(start, '\n', txt_handler->byte_size);

    for (; *cur_symb != '\0'; ++cur_symb) {

        if (*cur_symb == '\n') {

            my_str cur_str = {start, (size_t)(cur_symb - start)};            
            my_str_push(txt_handler->str_array, &i, &cur_str);

            start = cur_symb + 1;
        }
    }

    my_str cur_str = {start, (size_t)(cur_symb - start)};
    my_str_push(txt_handler->str_array, &i, &cur_str);
}

void sort(TextHandler* txt_handler, int (*comp)(const void* lhs, const void* rhs)) {

    assert(txt_handler);
    assert(txt_handler->str_array);

    size_t low = 0, high = txt_handler->str_arr_size - 1;
    q_sort(txt_handler->str_array, low, high, comp);
}

void str_array_realloc(my_str* str_array, size_t* str_arr_size, enum ALLOCA_PARAMS flag) {

    assert(str_array);
    assert(str_arr_size);

    if (flag)
        *str_arr_size <<= 1; 

    my_str* new_str_arr = (my_str*) realloc(str_array, sizeof(my_str) * (*str_arr_size));
    assert(new_str_arr);

    str_array = new_str_arr;
}

void get_sorted_txt(const char* pathname, TextHandler* txt_handler, ErrProc* err_handler) {

	assert(pathname);
    assert(txt_handler);
    assert(txt_handler->str_array);

    size_t num_of_str = txt_handler->str_arr_size;

	FILE* file = fopen(pathname, "w+");

    if (file == nullptr) {
        err_handler->type = FOPEN_NEG;
        err_handler->err_msg = "fopen(...) return NULL in get_sorted_text(...)\n";
    }

	for (size_t i = 0; i < num_of_str; i++) {
        char* beg = txt_handler->str_array[i].begin;
        if (isspace(*beg))
            continue;

        fprintf(file, "%.*s\n", (int)txt_handler->str_array[i].size, beg);
    }

	fclose(file);
}


void destructor(TextHandler* txt_handler) {

    free(txt_handler->text_buffer);
    txt_handler->text_buffer = nullptr;

    free(txt_handler->str_array);
    txt_handler->str_array = nullptr;
}