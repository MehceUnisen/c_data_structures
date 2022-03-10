#include "bst.h"

int main()
{
    leaf *main_root = init_tree(10);
    add_leaf(main_root, 9);
    add_leaf(main_root, 11);
    add_leaf(main_root, 7);
    add_leaf(main_root, 8);

    return 0;
}
