#include <stdio.h>
#include <stdlib.h>
#include "avl/avl.h"


int main() { //simple test of structures
	Tree *tree = tree_make();
	tree_insert(tree,2);
	tree_insert(tree,1);
	tree_insert(tree,4);
	tree_insert(tree,6);
	tree_insert(tree,3);
	tree_insert(tree,8);
	tree_insert(tree,10);
	tree_insert(tree,11);

	tree_print(tree);
	tree_destroy(tree);
	
	return 0;
}


