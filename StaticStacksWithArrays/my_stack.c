#include <stdlib.h>
#include <stdio.h>

#include "my_stack.h"

stackSize = 2;
topIndex = 0;

void initMyStack() {
	myStack = (int*)malloc(sizeof(int) * stackSize);
}

void pop() {
	
	myStack[topIndex - 1] = 0;
	topIndex--;
	
	
	if (topIndex == stackSize / 2)
	{
		
		int* myTempStack = (int*)malloc(sizeof(int) * stackSize);
		for (int i = 0; i < stackSize; i++)
		{
			myTempStack[i] = myStack[i];
		}
		
		stackSize /= 2;


		myStack = (int*)malloc(sizeof(int) * stackSize);

		for (int i = 0; i < stackSize; i++)
		{
			myStack[i] = myTempStack[i];
		}
		free(myTempStack);

		
	}
	
}

void push(int toPush) {
	if (stackSize == topIndex)
	{
		int* myTempStack = (int*)malloc(sizeof(int) * stackSize);
		for (int i = 0; i < stackSize; i++)
		{
			myTempStack[i] = myStack[i];
		}
		stackSize *= 2;
		myStack = (int*)malloc(sizeof(int) * stackSize);

		for (int i = 0; i < stackSize / 2; i++)
		{
			myStack[i] = myTempStack[i];
		}
		free(myTempStack);
	}

	myStack[topIndex] = toPush;
	topIndex++;

}

void printMyStack() {
	for (int i = 0; i < stackSize; i++)
	{
		printf("%d ", myStack[i]);
	}
}