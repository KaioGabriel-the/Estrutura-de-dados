#ifndef METHOD
#define METHOD

#include <stdio.h>
#include "tree.h"

void run(BRANCH branch){
	if (A == NULL) return;

	printf("%d", branch->number);
	run(branch->left);
	run(branch->right);	
}

#endif