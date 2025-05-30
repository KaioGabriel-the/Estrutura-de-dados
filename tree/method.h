#ifndef METHOD_H
#define METHOD_H

#include <stdio.h>
#include "tree.h"

void inorder(BRANCH A){
	if (A == NULL) return;

	inorder(A->left);
	printf("%d ", A->number);
	inorder(A->right);
}

void preorder(BRANCH A){
	if (A == NULL) return;

	printf("%d ", A->number);
	preorder(A->left);
	preorder(A->right);
}

void postorder(BRANCH A){
	if (A == NULL) return;

	postorder(A->left);
	postorder(A->right);
	printf("%d ", A->number);
}

void run(BRANCH A){
	if (A == NULL) return;

	printf("%d", A->number);
	run(A->left);
	run(A->right);	
}

#endif