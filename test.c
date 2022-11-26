#include "sll.h"

int main() {
	Sll *list = makeSll();
	add(list, 1, length(list));
	add(list, 1, length(list));
	add(list, 1, length(list));
	print(list);
	destroy(list);

	return 0;
}



