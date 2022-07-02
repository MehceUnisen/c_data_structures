#include "queue.h"

int main()
{
    q_id = -1;
    queue_identifier *main_q = init_queue(INT);
    int a = 10;
    enqueue(main_q, &a);
    a++;
    enqueue(main_q, &a);
    a++;
    enqueue(main_q, &a);

    a++;
    enqueue(main_q, &a);
    a++;
    enqueue(main_q, &a);

    print_queue(main_q);

    // output
    // 0th index -> 10
    // 1th index -> 11
    // 2th index -> 12
    // 3th index -> 13
    // 4th index -> 14

    dequeue(main_q);
    dequeue(main_q);
    a++;
    enqueue(main_q, &a);
    dequeue(main_q);
    dequeue(main_q);
    dequeue(main_q);
    a++;
    enqueue(main_q, &a);

    print_queue(main_q);

    // output

    // 0th index -> 15
    // 1th index -> 16

    return 0;
}