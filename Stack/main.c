#include <stdio.h>


int isEmpty(int*, int);
int isFull(int*, int);
int findFirstEmptySpot(int*, int);
int peek(int*, int);
int pop(int*, int);
int push(int*, int, int);

int main() {


	return 0;
}

int isEmpty(int* stack, int arrSize) {
	
	for (int i = 0; i < arrSize; i++)
	{
		if (stack[i])
		{
			return -1;
		}
	}

	return 1;
}

int isFull(int* stack, int arrSize) {
	
	for (int i = 0; i < arrSize; i++)
	{
		if (!stack[i])
		{
			return -1;
		}
	}

	return 1;
}

int findFirstEmptySpot(int* stack, int arrSize) {
	
	for (int i = arrSize - 1; i >= 0; i--)
	{
		if (!stack[i])
		{
			return i;
		}
	}
	return -1;
}

int peek(int* stack, int arrSize) {

	int topValue = stack[findFirstEmptySpot(stack, arrSize) + 1];

	printf("Value Peeked -> %d\n", topValue);

	return findFirstEmptySpot(stack, arrSize) + 1;
	
}

int pop(int* stack, int arrSize) {

	if (isEmpty(stack, arrSize) == 1)
	{
		printf("Stack is empty, there is nothing to pop\n");
		return -1;
	}
	else {
		int lastSpot = findFirstEmptySpot(stack, arrSize) + 1;
		stack[lastSpot] = 0;
		return 1;
	}
	
}

int push(int* stack, int arrSize, int valueToPush) {

	if (isFull(stack, arrSize) == 1)
	{
		printf("The Stack is Full, Consider sizing up the stack\n");

		return -1;
	}
	else {
		int writeIndex = findFirstEmptySpot(stack, arrSize);
		stack[writeIndex] = valueToPush;

		return 1;
	}
}