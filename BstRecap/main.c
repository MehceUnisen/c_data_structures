#include "bst.h"

int main()
{
    leaf *main_root = init_tree(10);
    add_node(main_root, 9);
    add_node(main_root, 11);
    add_node(main_root, 7);
    add_node(main_root, 8);

    return 0;
}