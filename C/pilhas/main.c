#include <stdio.h>
#include "function.h"

int main(){
    PILHA p;

    inicializarPilha(&p);
    push(&p,10);
    push(&p,20);
    int element = pop(&p);
    printf("%d \n",element);
    printf("%d",top(&p));

    return 0;
}