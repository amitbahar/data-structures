/**
 * @file avl.c
 * @author Amit Bajar
 * @brief interface implementation for a simple avl tree holding integer values that act as keys
*/

#include "../list/list.h"
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

//helper function
static int max(int a, int b) {
	return a < b ? b : a;
}

static int digits(int num) {
	int flag = 0;
	if (num < 0) {
		flag = 1; //if its negative we need 1 more digit for the -
		num *= -1;
	}

	int n = 0;
	while (0 < num) {
		num = num/10;
		++n;
	}
	return flag == 0 ? n : n+1;
}

static int mpow(int a, int b) {//a^b
	int result = 1;
	while (0 < b) {
		result *= a;
		--b;
	}
	return result;
}

static char* dtbin(int n, int num) {//decimal to binary
	char *string = (char*)malloc((n+1)*sizeof(char));
	char a;
	int i = 0;
	*(string+n) = '\0';
	while (0 < num) {
		if (num%2 == 1) {
			*(string+n-i-1) = '1';
		} else {
			*(string+n-i-1) = '0';
		}
		num = num / 2;
		++i;
	}
	while (0 < n - i) {
		++i;
		*(string+n-i) = '0';
	}

	return string;
	
}

/**
 * @brief makes an empty avl tree.
 * Time complexity: O(1)
 * @return empty avl tree
*/
Tree* tree_make() {
	TreeNode *virtual = (TreeNode *)malloc(sizeof(TreeNode)); 
	*virtual = (TreeNode){{NULL,NULL,NULL},0,-1,1}; //construct virtual node
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	*tree = (Tree){NULL,virtual}; //head is null at initialization
	return tree;
}

static void _destroyrec(TreeNode *head) { //recursive function to free memory of tree
	if (head->dhv[2] == 1) {
		return;
	} else {
		_destroyrec(head->plr[1]);
		_destroyrec(head->plr[2]);
		free(head);
		return;
	}
}

/**
 * @param tree
 * @brief deallocate memory of tree.
 * Time Complexity: O(size)
*/
void tree_destroy(Tree *tree) {
	_destroyrec(tree->head);
	return;
}

static void _rrotate(TreeNode *node, Tree *tree) {
	TreeNode *lson = node->plr[1]; //pointer to left son
	if (node->plr[0] == NULL) { //edge case no parent
		tree->head = lson;
		lson->plr[0] = NULL;
	} else {
		if (node->plr[0]->plr[1] == node) { //parent of node points to lson
			node->plr[0]->plr[1] = lson;
		} else {
			node->plr[0]->plr[2] = lson;
		}
		lson->plr[0] = node->plr[0]; //lson points to parent of node
	}
	node->plr[1] = lson->plr[2]; //new left child of node is right child of lson
	node->plr[1]->plr[0] = node; //update parent of left son of node
	node->plr[0] = lson; //new parent of node is lson
	lson->plr[2] = node; //new right child of lson is node
	
	node->dhv[1] = max(node->plr[1]->dhv[1],node->plr[2]->dhv[1])+1; //update heights of node first (important) then lson
	lson->dhv[1] = max(lson->plr[1]->dhv[1],lson->plr[2]->dhv[1])+1;
}

static void _lrotate(TreeNode *node, Tree *tree) { //symetric to right rotate
	TreeNode *rson = node->plr[2];
	if (node->plr[0] == NULL) {
		tree->head = rson;
		rson->plr[0] = NULL;
	} else {
		if (node->plr[0]->plr[1] == node) {
			node->plr[0]->plr[1] = rson;
		} else {
			node->plr[0]->plr[2] = rson;
		}
		rson->plr[0] = node->plr[0]; 
	}
	node->plr[2] = rson->plr[1];
	node->plr[2]->plr[0] = node;
	node->plr[0] = rson; 
	rson->plr[1] = node;
	
	node->dhv[1] = max(node->plr[1]->dhv[1],node->plr[2]->dhv[1])+1;
	rson->dhv[1] = max(rson->plr[1]->dhv[1],rson->plr[2]->dhv[1])+1;
}

