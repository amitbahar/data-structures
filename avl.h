#ifndef AVL_HEADER
#define AVL_HEADER

typedef struct Tree Tree;

Tree * makeTree();

void destroy(Tree *);

void insert(Tree *, int);

void printree(Tree *);

#endif
