#include <stdio.h>
#include <stdlib.h>
#include "avl/avl.h"
#include "heap/heap.h"
#include "list/list.h"


int main() { //simple test of structures
	Tree *tree = tree_make();
	tree_insert(tree,8);
	tree_insert(tree,10);
	tree_insert(tree,20);
	tree_insert(tree,40);
	tree_insert(tree,7);
	tree_insert(tree,-1);
	tree_insert(tree,15);
	tree_insert(tree,-30);

	tree_print(tree);
	tree_destroy(tree);
	
	return 0;
}


