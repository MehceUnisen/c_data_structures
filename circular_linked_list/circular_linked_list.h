#include <stdio.h>
#include <stdlib.h>


struct n {
    int data;
    struct n* next;
};

typedef struct n node;

node* iter;
int last_index;

node* add_node(node* head, int index, int data);
node* delete_node(node* head, int index);
void go_to_node(node* head, int index);
void print_list(node* head);
node* init_linked_list(int data);