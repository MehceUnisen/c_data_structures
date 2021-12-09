#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct n {
	int x;
	struct n* next;
};

typedef struct n node;


node* createNode(node* root);

int main() {

	srand(time(NULL));

	node* root;
	node* iter;

	//creating the root node
	root = (node*)malloc(sizeof(node));
	root->x = 10;

	//creating some nodes manually
	root->next = createNode(root);
	root->next->x = 31;
	root->next->next = createNode(root->next);
	root->next->next->x = 17;

	//moving the "iter" node pointer cursor to the root
	iter = root;

	for (int i = 0; i < 2; i++)
	{
		//skipping to the last node via looping
		iter = iter->next;
	}

	for (int i = 0; i < 2; i++)
	{
		//creating some nodes automaticly in loop
		iter->next = createNode(iter);
		iter = iter->next;
		iter->x = rand() % 10;
		
	}

	//reseting the position of iter cursor
	iter = root;
	
	for (int i = 0; i < 5; i++)
	{
		//printing out all the values of linked list
		printf("%d\n", iter->x);

		iter = iter->next;
	}


	return 0;
}

node* createNode(node* root) {
	//allocates new memory block for next node
	//and returns the address of new block
	root->next = (node*)malloc(sizeof(node));
	return root->next;
}
