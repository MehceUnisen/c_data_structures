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
node* addNodeBetween(node* rootNode, int xValue);
node* createNodeByOrder(node* rootNode, int xValue);




int main() {

	node* rootNode = (node*)malloc(sizeof(node));
	node* iter = rootNode;
	rootNode->next = NULL;

	rootNode->x = 12;
	iter = createNodeByOrder(iter, -31);
	iter = createNodeByOrder(iter, 14);
	iter = createNodeByOrder(iter, 13);
	iter = createNodeByOrder(iter, 14);
	iter = createNodeByOrder(iter, 47);
	iter = createNodeByOrder(iter, 210);
	iter = createNodeByOrder(iter, -420);
	iter = createNodeByOrder(iter, 169);
	iter = createNodeByOrder(iter, 48);
	iter = createNodeByOrder(iter, 420);
	iter = createNodeByOrder(iter, -69);
	iter = createNodeByOrder(iter, -500);

	rootNode = iter;
	tripLastNode(rootNode);

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

node* addNodeBetween(node* rootNode, int xValue) {

	node* toBeTied = rootNode->next;
	node* newNode = (node*)malloc(sizeof(node));
	rootNode->next = newNode;
	newNode->next = toBeTied;
	newNode->x = xValue;
}

node* createNodeByOrder(node* rootNode, int xValue) {
	node* tempRoot = rootNode;

	if (rootNode->x <= xValue)
	{
		while (rootNode->next != NULL)
		{
			if (rootNode->next->x > xValue)
			{
				break;
			}
			rootNode = rootNode->next;
		}

		if (rootNode->next != NULL) {
		node* toBeTied = rootNode->next;
		node* newNode = (node*)malloc(sizeof(node));
		rootNode->next = newNode;
		newNode->next = toBeTied;
		newNode->x = xValue;
		}

		else
		{
			rootNode->next = (node*)malloc(sizeof(node));
			rootNode = rootNode->next;
			rootNode->x = xValue;
			rootNode->next = NULL;
		}
	}
	
	else if (rootNode->x > xValue)
	{
		node* newRoot = (node*)malloc(sizeof(node));
		newRoot->next = rootNode;
		newRoot->x = xValue;
		return newRoot;
	}

	rootNode = tempRoot;
	return rootNode;
}