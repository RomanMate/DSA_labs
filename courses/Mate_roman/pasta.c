//
// Created by Román Máté on 2025. 04. 07..
//

#include "pasta.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void createQueue(CircularQueue_t *queue) {
    queue->elements=(PASTA*)malloc(20*sizeof(PASTA));
    if (!queue->elements) {perror("Memory allocation error!"); exit(-1);}
    queue->front = queue->rear = -1;
}
void destroyQueue(CircularQueue_t *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->capacity = 0;
    queue->front = queue->rear = -1;
}
bool isFull(CircularQueue_t queue){
    return (queue.front == (queue.rear + 1) % queue.capacity);
}
bool isEmpty(CircularQueue_t queue) {
    return (queue.front == -1);
}
void readOnePasta(PASTA *pasta) {
    scanf("\n%[^\n]\n",pasta->name);
    scanf("%i",&pasta->mennyiseg);
    scanf("%d",&pasta->tipus);
    scanf("%d",&pasta->glutenmentes);
}
char *getDescriptionType(enum Type type) {
    switch (type) {
        case 0: return "SPAGETTI";
        case 1: return "PENNE";
        case 2: return "FUSILLI";
        case 3: return "TAGLIATELLE";
        case 4: return "MACARONI";
        case 5: return "EGYEB";
        default: return "OTHER";
    }
}
void printOnePasta(PASTA pasta) {
    printf("%s, %i g, %s, %s\n",pasta.name,pasta.mennyiseg,getDescriptionType(pasta.tipus),getDescriptionGluten(pasta.glutenmentes));
}

char *getDescriptionGluten(bool glutenmentese) {
    switch (glutenmentese) {
        case 0: return "NEM GLUTENMENTES";
        case 1: return "GLUTENMENTES";
        default: return "NEM ELDONTHETO";
    }
}
void enqueue(CircularQueue_t *queue, PASTA pasta) {
    if (isFull(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    readOnePasta(&pasta);
    queue->elements[queue->rear] = pasta;
}
void display(CircularQueue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (true) {
        printOnePasta(queue.elements[i]);
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    printf("\n");
}
PASTA dequeue(CircularQueue_t* queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty!\n");
        return pasta0;
    }
    PASTA temp = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return temp;
}



