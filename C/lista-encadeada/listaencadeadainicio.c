#include <stdio.h>
#include <stdlib.h>

typedef struct ListaNo{
  int num; //um numero inteiro qualquer
  struct ListaNo *prox;  //ponteiro pro proximo elemento
}*NO;

//ato de criar a lista e ao mesmo o ato de inserir no começo
NO criarNo(int numero,NO lista ){
    NO nozinho = (NO)malloc(sizeof(struct ListaNo));
    if(nozinho == NULL) return NULL; //provavelmente tá errada
    nozinho->num = numero;
    nozinho->prox = lista; // [nozinho] -> [lista] -> [2] -> [7]
    return nozinho;
}

void exibir(NO lista){
    NO auxiliar = lista;
    while (auxiliar != NULL){
        printf("%d\n",auxiliar->num);
        auxiliar = auxiliar->prox;
    }    
}
//criar a lista
//incerção no começo
//inserção no final dela
//inserção de forma ordenada

int main(int argc, char* args[]){
    NO head = NULL;
    head = criarNo(1,head);
    head = criarNo(4,head);
    exibir(head);
}