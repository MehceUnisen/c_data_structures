#include "circular_linked_list.h"

int main() {

    node* head = init_linked_list(11);
    head = add_node(head, 0, 10);
    add_node(head, -1, 13);
    add_node(head, 2, 12);
    delete_node(head, 1);
    head = delete_node(head, 0);
    delete_node(head, -1);
    print_list(head);
 
}

//I decided to return head node to make changes on head node
//also double pointer can be used in order to make function void