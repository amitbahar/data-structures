/**
 * @file list.c
 * @author: Amit Bajar
 * @brief interface implementation of a simple singly linked list of int values
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node {
	struct Node *next;
	int data;
} Node;

typedef struct List {
	struct Node *head;
	int length;
} List;

/**
 * @brief creates an empty list. Time complexity: O(1)
 * @return empty list
*/
List * list_make() {
	List *list = (List*)malloc(sizeof(list));
	list->head = NULL;
	list->length = 0;
	
	return list;
}

/**
 * @param list
 * @brief Time complexity: O(length)
 * @brief deallocate the memory of list
*/
void list_destroy(List *list) {
	Node* current = list->head;
	Node* tmp = list->head->next;
	
	if (current == NULL) {
		free(list);
		return;
	} else {
		while (tmp != NULL) {
			free(current);
			current = tmp;
			tmp = tmp->next;
		}
		free(current);
	}
	free(list);
	return;
}

/**
 * @param list
 * @brief Time Complexity: O(1)
 * @return length of list
*/
int list_length(List *list) {
	return list->length;
}

/**
 * @param data int value to insert @param position position to insert value
 * @brief adds a new list element with given data at given position. 
 * Time Complexity: O(position)
 * @warning must always satisfy 0<=position<=length(list)
*/
void list_insert(List *list, int data, int position) {
	Node *element = (Node *)malloc(sizeof(Node));
	element->next = NULL;
	element->data = data;

	if (list->head == NULL) {
		list->head = element;
		++(list->length);
		return;
	}
	
	if (position == 0) {
		element->next = list->head;
		list->head = element;
		++(list->length);
		return;
	}

	Node *pnt = list->head;
	int tmp = position;
	
	while (1 < tmp) {
		--tmp;
		pnt = pnt->next;
	}
	
	if (position == list_length(list)) {
		pnt->next = element;
	} else {
		element->next = pnt->next;
		pnt->next = element;
	}
	++(list->length);
	return;
}

/**
 * @param list @param position
 * @brief deletes list element as given position
 * Time complexity: O(length)
 * @warning must always satisfy 0<=position<=length-1
*/
void list_delete(List *list, int position) {
	Node *pnt = list->head;
	if (position == 0) {
		list->head = list->head->next;
		free(pnt);
		return;
	}
	while (1 < position) {
		--position;
		pnt = pnt->next;
	}
	Node* tmp = pnt->next;
	pnt->next = pnt->next->next;
	free(tmp);
	return;
}

/**
 * @param list
 * @brief prints list values in order. 
 * Time complexity: O(length)
*/
void list_print(List *list) {
	if (list->head == NULL) {
		printf("Empty");
	} else {
		Node *pnt = list->head;
		
		while (pnt != NULL) {
			if (pnt->next == NULL) {
				printf("%d\n",pnt->data);
			} else {
				printf("%d->",pnt->data);
			}
			pnt = pnt->next;
		}
	}
}


	



