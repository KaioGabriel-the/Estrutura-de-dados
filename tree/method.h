#ifndef METHOD
#define METHOD

#include <stdio.h>
#include "tree.h"

void run(BRANCH A){
	if (A == NULL) return;

	printf("%d", A->number);
	percorre(A->left);
	percorre(A->right);	
}

#endif