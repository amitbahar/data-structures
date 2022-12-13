#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

typedef struct Node {
	struct Node *next;
	int data;
} Node;

typedef struct Sll {
	struct Node *head;
	int length;
} Sll;

Sll * makeSll() {
	Sll* list = (Sll*)malloc(sizeof(Sll));
	list->head = NULL;
	list->length = 0;
	
	return list;
}

void destroylist(Sll *list) {
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

int length(Sll *list) {
	return list->length;
}

void add(Sll *list, int data, int position) {
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
	
	if (position == length(list)) {
		pnt->next = element;
	} else {
		element->next = pnt->next;
		pnt->next = element;
	}
	++(list->length);
	return;
}

void undo(Sll *list, int position) {
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

void print(Sll *list) {
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


	



