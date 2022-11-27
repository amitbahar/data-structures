#include "avl.h"

typedef struct Node {
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	int height;
	int data;
} Node;

typedef struct Tree {
	struct Node *head;
} Tree;

Tree * makeTree() {
	Tree tree = {NULL};
	return tree;
}

void destory(Tree *tree) {
	_destroyrec(tree->head);
	free(tree);
	return;
}

void _destroyrec(Node *head) {
	if (head == NULL) {
		return;
	} else {
		_destroyrec(head->left);
		_destroyrec(head->right);
		free(head);
		return;
	}
}

void insert(Tree *tree, int data) {
	
}



