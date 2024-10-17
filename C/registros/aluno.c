#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[20];
    float nota;
    struct Node *proximo;
} Aluno;

int main(void) {

    Aluno *aluno1 = (Aluno *) malloc(sizeof(Aluno));
    Aluno *aluno2 = (Aluno *) malloc(sizeof(Aluno));

    aluno1->mat = 10;
    strcpy(aluno1 -> nome, "Kaio");
    aluno1 -> nota = 5.5;

    aluno2->mat = 20;
    strcpy(aluno2 -> nome, "Gabriel");
    aluno2 -> nota = 7.5;

    aluno1 -> proximo = aluno2;
    aluno2 -> proximo = NULL;

    Aluno * atual = aluno1;

    while (atual != NULL) {
        printf("Matricula: %d \n", atual -> mat);
        printf("Nome: %s \n", atual -> nome);
        printf("Nota: %.2f \n", atual -> nota);
        atual = atual -> proximo;
    }
    return 0;
}