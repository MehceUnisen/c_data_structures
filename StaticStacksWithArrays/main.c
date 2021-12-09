#include <stdio.h>
#include "my_stack.h"


int main() {

	initMyStack();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	push(110);
	push(120);

	pop();
	pop();
	pop();
	pop();
	pop();


	printMyStack();

	return 0;
}