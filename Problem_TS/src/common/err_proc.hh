#ifndef ERR_PROC_HH
#define ERR_PROC_HH

#include <stdio.h>
#include <assert.h>

struct TextHandler;

enum ERR_TYPE {

    NONE = 1,
    FOPEN_NEG,
    FREAD_NEG, 
    FSEEK_NEG,
};

struct ErrProc {
    char* err_msg;
    ERR_TYPE type;
};

void err_proc(ErrProc* err_proc, TextHandler* txt_handler);


#endif /* ERR_PROC_HH */