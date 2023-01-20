/**
 * @file list.c
 * @author: Amit Bajar
 * @brief interface implementation of a simple singly linked list of values
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * @brief creates an empty list. Time complexity: O(1)
 * @return empty list
*/
List* list_make() {
	List *list = (List*)malloc(sizeof(list));
	*list = (List){.head = NULL, .length = 0};
	return list;
}

/**
 * @param list
 * @brief Time complexity: O(length)
 * @brief deallocate the memory of list
*/
void list_destroy(List *list) {
	ListNode* current = list->head;
	
	if (current == NULL) {
		free(list);
		return;
	} else {
		ListNode* tmp = list->head->next;
		while (tmp != NULL) { //free current as long as there is next
			free(current->data);
			free(current);
			current = tmp;
			tmp = tmp->next;
		}
		free(current->data); //free last node
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
 * @param list @param position
 * @return element at position
 * @warning list must be none emtpy AND must always satisfy 0<=position<=length(list)-1
*/
void* list_retrieve(List *list, int position) {
	ListNode *pnt = list->head;
	for (int i = 0; i < position; ++i) {
		pnt = pnt->next;
	}
	return pnt->data;
}

/**
 * @param data value to insert @param position position to insert value
 * @brief adds a new list element with given data at given position. 
 * Time Complexity: O(position)
 * @warning must always satisfy 0<=position<=length(list)
*/
void list_insert(List *list, void* data, int position) {
	ListNode *element = (ListNode *)malloc(sizeof(ListNode));
	*element = (ListNode){.next = NULL, .data = data};
	++(list->length);

	if (list->head == NULL) {
		list->head = element;
		return;
	}
	
	if (position == 0) {
		element->next = list->head;
		list->head = element;
		return;
	}

	ListNode *pnt = list->head;
	int tmp = position;
	
	while (1 < tmp) {
		--tmp;
		pnt = pnt->next;
	}
	
	if (position == list_length(list)-1) { //subtract 1 because we already increased the length
		pnt->next = element;
	} else {
		element->next = pnt->next;
		pnt->next = element;
	}
	return;
}

/**
 * @param list @param position
 * @brief deletes list element as given position
 * Time complexity: O(length)
 * @warning must always satisfy 0<=position<=length-1
*/
void list_delete(List *list, int position) {
	ListNode *pnt = list->head;
	if (position == 0) {
		list->head = list->head->next;
		free(pnt);
		list->length--;
		return;
	}
	while (1 < position) {
		--position;
		pnt = pnt->next;
	}
	ListNode* tmp = pnt->next;
	pnt->next = pnt->next->next;
	free(tmp);
	list->length--;
	return;
}


	



