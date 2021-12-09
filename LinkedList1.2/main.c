#include <stdio.h>
#include <stdlib.h>

struct n {
	int x;
	struct n* next;
};

typedef struct n node;


void addNodeByAmount(node* root, int nodeAmount);
void tripLastNode(node* root);
node* goToNode(node* rootNode, int nodeIndex);
node* addNodeByValue(node* root, int value);

int main() {

	node* root = (node*)malloc(sizeof(node));
	root->x = 31;
	root->next = NULL;

	node* iter = root;
	
	addNodeByAmount(iter, 10);

	node* sixthNode = goToNode(root, 6);
	node* fifthNode = goToNode(root, 5);
	
	fifthNode->next = addNodeByValue(fifthNode, 69);
	iter = fifthNode->next;
	iter->next = addNodeByValue(iter, 420);
	iter->next->next = sixthNode;
	iter = root;

	tripLastNode(iter);

	return 0;
}

void addNodeByAmount(node* root, int nodeAmount) {
	
	node* tempRoot = root;

	while (root->next != NULL) {
		root = root->next;
	}
	
	for (int i = 0; i < nodeAmount; i++)
	{
		root->next = (node*)malloc(sizeof(node));
		root = root->next;
		root->x = i * 10;
	}

	root->next = NULL;
	root = tempRoot;
	
}

void tripLastNode(node* root) {
	node* tempRoot = root;

	while (root != NULL) {
		
		printf("%d ", root->x);
		root = root->next;

	}

	root = tempRoot;
	
}

node* goToNode(node* rootNode, int nodeIndex) {
	
	node* tempRoot = rootNode;

	for (int i = 0; i < nodeIndex; i++)
	{
		tempRoot = tempRoot->next;
	}

	return tempRoot;

}

node* addNodeByValue(node* root, int value) {

	root->next = (node*)malloc(sizeof(node));
	root = root->next;
	root->x = value;

	return root;
}