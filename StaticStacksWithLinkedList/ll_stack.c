#include <stdlib.h>
#include "ll_stack.h"

node* initStack(int data) {
	node* root = (node*)malloc(sizeof(node));
	root->data = data;
	root->next = NULL;

	return root;
}

void push(node* iter, int data) {

	while (iter->next != NULL) {
		iter = iter->next;
	}

	iter->next = (node*)malloc(sizeof(node));
	iter = iter->next;
	iter->data = data;
	iter->next = NULL;
}

void pop(node* iter) {

	while (iter->next->next != NULL) {
		iter = iter->next;
	}
	free(iter->next);
	iter->next = NULL;
}

void print(node* iter) {
	while (iter->next != NULL) {
		printf("%d - ", iter->data);
		iter = iter->next;
	}
}