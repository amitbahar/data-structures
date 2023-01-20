/**
 * @file btree.h
 * @author Amit Bajar
 * @brief interface for a simple (d,2d) b tree holding integer keys and values
*/

#ifndef BTREE_HEADER
#define BTREE_HEADER

typedef struct BTreeNode {
	int d;
	int *keys;
	BTreeNode *children;
} BTreeNode;

typedef struct BTree {
	BTreeNode *root;
} BTree;

BTree* btree_make(); //make empty avl tree

void btree_destroy(BTree*); //free memory of b tre 

#endif
