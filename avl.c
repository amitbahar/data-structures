#include "avl.h"

typedef struct Node {
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	int height;
	int data;
	char virtual; //0 == no, 1 == yes
} Node;

typedef struct Tree {
	struct Node *head;
	struct Node *virtual;
} Tree;


Tree * makeTree() {
	Node *tmp = (Node *)malloc(sizeof(Node));
	*tmp = (Node){NULL,NULL,NULL,-1,0,1};
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	*tree = (Tree){NULL,tmp};
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
	Node *new = (Node *)malloc(sizeof(Node));
	new = (Node){tree->virtual,tree->virtual,NULL,0,data,0};
	Node *tmp = tree->head;
	Node *tmpparent;
	
	if (tmp == NULL) {
		tree->head = new;
		return;
	} else {
		while (tmp->virtual != 1) {
			tmpparent = tmp;
			if (tmp->data <= data) {
				tmp = tmp->left;
			} else {
				tmp = tmp->right;
			}
		}
		
		if (tmpparent->left = tmp) {
			tmpparent->left = new;
		} else {
			tmpparent->right = new;
		}
		new->parent = tmpparent;
		
		while (tmpparent != NULL) {
			tmpparent->height = tmpparent->left->height-tmpparent->right->height;
			tmpparent = tmpparent->parent;
		}
	}
}



