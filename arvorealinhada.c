#include <stdio.h>
#include <stdlib.h>

// Definição de um nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para imprimir a árvore binária de maneira alinhada
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    // Aumenta o espaço entre os níveis
    space += 3;

    // Imprime a subárvore direita primeiro
    printTree(root->right, space);

    // Imprime o nó atual após os espaços
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Imprime a subárvore esquerda
    printTree(root->left, space);
}

// Função para realizar a travessia em ordem (in-order traversal)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Primeiro visita a subárvore esquerda
    inorderTraversal(root->left);

    // Em seguida, imprime o valor da raiz
    printf("%d ", root->data);

    // Por fim, visita a subárvore direita
    inorderTraversal(root->right);
}

int main() {
    // Criando a árvore binária
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Exibindo a árvore alinhada
    printf("Árvore binária alinhada:\n");
    printTree(root, 0);

    // Realizando a traversal em ordem (in-order) e exibindo os valores
    printf("\nTraversal em ordem (In-order):\n");
    inorderTraversal(root);  // Exibe os valores na ordem crescente
    printf("\n");

    return 0;
}
