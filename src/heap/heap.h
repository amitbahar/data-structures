/**
 * @file heap.h
 * @author Amit Bajar
 * @brief interface for a binary heap (min) holding integer keys and no extra data
*/

#ifndef HEAP_HEADER
#define HEAP_HEADER

#define SIZE 20

typedef struct Heap {
	int *arr;
    int n; //current length
    int l; //max length
} Heap;

Heap* heap_make(); //make an empty heap

void heap_insert(Heap*, int); //insert key to heap

void heap_delete(Heap*, int); //delete key from heap

void heap_decreasekey(Heap*, int, int); //decrease key at index

int heap_min(Heap*); //retrieve minimum key

int heap_deletemin(Heap*); //retrieve minimum key and delete it from heap

void heap_destroy(Heap*); //free memory used by heap

#endif