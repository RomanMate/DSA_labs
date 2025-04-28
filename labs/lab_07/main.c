#include <stdio.h>

#include "glasess_circular_queue.h"

int main(void) {
    CircularQueue_t glasses;
    createQueue(10, &glasses);

    GLASS glass;

    enqueue(&glasses, glass);
    enqueue(&glasses, glass);

    dequeue(&glasses);

    display(glasses);

    for (int i=0; i<glasses.capacity; i++) {

    }

    return 0;
}
