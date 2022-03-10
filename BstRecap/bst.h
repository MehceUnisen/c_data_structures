#include <stdlib.h>
#include <stdio.h>

struct n
{
    struct n *left;
    struct n *right;
    int data;
};

typedef struct n leaf;

leaf *init_tree(int data);
void add_leaf(leaf *root, int data);
leaf *go_to_leaf(leaf *root, int data);
