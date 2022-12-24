/**
 * @file avl.h
 * @author Amit Bajar
 * @brief interface for a simple avl tree holding integer keys and values
*/

#ifndef AVL_HEADER
#define AVL_HEADER

typedef struct TreeNode {
	struct TreeNode *plr[3]; //parent-left-right
	int dhv[3]; //data-height-virtual
} TreeNode;

typedef struct Tree {
	TreeNode *head;
	TreeNode *virtual;
} Tree;

Tree* tree_make(); //make empty avl tree

void tree_destroy(Tree*); //deallocate avl tree

void tree_insert(Tree*, int); //insert element with value int

void tree_inorder(Tree*); //print integer values in order

void tree_print(Tree*); //print tree

#endif
