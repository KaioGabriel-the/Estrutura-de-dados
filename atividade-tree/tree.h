#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef int Item;

typedef struct Tree{
    Item item;
    struct Tree *left;
    struct Tree *right;
} *TREE;

TREE create_tree(int number, TREE left, TREE right){
    TREE tree_new = (TREE) malloc (sizeof( struct Tree));

    if (tree_new == NULL){
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    
    tree_new->item = number;
    tree_new->left = left;
    tree_new->right = right;
    return tree_new;
}

#endif