#ifndef METHOD_H
#define METHOD_H

#include <stdio.h>
#include "tree.h"

void run(BRANCH A){
	if (A == NULL) return;

	printf("%d", A->number);
	run(A->left);
	run(A->right);	
}

#endif