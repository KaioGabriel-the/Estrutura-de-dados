#include <stdio.h>
#include <stdlib.h>

char* mostrar(char array,size) {
    for(int i = 0; i < size; i++) {}
        printf("%c", array);
}
int main(void) {
    int size, optcion, elemento;
    int *number;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    number = (int *) malloc(size * sizeof(int));

    printf(" ----- MENU ----- \n1 - ADICIONAR \n2- REMOVER\n0 - SAIR");
    scanf("%d", &optcion);

    while (optcion == 0) {
        int qtd = 0;
        if (optcion == 1) {
            printf("Digite o elemento que desaja inserir: ");
            scanf("%d", &elemento);
            number[qtd] = elemento;
        }
        else if (optcion == 2) {
            mostrar(number, size);
            printf("Digite o elemento que desaja remover: ");
        }
    }
}
