#include "avl/avl.h"
#include "list/list.h"
#include <stdio.h>

int main() { //simple test of structures
	Tree *tree = tree_make();
	List *list = list_make();
	for (int i = 0; i <10; ++i) {
		list_insert(list,i,list_length(list));
		tree_insert(tree,i);
	}
	printf("Print List values:\n");
	list_print(list);
	list_destroy(list);
	printf("Print Tree values:\n");
	tree_print(tree);
	tree_destroy(tree);
	
	return 0;
}


