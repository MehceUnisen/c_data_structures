#include "doubly_linked_list.h"

int main() {

    node* main_root = init_linked_list(11);
    add_node(&main_root, -1, 12);
    add_node(&main_root, -1, 13);
    add_node(&main_root, -1, 15);
    add_node(&main_root, -1, 16);
    add_node(&main_root, 0, 10);
    add_node(&main_root, 4, 14);
    remove_node(&main_root, 0);
    remove_node(&main_root, -1);
    remove_node(&main_root, 2);

    print_linked_list(main_root);

    print_linked_list_backwards(main_root);

    //output
    // 0th index -> 11
    // 1th index -> 12
    // 2th index -> 14
    // 3th index -> 15
    // 4th index -> 11
    // 4th data -> 15
    // 3th data -> 14
    // 2th data -> 12
    // 1th data -> 11
    // 0th data -> 15

    return 0;
}