#ifndef ERR_PROC_HH
#define ERR_PROC_HH

#include <stdio.h>
#include <assert.h>

struct TextHandler;

enum ERR_TYPE {

    ERR_EXIT = -1,
    NONE,
    FOPEN_NEG,
    FREAD_NEG, 
    FSEEK_NEG,
};

struct ErrProc {
    char* err_msg;
    ERR_TYPE type;
};

/**
 * @brief 
 * 
 * @param err_proc 
 * @param txt_handler 
 */
void err_proc(ErrProc* err_proc, TextHandler* txt_handler);


#endif /* ERR_PROC_HH */