/**
 * @file avltree.h
 * @author Amit Bajar
 * @brief interface for a simple avl tree holding integer keys 
*/

#ifndef AVLTREE_HEADER
#define AVLTREE_HEADER

typedef struct AVLTreeNode {
	struct AVLTreeNode *plr[3]; //parent-left-right
	int dhv[3]; //data-height-virtual
} AVLTreeNode;

typedef struct AVLTree {
	AVLTreeNode *head;
	AVLTreeNode *virtual;
} AVLTree;

AVLTree* avltree_make(); //make empty avl tree

void avltree_destroy(AVLTree*); //deallocate avl tree

void avltree_insert(AVLTree*, int); //insert element with value int

int avltree_min(AVLTree*); //get minimum key

int avltree_max(AVLTree*); //get maximum key

void avltree_inorder(AVLTree*); //print integer values in order

void avltree_print(AVLTree*); //print tree

#endif
