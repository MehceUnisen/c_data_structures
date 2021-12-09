#include <stdio.h>
#include "ll_stack.h"



int main() {

	node* root = initStack(31);
	node* iter = root;

	push(iter, 12);
	push(iter, 13);
	push(iter, 14);
	push(iter, 15);
	push(iter, 16);
	push(iter, 17);

	pop(root);
	pop(root);


	return 0;
}