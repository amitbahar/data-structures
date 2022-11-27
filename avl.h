#ifndef AVL_HEADER
#define AVL_HEADER

typedef struct Node Node;

typedef struct Tree Tree;

Tree * makeTree();

void destroy(Tree *);

void insert(Tree *, int);

void remove(Tree *, int);

void print(Tree *);

#endif