static void _rlrotate(TreeNode *node, Tree *tree) {
	_rrotate(node->plr[2],tree);
	_lrotate(node,tree);
}

static void _lrrotate(TreeNode *node, Tree *tree) {
	_lrotate(node->plr[1], tree);
	_rrotate(node,tree);
}

/**
 * @param tree @param data
 * @brief inserts a new element with give data to tree.
 * Time complexity: O(height)
*/
void tree_insert(Tree *tree, int data) {
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode)); //creating the new node
	new->plr[0] = NULL;
	new->plr[1] = tree->virtual;
	new->plr[2] = tree->virtual;
	new->dhv[0] = data;
	new->dhv[1] = 0;
	new->dhv[2] = 0;
	TreeNode *tmp = tree->head; //pointer
	TreeNode *tmpparent; //parent of pointer
	
	if (tmp == NULL) { //edge case tree is empty
		tree->head = new;
		return;
	} else {
		while (tmp->dhv[2] != 1) { //traverse down as long as current is not virtual
			tmpparent = tmp;
			if (tmp->dhv[0] <= data) {
				tmp = tmp->plr[2];
			} else {
				tmp = tmp->plr[1];
			}
		}
		
		if (tmpparent->dhv[0] <= data) { //insert new node instead of virtual
			tmpparent->plr[2] = new;
		} else {
			tmpparent->plr[1] = new;
		}
		new->plr[0] = tmpparent; //update the parent of new node
		
		while (tmpparent != NULL) { //going up and updating heights+rotating
			tmpparent->dhv[1] = max(tmpparent->plr[1]->dhv[1],tmpparent->plr[2]->dhv[1])+1; //update current height
			if (tmpparent->plr[1]->dhv[1]-tmpparent->plr[2]->dhv[1] > 1) { //checking on bf and rotating accordingly
				if (tmpparent->plr[1]->plr[1]->dhv[1]-tmpparent->plr[1]->plr[2]->dhv[1] == 1)
					_rrotate(tmpparent, tree);
				else
					_lrrotate(tmpparent, tree);
				return; //one rotation is enough, no need to update further heights
			} else if (tmpparent->plr[1]->dhv[1]-tmpparent->plr[2]->dhv[1] < -1){
				if (tmpparent->plr[2]->plr[1]->dhv[1]-tmpparent->plr[2]->plr[2]->dhv[1] == 1)
					_rlrotate(tmpparent, tree);
				else 
					_lrotate(tmpparent, tree);
				return;
			}
			tmpparent = tmpparent->plr[0];
		}
	}
}

/**
 * @param tree
 * @return maximum value in tree
 * @warning tree MUST be None empty!
*/
int tree_max(Tree *tree) {
	TreeNode *ptr = tree->head;

	while (ptr->plr[2]->dhv[2] != 1) {
		ptr = ptr->plr[2];
	}

	return ptr->dhv[0];
}

/**
 * @param tree
 * @return minimum value in tree
 * @warning tree MUST be None empty!
*/
int tree_min(Tree *tree) {
	TreeNode *ptr = tree->head;

	while (ptr->plr[1]->dhv[2] != 1) {
		ptr = ptr->plr[1];
	}

	return ptr->dhv[0];
}

int _tree_height(TreeNode *node) {
	if (node->dhv[2] == 1) {//base case - virtual node has height -1
		return -1;
	}
	return 1 + max(_tree_height(node->plr[1]),_tree_height(node->plr[2]));
}

/**
 * @param tree
 * @return height of tree
 * @warning empty tree has height -1.
*/
int tree_height(Tree *tree) {
	if (tree->head == NULL) {
		return -1;
	}
	return _tree_height(tree->head);
}

static void _inorder(TreeNode *node) {
	if (node->dhv[2] == 1) {
		return;
	} else {
		_inorder(node->plr[1]);
		printf("%d->",node->dhv[0]);
		_inorder(node->plr[2]);
	}
}

