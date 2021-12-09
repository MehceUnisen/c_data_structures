#pragma once

typedef struct{
	int data;
	node* next;
}node;


node* initStack(int data);
void pop(node* iter);
void push(node* iter, int data);
void print(node* root);

