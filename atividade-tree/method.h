#ifndef METHOD_H
#define METHOD_H

#include <stdio.h>
#include "atividade-tree/tree.h"

void run(TREE A){
	if (A == NULL) return;

	printf("%d", A->item);
	run(A->left);
	run(A->right);	
}

void inorder(TREE tree){
    if(tree == NULL) return;

    inorder(tree->left);
    printf("%d", tree->item);
    inorder(tree->right);
}

void beroreorder(TREE tree){
    if(tree == NULL) return;

    printf("%d", tree->item);
    inorder(tree->left);
    inorder(tree->right);
}

void thenorder(TREE tree){
    if(tree == NULL) return;

    inorder(tree->left);
    inorder(tree->right);
    printf("%d", tree->item);
}

void destroy(TREE *tree){
    if(*tree == NULL) return;
    destroy(&(*tree) ->left);
    destroy(&(*tree) ->right);

    free(*tree);
    *tree = NULL;
}

void addtree(Item item, TREE *tree){
    if(*tree == NULL){
     *tree = (TREE) malloc (sizeof(struct Tree));
     (*tree)->item = item;
     (*tree)->left = NULL;
     (*tree)->right = NULL;
    }else if( item = (*tree)->item) addtree(item, &(*tree)->left);
    else addtree(item, &(*tree)->right);
    
}

void search(Item item, TREE tree){
    if (tree == NULL) return 0;
    else if ( item = tree->item) return 1;
    else if ( item <= tree->item) return search (item, tree->left);
    else return search(item, tree->right);
}

#endif