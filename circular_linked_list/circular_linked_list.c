#include "circular_linked_list.h"

node* init_linked_list(int data) {
    node *head = (node*)malloc(sizeof(node));
    head->next = head;
    head->data = data;
    last_index = 0;
    iter = head;

    return head;
}

node* add_node(node* head, int index, int data) {
    if(index == -1) {
        //add to the end
        go_to_node(head, last_index);

        iter->next = (node*)malloc(sizeof(node));
        iter = iter->next;
        iter->data = data;
        iter->next = head;

        last_index++;
    }
    else if (index == 0) {
        //change the head

        go_to_node(head, last_index);

        node* new_head = (node*)malloc(sizeof(node));
        new_head->next = head;
        iter->next = new_head;
        new_head->data = data;
        head = new_head;
        last_index++;

    }
    else {
        //insert to the middle
        go_to_node(head, --index);
        node* tmp_node = iter->next;
        iter->next = (node*)malloc(sizeof(node));
        iter->next->next = tmp_node;
        iter->next->data = data;
        last_index++;

    }

    return head;
}


node* delete_node(node* head, int index) {
    if (index == 0) {
        iter = head->next;
        last_index--;
        free(head);
        node* new_head = iter;
        go_to_node(new_head, last_index);
        iter->next = new_head;
        return new_head;
    }
    else if (index == -1) {
        go_to_node(head, --last_index);
        node* tail = iter->next;
        free(tail);
        iter->next = head;
    }
    else {
        go_to_node(head, --index);
        node* prev_node = iter;
        node* del_node = iter->next;
        prev_node->next = del_node->next;
        free(del_node);
        --last_index;
    }
    return head;
}

void go_to_node(node* head, int index) {
    iter = head;
    
    for (int i = 0; i < index; i ++) {
        iter = iter->next;
    }

}

void print_list(node* head) {
    iter = head;
    
    for (int i = 0; i <= last_index + 1; i++) {
        printf("%dth index -> %d\n", i, iter->data);
        iter = iter->next;
    }
   

}
