#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BRANCH{
    int number;
    struct BRANCH *left;
    struct BRANCH *right;
} *BRANCH;

BRANCH create_tree(int number, BRANCH left, BRANCH right){
    BRANCH tree = (BRANCH) malloc (sizeof( struct BRANCH));

    if (tree == NULL){
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    
    tree->number = number;
    tree->left = left;
    tree->right = right;
    return tree;
}

#endif