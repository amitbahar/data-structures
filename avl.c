#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return a < b ? b : a;
}



typedef struct Node {
	struct Node *plr[3]; //parent-left-right
	int dhv[3]; //data-height-virtual
} Node;

typedef struct Tree {
	Node *head;
	Node *virtual;
} Tree;


Tree * makeTree() {
	Node *virtual = (Node *)malloc(sizeof(Node)); 
	*virtual = (Node){{NULL,NULL,NULL},0,-1,1}; //construct virtual node
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	*tree = (Tree){NULL,virtual}; //head is null at initialization
	return tree;
}

void _destroyrec(Node *head) { //recursive function to free memory of tree
	if (head == NULL) {
		return;
	} else {
		_destroyrec(head->plr[1]);
		_destroyrec(head->plr[2]);
		free(head);
		return;
	}
}

void destroy(Tree *tree) {
	_destroyrec(tree->head);
	return;
}

void _rrotate(Node *node) {
	Node *lson = node->plr[1]; //pointer to left son
	if (node->plr[0]->plr[1] == node) { //parent of node points to lson
		node->plr[0]->plr[1] = lson;
	} else {
		node->plr[0]->plr[2] = lson;
	}
	lson->plr[0] = node->plr[0]; //lson points to parent of node
	node->plr[1] = lson->plr[2]; //new left child of node is right child of lson
	node->plr[1]->plr[0] = node; //update parent of left son of node
	node->plr[0] = lson; //new parent of node is lson
	lson->plr[2] = node; //new right child of lson is node
	
	node->dhv[1] = max(node->plr[1]->dhv[1],node->plr[2]->dhv[1])+1; //update heights of node first (important) then lson
	lson->dhv[1] = max(lson->plr[1]->dhv[1],lson->plr[2]->dhv[1])+1;
}

void _lrotate(Node *node) { //symetric to right rotate
	Node *rson = node->plr[2];
	if (node->plr[0]->plr[1] == node) {
		node->plr[0]->plr[1] = rson;
	} else {
		node->plr[0]->plr[2] = rson;
	}
	rson->plr[0] = node->plr[0]; 
	node->plr[2] = rson->plr[1];
	node->plr[2]->plr[0] = node;
	node->plr[0] = rson; 
	rson->plr[1] = node;
	
	node->dhv[1] = max(node->plr[1]->dhv[1],node->plr[2]->dhv[1])+1;
	rson->dhv[1] = max(rson->plr[1]->dhv[1],rson->plr[2]->dhv[1])+1;
	
}

void _rlrotate(Node *node) {
	_rrotate(node->plr[2]);
	_lrotate(node);
}

void _lrrotate(Node *node) {
	_lrotate(node->plr[1]);
	_rrotate(node);
}

void insert(Tree *tree, int data) {
	Node *new = (Node *)malloc(sizeof(Node)); //creating the new node
	new->plr[0] = NULL;
	new->plr[1] = tree->virtual;
	new->plr[2] = tree->virtual;
	new->dhv[0] = data;
	new->dhv[1] = 0;
	new->dhv[2] = 0;
	Node *tmp = tree->head; //pointer
	Node *tmpparent; //parent of pointer
	
	if (tmp == NULL) { //edge case tree is empty
		tree->head = new;
		return;
	} else {
		while (tmp->dhv[2] != 1) { //traverse down as long as current is not virtual
			tmpparent = tmp;
			if (tmp->dhv[0] <= data) {
				tmp = tmp->plr[1];
			} else {
				tmp = tmp->plr[2];
			}
		}
		
		if (tmpparent->plr[1] = tmp) { //insert new node instead of virtual
			tmpparent->plr[1] = new;
		} else {
			tmpparent->plr[2] = new;
		}
		new->plr[0] = tmpparent; //update the parent of new node
		
		while (tmpparent != NULL) { //going up and updating heights+rotating
			tmpparent->dhv[1] = max(tmpparent->plr[1]->dhv[1],tmpparent->plr[2]->dhv[1])+1; //update current height
			if (tmpparent->plr[1]->dhv[1]-tmpparent->plr[2]->dhv[1] > 1) { //checking on bf and rotating accordingly
				if (tmpparent->plr[1]->plr[1]->dhv[1]-tmpparent->plr[1]->plr[2]->dhv[1] == 1)
					_rrotate(tmpparent);
				else
					_lrrotate(tmpparent);
				return; //one rotation is enough, no need to update further heights
			} else if (tmpparent->plr[1]->dhv[1]-tmpparent->plr[2]->dhv[1] < -1){
				if (tmpparent->plr[2]->plr[1]->dhv[1]-tmpparent->plr[2]->plr[2]->dhv[1] == 1)
					_rlrotate(tmpparent);
				else 
					_lrotate(tmpparent);
				return;
			}
			tmpparent = tmpparent->plr[0];
		}
	}
}

void _printree(Node *node) {
	if (node == NULL) {
		return;
	} else {
		_printree(node->plr[1]);
		printf("%d->",node->dhv[0]);
		_printree(node->plr[2]);
	}
	printf("\n");
}

void printree(Tree *tree) {
	_printree(tree->head);
}






