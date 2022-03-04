#include "doubly_linked_list.h"



node* init_linked_list(int data) {
    
    node* root = (node*)malloc(sizeof(node));
    
    root->next = (node*)malloc(sizeof(node));
    root->prev = NULL;

    root->data = data;
    root->last_index = 1;


    return root;
}


void add_node(node** root, int index, int data) {
    if (index == -1) {
        //add to the end

        node* prev_node = go_to_node(root, (*root)->last_index);
        iter->next = (node*)malloc(sizeof(node));
        iter = iter->next;
        iter->prev = prev_node;
        iter->next = *root;
        (*root)->prev = iter;

        iter->data = data;
        (*root)->last_index++;

    }
    else if (index == 0) {
        //change the head

        node* new_root = (node*)malloc(sizeof(node));
        go_to_node(root, (*root)->last_index);
        iter->next = new_root;
        new_root->prev = iter;
        new_root->next = (*root);
        new_root->last_index = ++(*root)->last_index;
        new_root->data = data;
        (*root) = new_root;
        
    }
    else {
        //insert between two node

        node* new_node = (node*)malloc(sizeof(node));
        node* prev_node = go_to_node(root, index);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        new_node->next->prev = new_node;
        new_node->prev = prev_node;

        new_node->data = data;
        (*root)->last_index++;
    }
}


void remove_node(node** root, int index) {
    if(index == 0) {
        //remove root node
        node* old_root = (*root);
        go_to_node(root, (*root)->last_index);
        iter->next = old_root->next;
        old_root->next->prev = iter;
        old_root->next->last_index = --(*root)->last_index; 
        (*root) = old_root->next;
        free(old_root);
    }
    else if(index == -1) {
        node* del_node = go_to_node(root, (*root)->last_index);
        del_node->prev->next = (*root);
        (*root)->prev = del_node->prev;
        (*root)->last_index--;
        free(del_node);
    }
    else {
        node* del_node = go_to_node(root, ++index);
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
        (*root)->last_index--;
        free(del_node);
    }
}


node* go_to_node(node* root, int index) {
    iter = root;
    for (int i = 0; i < index; i++) {
        iter = iter->next;
    }
    return iter;
}


void print_linked_list(node* root) {
    iter = root;
    for (int i = 0; i <= root->last_index; i++) {
        printf("%dth index -> %d\n", i, iter->data);
        iter = iter->next;
    }
}

void print_linked_list_backwards(node* root) {
    iter = root->prev;

    for(int i = root->last_index; i >= 0; i--) {
        printf("%dth data -> %d\n", i, iter->data);
        iter = iter->prev;
    }
}