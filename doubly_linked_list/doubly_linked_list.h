#pragma once

#include <stdio.h>
#include <stdlib.h>

struct n {
    struct n* next;
    struct n* prev;

    int data;

    int last_index;
};


typedef struct n node;

node* iter;

node* init_linked_list(int data);
void add_node(node** root, int index, int data);
void remove_node(node** root, int index);
node* go_to_node(node* head, int index);
void print_linked_list(node* head);
void print_linked_list_backwards(node* root);