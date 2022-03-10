#include "bst.h"

leaf *init_tree(int data)
{
    leaf *root = (leaf *)malloc(sizeof(leaf));
    root->left = NULL;
    root->right = NULL;
    root->data = data;

    return root;
}

void add_leaf(leaf *root, int data)
{

    while (1)
    {
        if (!root->right && data >= root->data)
        {
            root->right = (leaf *)malloc(sizeof(leaf));
            root = root->right;
            root->data = data;
            root->left = NULL;
            root->right = NULL;

            return;
        }
        else if (!root->left && data < root->data)
        {
            root->left = (leaf *)malloc(sizeof(leaf));
            root = root->left;
            root->data = data;
            root->left = NULL;
            root->right = NULL;

            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else if (data >= root->data)
        {
            root = root->right;
        }
    }
}

leaf *go_to_leaf(leaf *root, int data)
{

    while (root->left || root->right)
    {
        if (root->data == data)
        {
            return root;
        }
        else if (root->data > data)
        {
            // printf("left\n");
            root = root->left;
        }
        else if (root->data <= data)
        {
            // printf("right\n");
            root = root->right;
        }
    }
    if (root->data == data)
    {
        printf("nasii");
        return root;
    }
    return NULL;
}