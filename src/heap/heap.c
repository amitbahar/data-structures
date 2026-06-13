/**
 * @file heap.c
 * @author Amit Bajar
 * @brief implementation for a binary heap (min) holding integer keys and no extra data
*/

#include "heap.h"
#include <stdlib.h>

static int parent(int i) { //get index of parent of i'th element in array
    return ((i+1)/2)-1;
}

static int left(int i) { //get index of left child of i'th element in array
    return 2*(i+1)-1;
}

static int right(int i) { //get index of right child of i'th element in array
    return 2*(i+1);
}

static void heapify_up(Heap *heap, int i) { // i - index of element to heapify up in the array
    int *arr = heap->arr;
    while (0 < i && *(arr+i) < *(arr+parent(i))) {
        int temp = *(arr+i);
        *(arr+i) = *(arr+parent(i));
        *(arr+parent(i)) = temp;
        i = parent(i);
    }
}

static void heapify_down(Heap *heap, int i) { // i - index of element to heapify down in the array
    int *arr = heap->arr;
    while (left(i) < heap->n && (*(arr+left(i)) < *(arr+i) || *(arr+right(i)) < *(arr+i))) {
        int index = *(arr+left(i)) < *(arr+right(i)) ? left(i) : right(i);
        int temp = *(arr+index);
        *(arr+index) = *(arr+i);
        *(arr+i) = temp;
        i = index;
    }
}

/**
 * @brief creates an empty heap. Time complexity: O(1)
 * @return empty heap
*/
Heap* heap_make() {
    int *temp = (int*)malloc(sizeof(int)*SIZE);
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    *heap = (Heap){temp,0,SIZE};

    return heap;
}

/**
 * @param heap, @param key
 * @brief inserts key to given heap. Time complexity: O(logn)
*/
void heap_insert(Heap *heap, int key) {
    int size = heap->n;
    int length = heap->l;
    
    if (size == length) { //reallocate twice as much memory for the new heap
        heap = (Heap*)realloc(heap,2*length*sizeof(int));
        heap->l *= 2;
    }

    ++heap->n;

    int *arr = heap->arr;
    *(arr+size) = key;
    heapify_up(heap,size);
}

/**
 * @param heap, @param pointer_to_key
 * @brief delete key at index. Time complexity: O(logn)
*/
void heap_delete(Heap *heap, int index) {
    --heap->n;
    int *arr = heap->arr;
    int size = heap->n;
    *(arr+index) = *(arr+size);
    heapify_down(heap,index);

    if (2*size <= heap->l) {
        int length = heap->l;
        heap = (Heap*)realloc(heap,(length/2)*sizeof(int));
        heap->l = length/2;
    }
}

/**
 * @param heap @param index @param delta
 * @brief decrease value of key at index by delta. Time complexity: O(logn)
*/
void heap_decreasekey(Heap* heap, int index, int delta) {
    *((heap->arr)+index) -= delta;
    heapify_up(heap,index);
}


/**
 * @param heap
 * @brief returns the minimum. Time complexity: O(1)
 * @return minimum element.
*/
int heap_min(Heap *heap) {
    return *(heap->arr);
}

/**
 * @param heap
 * @brief returns the minimum and deletes it from the heap. Time complexity: O(logn)
 * @return minimum element.
*/
int heap_deletemin(Heap *heap) {
    int min = heap_min(heap);
    heap_delete(heap,0);
    return min;
}

/**
 * @param heap
 * @brief free memory used by heap. Time complexity: O(1)
*/
void heap_destroy(Heap *heap) {
    free(heap->arr);
    free(heap);
}