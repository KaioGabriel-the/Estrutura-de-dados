#include <stdio.h>
#include <stdlib.h>

typedef struct ListNo {
    int element;
    struct ListNo *prox;
} *NO;

// Função para criar um novo nó
NO criarNo(int elementList) {
    NO no = malloc(sizeof(struct ListNo));
    if (no == NULL) {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }

    no->element = elementList;
    no->prox = NULL; // Inicialmente, o próximo nó é NULL, pois é o último nó.

    return no;
}

// Função para adicionar um nó no início da lista
NO adicionarNoInicio(NO list, int elementList) {
    NO novoNo = criarNo(elementList);
    if (novoNo == NULL) {
        return list; // Retorna a lista original se a alocação falhar.
    }

    novoNo->prox = list; // Faz o novo nó apontar para o início da lista existente.
    return novoNo; // Retorna o novo nó como o novo início da lista.
}

// Função para imprimir a lista
void printList(NO list) {
    NO auxiliar = list;
    while (auxiliar != NULL) {
        printf("%d ", auxiliar->element);
        auxiliar = auxiliar->prox;
    }
    printf("\n"); // Adiciona uma quebra de linha após a lista.
}

NO inverso(NO list) {
    NO no = list;
    NO newHead = NULL;

    while (no != NULL) {
        newHead = adicionarNoInicio(newHead, no->element);
        no = no->prox;
    }

    return newHead;
}

int main() {
    NO head = NULL; // Inicializa a lista como NULL.

    // Adiciona elementos à lista, inserindo no início.
    head = adicionarNoInicio(head, 10);
    head = adicionarNoInicio(head, 20);
    head = inverso(head);

    // Imprime a lista para verificar a saída.
    printList(head);

    return 0;
}
