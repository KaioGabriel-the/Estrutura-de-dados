#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
}PILHA;

void inicializarPilha(PILHA *p){
    p->top = -1;
}

bool estaVazia(PILHA *p){
    return p->top == -1;
}

void push(PILHA *p, int element){
    if(p->top < MAX - 1){
        p->top++;
        p->arr[p->top] = element;
    }else{
        printf("Pilha cheia |+ -|");
    }
}

int top(PILHA *p){
    return estaVazia(p) ? -1 : p->arr[p->top] ;  
}

int pop(PILHA *p) {
    if (estaVazia(p)) {
        printf("A lista está vazia \n");
        return -1;  // Retorna um valor de erro
    } else {
        int elemento = p->arr[p->top];
        p->top--;  // Decrementa o índice do topo
        return elemento;
    }
}
