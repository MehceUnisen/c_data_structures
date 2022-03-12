#include "hm.h"

hm *init_hm(int size)
{
    hm *head = (hm *)malloc(sizeof(hm));
    head->size = size;
    head->first_index = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        head->first_index[i] = -1;
    }

    return head;
}

void add_data(hm *head, int data)
{
    int i = hash(head, data) - 1;
    for (; i < (head->size - 1) && head->first_index[i] != -1; i++)
        ;
    head->first_index[i] = data;
}

int hash(hm *head, int data)
{
    return data % head->size;
}

void remove_data(hm *head, int data)
{
    int index = hash(head, data);
    for (; index < (head->size - 1) && head->first_index[index] != data; index++)
        ;
    // default value assignment for deleting
    if (data == head->first_index[index])
    {
        head->first_index[index] = -1;
    }
    else
    {
        printf("There isn't any %d in hashmap!\n", data);
    }
}

void print_hm(hm *head)
{
    for (int i = 0; i < head->size; i++)
    {
        printf("%dth index -> %d\n", i, head->first_index[i]);
    }
}
