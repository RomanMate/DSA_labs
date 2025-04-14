//
// Created by Román Máté on 2025. 03. 24..
//
#include <stdlib.h>
#include <stdio.h>
#include "queuef.h"

void createQueue(int capacity, Simple_Queue_t* queue)
{
    queue->capacity=capacity;
    queue->rear=queue->front=-1;
    queue->elements=(int*)malloc(capacity*sizeof(int));
    if (!queue->elements)
    {
        printf("Memory allocation error");
        exit(-1);
    }
}
void createQueue(int capacity, Simple_Queue_t *queue){
    queue->capacity=0;
    queue->front=-1;
    free(queue->elements);
    queue=NULL;
}
bool isFull(Simple_Queue_t queue){
    return queue.rear==queue.capacity-1;
}
bool isEmpty(Simple_Queue_t queue){
    return queue.rear==-1;
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
void enqueue(Simple_Queue_t* queue, int item)
{
 if (isFull(*queue))
   {
     printf("The stack is full");
     exit(-3);
   }
   if (isEmpty(*queue))
   {
       queue->front=;
   }
   queue->elements[]=item;
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
       queue->front=queue->rear=;
   else
       queue->front++;
 return save;
}
void display(Simple_Queue_t queue)
{
 if (isEmpty(queue))
 {
 printf("is empty");
 exit(-4);
 }
 if (queue.front==queue.rear)
 printf("%i ",queue.elements[queue.front]);
 else
 {
 int i=queue.front;
 do
 {
 printf("%i ",queue.elements[i]);
 i=()%queue.capacity;
 }
 while (i!=queue.rear);
 printf("%i ",queue.elements[i]);
 }
 printf("\n");
}


