#include <stdio.h>
#include <stdlib.h>

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

    // Chamando a travessia Morris Inorder
    printf("Resultado da travessia Morris Inorder: ");
    MorrisInorder(root);
    printf("\n");

    return 0;
}
