#include "queue.h"

queue_identifier *init_queue(queue_type q_type)
{
    queue_identifier *new_q = (queue_identifier *)malloc(sizeof(queue_identifier));
    new_q->queue_id = ++q_id;
    new_q->queue_size = 1;
    new_q->last_index = 0;
    new_q->q_type = q_type;

    if (q_type == FLOAT)
    {
        new_q->queue_head = (float *)malloc(sizeof(float));
        new_q->q_type = FLOAT;
    }
    else if (q_type == DOUBLE)
    {
        new_q->queue_head = (double *)malloc(sizeof(double));
        new_q->q_type = DOUBLE;
    }
    else if (q_type == CHAR)
    {
        new_q->queue_head = (char *)malloc(sizeof(char));
        new_q->q_type = CHAR;
    }
    else
    {
        new_q->queue_head = (int *)malloc(sizeof(int));
        new_q->q_type = INT;
    }

    return new_q;
}

void enqueue(queue_identifier *q_identity, int data)
{
    if (q_identity->q_type == FLOAT)
    {
        if (q_identity->last_index + 1 == q_identity->queue_size)
        {
            q_identity->queue_head = realloc(q_identity->queue_head, ++q_identity->queue_size * sizeof(float));
        }

        ((float *)q_identity->queue_head)[q_identity->last_index++] = data;
    }
    else if (q_identity->q_type == DOUBLE)
    {

        if (q_identity->last_index + 1 == q_identity->queue_size)
        {
            q_identity->queue_head = realloc(q_identity->queue_head, ++q_identity->queue_size * sizeof(double));
        }
        ((double *)q_identity->queue_head)[q_identity->last_index++] = data;
    }
    else if (q_identity->q_type == CHAR)
    {

        if (q_identity->last_index + 1 == q_identity->queue_size)
        {

            q_identity->queue_head = realloc(q_identity->queue_head, ++q_identity->queue_size * sizeof(char));
        }
        ((char *)q_identity->queue_head)[q_identity->last_index++] = data;
    }
    else
    {

        if (q_identity->last_index + 1 == q_identity->queue_size)
        {
            q_identity->queue_head = realloc(q_identity->queue_head, ++q_identity->queue_size * sizeof(int));
        }
        ((int *)q_identity->queue_head)[q_identity->last_index++] = data;
    }
}

void dequeue(queue_identifier *q_identity)
{
    if (q_identity->q_type == INT)
    {
        // printf("geldim hanim kusura bakma biraz erken oldu sanirim");
        int *del = ((int *)q_identity->queue_head + (--q_identity->last_index - 1));
        q_identity->queue_head = (int *)q_identity->queue_head + 1;
        free((void *)del);
    }

    else if (q_identity->q_type == FLOAT)
    {
        float *del = ((float *)q_identity->queue_head + (--q_identity->last_index - 1));
        q_identity->queue_head = (float *)q_identity->queue_head + 1;
        free((void *)del);
    }
    else if (q_identity->q_type == DOUBLE)
    {
        double *del = ((double *)q_identity->queue_head + (--q_identity->last_index - 1));
        q_identity->queue_head = (double *)q_identity->queue_head + 1;
        free((void *)del);
    }
    else
    {
        char *del = ((char *)q_identity->queue_head + (--q_identity->last_index - 1));
        q_identity->queue_head = (char *)q_identity->queue_head + 1;
        free((void *)del);
    }
}

void print_queue(queue_identifier *q_identity)
{
    if (q_identity->q_type == INT)
    {
        for (int i = 0; i < q_identity->last_index; i++)
        {
            printf("%dth index -> %d\n", i, ((int *)q_identity->queue_head)[i]);
        }
    }
    else if (q_identity->q_type == FLOAT)
    {
        for (int i = 0; i < q_identity->last_index; i++)
        {
            printf("%dth index -> %f\n", i, ((float *)q_identity->queue_head)[i]);
        }
    }
    else if (q_identity->q_type == DOUBLE)
    {
        for (int i = 0; i < q_identity->last_index; i++)
        {
            printf("%dth index -> %lf\n", i, ((double *)q_identity->queue_head)[i]);
        }
    }
    else
    {
        for (int i = 0; i < q_identity->last_index; i++)
        {
            printf("%dth index -> %c\n", i, ((char *)q_identity->queue_head)[i]);
        }
    }
}
