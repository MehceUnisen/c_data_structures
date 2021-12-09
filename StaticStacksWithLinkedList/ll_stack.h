#pragma once

struct n{
	int data;
	node* next;
};

typedef struct n node;


node* initStack(int data);
void pop(node* iter);
void push(node* iter, int data);
void print(node* root);

