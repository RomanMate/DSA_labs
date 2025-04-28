//
// Created by balin on 2025. 03. 24..
//

#include <stdio.h>
#include <stdlib.h>

#include "simple_queue.h"
#include <constans.h>

void createQueue(int capacity, Simple_Queue_t* queue)
{
    queue->capacity=capacity;
    queue->rear=queue->front=-1;
    queue->elements=(int*)malloc(capacity*sizeof(int));
    if (!queue->elements)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueue(Simple_Queue_t* queue) {
    if (queue == NULL) {
        return;
    }

    // Felszabadítjuk a queue által használt dinamikus memóriát
    free(queue->elements);
    queue->elements = NULL;

    // Végül magát a queue struktúrát is felszabadítjuk
    free(queue);
}


bool isFull(Simple_Queue_t queue){
    return queue.rear==queue.capacity-1;
}

bool isEmpty(Simple_Queue_t queue)
{
    return queue.front==-1;
}


void enqueue(Simple_Queue_t* queue, int item)
{
    if (isFull(*queue))
    {
        printf("The queve is full");
        exit(-3);
    }
    if (isEmpty(*queue))
    {
        queue->front=0;
    }
    queue->elements[++queue->rear]=item;
}

int dequeue(Simple_Queue_t* queue)
{
    if (isEmpty(*queue))
    {
        printf("The queue is empty");
        exit(-3);
    }
    int save=queue->elements[queue->front];
    if (queue->front==queue->rear)
        queue->front=queue->rear=-1;
    else
        queue->front++;
    return save;
}

void display(Simple_Queue_t queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty");
        exit(-3);
    }
    for (int i=queue.front;i<=queue.rear;i++)
    {
        printf("%i ",queue.elements[i]);
    }
    printf("\n");
}

int peek(Simple_Queue_t queue){
    if (isEmpty(queue)){
        printf("The queue is empty");
        exit(-3);
    }
    return queue.rear;
}
