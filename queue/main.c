#include "queue.h"

int main()
{
    q_id = -1;
    int a = 9;
    queue_identifier *main_q = init_queue(INT, &a);

    enqueue(main_q, 10);
    enqueue(main_q, 11);
    enqueue(main_q, 12);

    enqueue(main_q, 13);
    enqueue(main_q, 14);
    dequeue(main_q);
    dequeue(main_q);
    enqueue(main_q, 15);
    dequeue(main_q);
    dequeue(main_q);
    dequeue(main_q);
    enqueue(main_q, 16);

    print_queue(main_q);

    // output
    // 0th index -> 15
    // 1th index -> 16

    return 0;
}