#ifndef SLL_HEADER
#define SLL_HEADER

typedef struct Node Node;

typedef struct Sll Sll;

Sll * makeSll();

void destroy(Sll *);

int length(Sll *);

void add(Sll *, int, int);

void undo(Sll *, int);

void print(Sll *);

#endif


	



