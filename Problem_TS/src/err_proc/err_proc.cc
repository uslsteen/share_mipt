#include "err_proc.hh"


void err_proc(ErrProc* err_proc, TextHandler* txt_handler) {

    assert(err_proc);
    assert(txt_handler);

    switch (err_proc->type)
    {

    case NONE: break;

    case FOPEN_NEG: perror(err_proc->err_msg);
        break;

    case FREAD_NEG: perror(err_proc->err_msg);
        break;

    case FSEEK_NEG: perror(err_proc->err_msg);
        break;
        
    default: perror("Undefined error\n");
        break;
    }
}
