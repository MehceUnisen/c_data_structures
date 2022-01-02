//Written by Mehce Faruk Unisen
//Coded via Visual Studio 2022
//This code reverts the linked list!

#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	struct n* next;
};

typedef struct n node;

int rev(node* iter_two, node* iter_one, node* root);


int main() {
	//creating nodes manually
	//dont need to much of nodes actually
	node* root = (node*)malloc(sizeof(node));
	root->data = 1;
	root->next = (node*)malloc(sizeof(node));
	root->next->data = 2;
	root->next->next = (node*)malloc(sizeof(node));
	root->next->next->data = 3;
	root->next->next->next = (node*)malloc(sizeof(node));
	root->next->next->next->data = 4;
	root->next->next->next->next = NULL;

	//we will have two cursor nodes to navigate
	//one node will be in front of the other node
	//and the prior cursor will be pointed by the other
	//cursor, and the prior cursor will go back to root

	node* iter_one = root;
	node* iter_two = root;
	
	while (iter_one->next != NULL)
		iter_one = iter_one->next;
	
	while (iter_two->next->next != NULL)
		iter_two = iter_two->next;
	
	node* new_root = iter_one;
	
	iter_one->next = iter_two;
	iter_two = root;
	printf("%d ", iter_one->data);
	iter_one = iter_one->next;
	

	rev(iter_two, iter_one, root);

	printf("%d", new_root->next->next->next->data);
	return 0;
}

//rev -> reverse I know It's not a good example of naming
//two cursor navigates around the linked list
//one will be in front, the other will be right back at it
//the one in front will point to one in the back
//and the one in the back will go back to root until it reaches 
//the first pointer, which that pointer will just point to the second 
//pointer and it will go to the next node
//code will explain itself better than I did !
int rev(node* iter_two, node* iter_one, node* root) {
	while (1) {
		while (iter_two->next != iter_one)
			iter_two = iter_two->next;

		iter_one->next = iter_two;
		
		printf("%d ", iter_one->data);
		iter_one = iter_one->next;
		
		if (iter_two == root)
		{
			break;
		}
		iter_two = root;
	}
}