#include <stdio.h>

#include "simple_queue.h"

int main(void) {
    Simple_Queue_t queue;
    createQueue(4, &queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    //enqueue(&queue, 5);
    printf("Az elso elem: %i", dequeue(&queue));
    return 0;
}
