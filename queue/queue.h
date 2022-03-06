#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    INT,
    FLOAT,
    DOUBLE,
    CHAR

} queue_type;

typedef struct
{
    queue_type q_type;
    int queue_size;
    int last_index;
    int queue_id;
    void *queue_head;

} queue_identifier;

int q_id;

queue_identifier *init_queue(queue_type q_type, void *head_data);
void enqueue(queue_identifier *q_identity, int data);
void dequeue(queue_identifier *q_identity);
void print_queue(queue_identifier *q_identity);
