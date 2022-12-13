#include "avl.h"
#include <stdio.h>

int main() {
	Tree *tree = makeTree();
	insert(tree,1);
	insert(tree,2);
	insert(tree,3);
	printree(tree);
	destroy(tree);
	return 0;
}


