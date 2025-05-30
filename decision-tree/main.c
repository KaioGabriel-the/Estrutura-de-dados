#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    char question[100];
    struct Node* yes;
    struct Node* no;
} Node;

// Função para criar um novo nó
Node* createNode(const char* question) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->question, question);
    node->yes = NULL;
    node->no = NULL;
    return node;
}

// Função para percorrer a árvore de decisão
void traverse(Node* node) {
    if (node->yes == NULL && node->no == NULL) {
        printf("Diagnóstico: %s\n", node->question);
        return;
    }

    char answer[10];
    printf("%s (Y/N): ", node->question);
    scanf("%s", answer);

    if (strcmp(answer, "Y") == 0) {
        traverse(node->yes);
    } else if (strcmp(answer, "N") == 0) {
        traverse(node->no);
    } else {
        printf("Resposta inválida. Tente novamente.\n");
        traverse(node);  // Repergunta
    }
}

// Função principal
int main() {
    // Criando manualmente a árvore de decisão
    Node* root = createNode("Você está com febre?");
    root->yes = createNode("Você está com dor no corpo?");
    root->no = createNode("Você está com alergia?");

    root->yes->yes = createNode("Pode ser gripe.");
    root->yes->no = createNode("Pode ser resfriado leve.");
    root->no->yes = createNode("Pode ser reação alérgica.");
    root->no->no = createNode("Você está saudável.");

    // Iniciando o diagnóstico
    traverse(root);

    // Liberação de memória (não otimizado para simplificação)
    free(root->yes->yes);
    free(root->yes->no);
    free(root->no->yes);
    free(root->no->no);
    free(root->yes);
    free(root->no);
    free(root);

    return 0;
}
