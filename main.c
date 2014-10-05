#include "start_schedule.h"
#include "yield.h"
#include <stdio.h>
#include <stdlib.h>

void f_ping(void *arg);
void f_pong(void *arg);

int main(int argc, char *argv[])
{
    create_ctx(16384, f_ping, NULL);
    create_ctx(16384, f_pong, NULL);
    
    start_schedule();

    exit(EXIT_SUCCESS);
}

void f_ping(void *args)
{
    int i = 0;
    while(i < 500000) {
        printf("A");
        printf("B");
        printf("C");
        i++;
    }
}

void f_pong(void *args)
{
    int i = 0;
    while(i < 250000) {
        printf("1");
        printf("2");
        i++;
    }
}
