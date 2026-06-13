/**
 * @file list.h
 * @author: Amit Bajar
 * @brief interface of a simple singly linked list of int values
*/

#ifndef LIST_HEADER
#define LIST_HEADER

typedef struct ListNode {
	struct ListNode *next;
	void* data;
} ListNode;

typedef struct List {
	struct ListNode *head;
	int length;
} List;

List* list_make(); //constructor

void list_destroy(List *); //deallocate list memory

int list_length(List *); //get length

void* list_retrieve(List*,int); //retrieve data at position

void list_insert(List*, void*, int);

void list_delete(List*, int); //delete at position = int

void list_print(List*); //print values

#endif


	



