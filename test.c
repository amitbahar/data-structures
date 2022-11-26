#include "sll.h"

int main() {
	Sll *list = makeSll();
	add(list, 1, length(list));
	add(list, 2, length(list));
	add(list, 3, length(list));
	add(list, 4, length(list));
	add(list, 5, length(list));
	print(list);
	add(list,6,length(list)-1);
	print(list);
	undo(list,length(list)-2);
	print(list);
	destroy(list);

	return 0;
}


