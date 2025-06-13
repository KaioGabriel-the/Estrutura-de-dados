#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define DISTANCIA 5

// Definição de um nó da árvore
typedef struct ArvoreNo {
    int valor;
    struct ArvoreNo* left;
    struct ArvoreNo* right;
} ArvoreNo;

// Função para criar um novo nó
ArvoreNo* novoNo(int valor) {
    ArvoreNo* no = (ArvoreNo*)malloc(sizeof(ArvoreNo));
    no->valor = valor;
    no->left = no->right = NULL;
    return no;
}

// Altura da árvore
int altura(ArvoreNo* raiz) {
    if (!raiz) return 0;
    int esq = altura(raiz->left);
    int dir = altura(raiz->right);
    return (esq > dir ? esq : dir) + 1;
}

// Imprime espaços
void printEspacos(int count) {
    for (int i = 0; i < count; i++) printf(" ");
}

void imprimirArvore(ArvoreNo* raiz) {
    if (!raiz) return;

    int h = altura(raiz);
    int maxN = (int)pow(2, h) - 1;
    ArvoreNo** nivelAtual = (ArvoreNo**)malloc(maxN * sizeof(ArvoreNo*));
    ArvoreNo** proximoNivel = (ArvoreNo**)malloc(maxN * sizeof(ArvoreNo*));

    for (int i = 0; i < maxN; i++) {
        nivelAtual[i] = NULL;
        proximoNivel[i] = NULL;
    }
    nivelAtual[0] = raiz;

    int largura = 2; // largura base para imprimir os números

    for (int nivel = 0; nivel < h; nivel++) {
        int nodes = (int)pow(2, nivel);
        int gap = (int)pow(2, h - nivel) - 1;

        // Espaço inicial para centralizar o primeiro nó do nível
        printEspacos(gap * largura / 2);

        for (int i = 0; i < nodes; i++) {
            if (nivelAtual[i]) {
                printf("%2d", nivelAtual[i]->valor);
            } else {
                printEspacos(2);
            }
            printEspacos(gap * largura);
        }
        printf("\n");

        // Imprime os ramos só se não for o último nível
        if (nivel < h - 1) {
            printEspacos(gap * largura / 2);
            for (int i = 0; i < nodes; i++) {
                if (nivelAtual[i]) {
                    if (nivelAtual[i]->left)
                        printf("/");
                    else
                        printEspacos(1);

                    printEspacos(largura - 2);

                    if (nivelAtual[i]->right)
                        printf("\\");
                    else
                        printEspacos(1);
                } else {
                    printEspacos(largura);
                }
                printEspacos(gap * largura);
            }
            printf("\n");
        }

        // Prepara próximo nível
        int idx = 0;
        for (int i = 0; i < nodes; i++) {
            if (nivelAtual[i]) {
                proximoNivel[idx++] = nivelAtual[i]->left;
                proximoNivel[idx++] = nivelAtual[i]->right;
            } else {
                proximoNivel[idx++] = NULL;
                proximoNivel[idx++] = NULL;
            }
        }

        ArvoreNo** temp = nivelAtual;
        nivelAtual = proximoNivel;
        proximoNivel = temp;
    }

    free(nivelAtual);
    free(proximoNivel);
}


// Função para visitar o nó (exibindo o valor)
void visit(ArvoreNo* p) {
    printf("%d ", p->valor);
}

// Função Morris Inorder para travessar a árvore
void MorrisInorder(ArvoreNo* root) {
    ArvoreNo* p = root;
    ArvoreNo* tmp;

    while (p != NULL) {
        // Se não houver filho à esquerda
        if (p->left == NULL) {
            visit(p);  // Visita o nó
            p = p->right;  // Mova para o nó à direita
        } else {
            tmp = p->left;
            // Encontre o maior nó à esquerda
            while (tmp->right != NULL && tmp->right != p) {
                tmp = tmp->right;
            }

            // Crie um link temporário, se ainda não existir
            if (tmp->right == NULL) {
                tmp->right = p;
                p = p->left;  // Mova-se para o filho à esquerda
            } else {
                visit(p);  // Visite o nó
                tmp->right = NULL;  // Restaure a estrutura original
                p = p->right;  // Mova-se para o nó à direita
            }
        }
    }
}

// Função para inserir um nó na árvore binária de busca
ArvoreNo* inserir(ArvoreNo* root, int valor) {
    if (root == NULL) {
        return novoNo(valor);
    }

    if (valor < root->valor) {
        root->left = inserir(root->left, valor);
    } else {
        root->right = inserir(root->right, valor);
    }

    return root;
}

// Função auxiliar para imprimir do nó 'start' até 'end' no caminho inverso
void imprimirCaminhoReverso(ArvoreNo* start, ArvoreNo* end) {
    ArvoreNo* noAtual = start;
    ArvoreNo* proximo = start->right;
    ArvoreNo* temp;

    // Inverte o caminho de start até end
    while (noAtual != end) {
        temp = proximo->right;
        proximo->right = noAtual;
        noAtual = proximo;
        proximo = temp;
    }

    // Imprime os nós do caminho invertido
    noAtual = end;
    while (1) {
        visit(noAtual);
        if (noAtual == start) break;
        noAtual = noAtual->right;
    }

    // Restaura a ordem original invertendo novamente
    noAtual = end;
    proximo = end->right;
    while (noAtual != start) {
        temp = proximo->right;
        proximo->right = noAtual;
        noAtual = proximo;
        proximo = temp;
    }
}

// Travessia Morris Pós-ordem sem nó dummy
void MorrisPretorder(ArvoreNo* raiz) {
    ArvoreNo* atual = raiz;
    ArvoreNo* predecessor;

    while (atual != NULL) {
        if (atual->left == NULL) {
            // Nada a visitar aqui, só avançar para direita
            atual = atual->right;
        } else {
            predecessor = atual->left;
            // Encontra o predecessor (nó mais à direita da subárvore esquerda)
            while (predecessor->right != NULL && predecessor->right != atual) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Cria link temporário para voltar ao atual depois
                predecessor->right = atual;
                atual = atual->left;
            } else {
                // Remove link temporário e visita os nós da subárvore esquerda em pós-ordem invertida
                imprimirCaminhoReverso(atual->left, predecessor);
                predecessor->right = NULL;
                atual = atual->right;
            }
        }
    }

    // Depois do loop, visita a raiz em pós-ordem
    if (raiz != NULL) {
        predecessor = raiz;
        while (predecessor->right != NULL) predecessor = predecessor->right;
        imprimirCaminhoReverso(raiz, predecessor);
    }
}


// Função para testar o código
int main() {
    ArvoreNo* root = NULL;

    // Inserindo elementos na árvore
    root = inserir(root, 10);
    root = inserir(root, 5);
    root = inserir(root, 3);
    root = inserir(root, 7);
    root = inserir(root, 20);
    root = inserir(root, 15);
    root = inserir(root, 24);
    
    imprimirArvore(root);    // Chamando a travessia Morris Inorder
    printf("Resultado da travessia Morris Inorder: ");
    MorrisInorder(root);
    printf("\n");
    printf("Resultado da travessia Morris Postorder: ");
    MorrisPretorder(root);
    printf("\n");

    return 0;
}
