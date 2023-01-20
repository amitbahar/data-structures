#include <stdio.h>
#include <stdlib.h>
#include "src/avltree/avltree.h"

int main() { //simple test of structures
	AVLTree *tree = avltree_make();
	avltree_insert(tree,8);
	avltree_insert(tree,10);
	avltree_insert(tree,20);
	avltree_insert(tree,40);
	avltree_insert(tree,7);
	avltree_insert(tree,-1);
	avltree_insert(tree,15);
	avltree_insert(tree,-30);

	avltree_print(tree);
	avltree_destroy(tree);
	
	return 0;
}


