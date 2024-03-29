#ifndef _YIELD_H_
#define _YIELD_H_

#define MAGIC 0xDEADBEEF

enum state_e
{
    CTX_FINISHED,
    CTX_RUNNING,
    CTX_INITIALIZED
};

typedef void (func_t)(void*);

struct ctx_s
{
    void* ctx_esp;
    void* ctx_ebp;
    func_t* ctx_f;
    void* ctx_args;
    void* ctx_stack;
    enum state_e ctx_state; 
    int ctx_magic;
    struct ctx_s* ctx_next;
};

int create_ctx(int stack_size, func_t f, void* args);

void yield();

#endif
