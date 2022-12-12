#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void _rrotate();
void _lrotate();
void _rlrotate();
void _lrrotate();

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

void destroy(Tree *tree) {
	_destroyrec(tree->head);
	free(tree->virtual);
	free(tree);
	return;
}

void insert(Tree *tree, int data) {
	Node *new = (Node *)malloc(sizeof(Node));
	new->left = tree->virtual;
	new->right = tree->virtual;
	new->parent = NULL;
	new->height = 0;
	new->data = data;
	new->virtual = 0;
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
			tmpparent->height = (tmpparent->left->height)-(tmpparent->right->height);
			if (tmpparent->left->height-tmpparent->right->height > 1) {
				if (tmpparent->left->left->height-tmpparent->left->right->height > 1)
					_rrotate(tmpparent, tree);
				else
					_lrrotate(tmpparent, tree);
				return;
			} else if (tmpparent->left->height-tmpparent->right->height < -1){
				if (tmpparent->right->left->height-tmpparent->right->right->height > 1)
					_rlrotate(tmpparent, tree);
				else 
					_lrotate(tmpparent, tree);
				return;
			}
			tmpparent = tmpparent->parent;
		}
	}
}

void _rrotate(Node *node, Tree *tree) {
	Node *parent = node->parent;
	if (parent->left == node) {
		parent->left == node->left;
	} else {
		parent->right = node->left;
	}
	
	node->parent = node->left;
	node->left->parent = parent;
	node->left->right = node;
	node->left = tree->virtual;
	node->height = node->left->height > node->right->height ? node->left->height+1 : node->right->height+1;
	node->parent->height = node->height > node->parent->left->height ? node->height+1 : node->parent->left->height+1;
}

void _lrotate(Node *node, Tree *tree) {
	Node *parent = node->parent;
	if (parent->left == node) {
		parent->left == node->left;
	} else {
		parent->right = node->left;
	}
	
	node->parent = node->right;
	node->right->parent = parent;
	node->right->left = node;
	node->right = tree->virtual;
	node->height = node->left->height > node->right->height ? node->left->height+1 : node->right->height+1;
	node->parent->height = node->height > node->parent->right->height ? node->height+1 : node->parent->right->height+1;
}

void _rlrotate(Node *node, Tree *tree) {
	_rrotate(node->right,tree);
	_lrotate(node,tree);
}

void _lrrotate(Node *node, Tree *tree) {
	_lrotate(node->left,tree);
	_rrotate(node,tree);
}

void printree(Tree *tree) {
}

void inorder(Node *node) {
	if (node == NULL) {
		printf("empty\n'");
	} else {
		inorder(node->left);
		printf("%d",node->data);
		inorder(node->right);
	}
	printf("\n");
}




