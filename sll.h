#ifndef SLL_HEADER
#define SLL_HEADER

typedef struct Node Node;

typedef struct Sll Sll;

Sll * makeSll();

void destroy(Sll *list);

int length(Sll *list);

void add(Sll *list, int data, int position);

void print(Sll *list);

#endif


	



