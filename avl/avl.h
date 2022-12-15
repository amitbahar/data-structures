/**
 * @file avl.h
 * @author Amit Bajar
 * @brief interface for a simple avl tree holding integer keys and values
*/

#ifndef AVL_HEADER
#define AVL_HEADER

typedef struct Tree Tree; //tree

Tree * tree_make(); //make empty avl tree

void tree_destroy(Tree *); //deallocate avl tree

void tree_insert(Tree *, int); //insert element with value int

void tree_print(Tree *); //print integer values in order

#endif