/**
 * @param tree
 * @brief prints tree values in order.
 * Time complexity: O(size)
*/
void tree_inorder(Tree *tree) {
	_inorder(tree->head);
	printf("\n");
}

static int* values_depth_n(Tree *tree, int n) {
	int *arr = malloc(mpow(2,n)*sizeof(int)); //array of values
	if (n == 0) {
		*arr = tree->head->dhv[0];
		return arr;
	}
	char *num;
	for (int i = 0; i <= mpow(2,n)-1; ++i) {
		num = dtbin(n,i);
		TreeNode *ptr = tree->head;
		for (int j = 0; j < n; ++j) {
			if (*(num+j) == '0') {
				ptr = ptr->plr[1];
			} else {
				ptr = ptr->plr[2];
			}
			
			if (ptr->dhv[2] == 1) {
				*(arr+i) = -1; //does not matter because virtual at this place will make it xx..x
				break;
			}
		}
		if (ptr->dhv[2] == 0) {
			*(arr+i) = ptr->dhv[0];
		}
	}
	free(num);
	return arr;
}

static int* virtual_depth_n(Tree *tree, int n) {
	int *arr = malloc(mpow(2,n)*sizeof(int)); //[0,1,0,0,...1] whether the node is virtual or not at depth n
	if (n == 0) {
		*arr = tree->head->dhv[0];
		return arr;
	}
	char *num;
	for (int i = 0; i <= mpow(2,n)-1; ++i) {
		num = dtbin(n,i);
		TreeNode *ptr = tree->head;
		for (int j = 0; j < n; ++j) {
			if (*(num+j) == '0') {
				ptr = ptr->plr[1];
			} else {
				ptr = ptr->plr[2];
			}
			
			if (ptr->dhv[2] == 1) {
				*(arr+i) = 1;
				break;
			}
		}
		if (ptr->dhv[2] == 0) {
			*(arr+i) = 0;
		}
	}
	free(num);
	return arr;
}

static void treeprow_rec(int len, int n, int digit, int* values, int* virtual) {
	if (n == 1) {
		int padding = (len-digit*n)/(n+1);
		int value = *values;
		printf("%*s", padding, "");
		if (*virtual != 1) {
			printf("%0*d",digit,value);
		} else {
			char x[digit+1];
			for (int i = 0; i < digit; ++i) {
				x[i] = 'x';
			}
			x[digit] = '\0';
			printf("%s",x);
		}
		printf("%*s", padding, "");
		return;
	} else {
		int values1[n/2];
		int values2[n/2];
		int virtual1[n/2];
		int virtual2[n/2];

		for (int i = 0; i < n/2; ++i) {
			values1[i] = *(values+i);
			virtual1[i] = *(virtual+i);
		}
		for (int i = n/2; i < n; ++i) {
			values2[i-n/2] = *(values+i);
			virtual2[i-n/2] = *(virtual+i);
		}

		treeprow_rec((len-1)/2, n/2, digit, values1, virtual1);
		printf("%*s", digit, "");
		treeprow_rec((len-1)/2, n/2, digit, values2, virtual2);
	}
}

/**
 * @param tree
 * @brief returns visual representation of the tree. 
*/
void tree_print(Tree *tree) {
	if (tree->head == NULL) {
		printf("Empty\n");
		return;
	}
	int max = tree_max(tree); //maximum value
	int min = tree_min(tree); //miminum value
	int digit = digits(max) < digits(min) ? digits(min) : digits(max); //maxium number of digits in tree
	int height = tree_height(tree); //get height
	int len = 2*1+digit; //base linelength

	for (int i = 0; i < height; ++i) {//calculate linelength
		len = 2*len + digit;
	}

	int* values;
	int* virtual;
	for (int i = 0; i <= height; ++i) {
		values = values_depth_n(tree,i);
		virtual = virtual_depth_n(tree,i);
		treeprow_rec(len,mpow(2,i),digit,values,virtual);
		printf("\n");
	}
}




