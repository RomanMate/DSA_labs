//
// Created by Román Máté on 2025. 03. 31..
//

#include "glass_circular_queue.h"
#include <stdio.h>
#include <stdlib.h>
void readOneGlass(GLASS *glass) {
    scanf("\n%[^\n]",glass->color);
    scanf("%f",&glass->volum);
    scanf("%d",&glass->type);
}
void printOneGlass(GLASS glass) {
    printf("%s %.2f %s\n",glass.color,glass.volum,getDescriptionType(glass.type));
}
char *getDescriptionType(enum Type type) {
    switch (type) {
        case 0: return "GLASS";
        case 1: return "PLASTIC";
        default: return "OTHER";
    }
}
void createGlassArray(int capacity, GLASSARRAY *pGlassArray) {
    pGlassArray->capacity = capacity;
    pGlassArray->size = 0;
    pGlassArray->elements = (GLASS *)calloc(capacity, sizeof(GLASS));
    if(!pGlassArray->elements){
        printf("Memory Allocation Error!");
        exit(-1);
    }
}
bool isEmptyArray(GLASSARRAY poharArray) {
    return poharArray.size == 0;
}
bool isFullArray(GLASSARRAY poharArray) {
    return poharArray.size == poharArray.capacity;
}
void insertFirst(GLASSARRAY *pGlassArray, GLASS pohar) {
    if(isFullArray(*pGlassArray)){
        printf("The Array is already Full!");
    }
    for (int i = pGlassArray->size-1; i >= 0; --i) {
        pGlassArray->elements[i+1]= pGlassArray->elements[i];
    }
    pGlassArray->elements[0] = pohar;
    pGlassArray->size++;
}
void insertLast(GLASSARRAY *pGlassArray, GLASS pohar) {
    if(isFullArray(*pGlassArray))return;
    pGlassArray->elements[pGlassArray->size++] = pohar;
}
void insertAt(GLASSARRAY *pGlassArray, int index, GLASS pohar) {
    if(isFullArray(*pGlassArray))return;
    if(index < 0 || index > pGlassArray->size){
        printf("Invalid Position!");
        return;
    }
    if(pGlassArray->size == index){
        insertLast(pGlassArray, pohar);
        return;
    }
    for (int i = pGlassArray->size-1; i >=index ; --i) {
        pGlassArray->elements[i+1]=pGlassArray->elements[i];
    }
    pGlassArray->elements[index] = pohar;
    pGlassArray->size++;
}
void deleteItemAt(GLASSARRAY *pArray, int position) {
    if (isEmptyArray(*pArray)) {
        printf("ARRAY_EMPTY_ERROR_MESSAGE");
        return;
    }
    if (position < 0 || position >= pArray->size) {
        printf("INVALID_POSITION_ERROR_MESSAGE");
        return;
    }
    for (int i = position; i < pArray->size - 1; i++) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->size--;
}
void printGlasses(GLASSARRAY glasses) {
    for(int i = 0; i < glasses.size; i++){
        printOneGlass(glasses.elements[i]);
    }
}
bool isFullStack(Stack stack) {
    return stack.top == stack.capacity - 1;
}
bool isEmptyStack(Stack stack) {
    return stack.top == -1;
}
GLASS peek(Stack stack) {
    if (isEmptyStack(stack)) {
        GLASS uresPohar={"",0,0};
        printf("Stack is empty!");
        return uresPohar;
    }
    GLASS temp = stack.elements[stack.top];
    return temp;
}
void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (GLASS *)calloc(stack->capacity, sizeof (GLASS));
    if(!stack->elements) {
        printf("MEMORY_ALLOCATION_ERROR_MESSAGE");
        exit(-1);
    }
}
void pushStack(Stack *stack, GLASS item) {
    if(isFullStack(*stack)) {
        printf("its full");
        return;
    }
    stack->elements[++stack->top] = item;
}
GLASS popStack(Stack *stack) {
    GLASS defPohar = {"blank", 0, 2};
    if (isEmptyStack(*stack)) {
        printf("its empty");
        exit(-3);
    }
    GLASS save = stack->elements[stack->top];
    stack->elements[stack->top--] = defPohar;
    return save;
}
void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (GLASS*)calloc(10, sizeof(GLASS));
    if(!queue->elements){
        printf("Memory allocation failed!");
        exit(-1);
    }
}
bool isFull(Queue queue) {
    return queue.rear == queue.capacity -1;
}
bool isEmpty(Queue queue) {
    return queue.front == -1;
}
void enqueue(Queue *queue, GLASS item) {
    if(isFull(*queue)) {
        printf("FULL_MESSAGE");
        return;
    }
    if(isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
}
GLASS dequeue(Queue *queue) {
    GLASS uresPohar={"",0,0};
    if(isEmpty(*queue)){
        printf("Queue is empty");
        return uresPohar;
    }
    int poz = queue->front;
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
        return queue->elements[poz];
    }
    else{
        queue->front++;
    }
    return queue->elements[poz];
}
void display(Queue queue) {
    printf("Poharak:\n");
    for (int i = queue.front; i <= queue.rear; ++i) {
        printOneGlass(queue.elements[i]);
    }
}
bool isEmptyCirc(Queue queue) {
    return queue.rear == -1;
}
bool isFullCirc(Queue queue) {
    return queue.front == 0 && queue.rear == queue.capacity-1 ||
    queue.rear==queue.front-1;
}
GLASS dequeueCQ(Queue *poharcq) {
    if(isEmptyCirc(*poharcq)) {
        printf("CQ is empty");
        exit(-3);
    }
    GLASS result;
    result = poharcq->elements[poharcq->front];
    if(poharcq->front == poharcq->rear){
        poharcq->front = -1;
        poharcq->rear = -1;
    }
    else
    {
        poharcq->front = (poharcq->front ++) % poharcq->capacity;
    }
    return result;
}
void enqueueCirc(Queue *poharcq, GLASS pohar) {
    if (isFullCirc(*poharcq)) {
        printf("Pohar is full. Cannot enqueue more items.\n");
        return;
    }
    if (isEmptyCirc(*poharcq)) {
        poharcq->front = 0;
    }
    poharcq->rear = (poharcq->rear + 1) % poharcq->capacity;
    poharcq->elements[poharcq->rear]=pohar;
}
void displayCircQueue(Queue poharacq)
{
    int i = poharacq.front;
    do
    {
        printOneGlass(poharacq.elements[i]);
        i = (i + 1) % poharacq.capacity;
    }
    while(i != poharacq.rear);
    printOneGlass(poharacq.elements[poharacq.rear]);
}