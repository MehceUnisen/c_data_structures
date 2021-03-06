#pragma once

#include <stdio.h>
#include <stdlib.h>

// i made the code more complex on purpose
// in order to have a better comprehension
// of double pointers

struct hm_identifier
{
    int *first_index;
    int size;
    int **oper_ar;
    int *non_empty;
};

typedef struct hm_identifier hm;

hm *init_hm(int size);
void add_data(hm *head, int data);
int hash(hm *head, int data);
void remove_data(hm *head, int data);
void print_hm(hm *head);