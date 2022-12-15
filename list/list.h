/**
 * @file list.h
 * @author: Amit Bajar
 * @brief interface of a simple singly linked list of int values
*/

#ifndef SLL_HEADER
#define SLL_HEADER

typedef struct Node Node; //basic element of a list

typedef struct List List; //list

List * list_make(); //constructor

void list_destroy(List *); //deallocate list memory

int list_length(List *); //get length 

void list_insert(List *, int, int); //insert value = int, at position = int

void list_delete(List *, int); //delete at position = int

void list_print(List *); //print values

#endif


	



