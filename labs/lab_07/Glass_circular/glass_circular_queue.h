//
// Created by Román Máté on 2025. 03. 31..
//

#ifndef GLASS_CIRCULAR_QUEUE_H
#define GLASS_CIRCULAR_QUEUE_H

enum Type {glass, plastic, other};
typedef struct {
    char color[25];
    float volum;
    enum Type type;
}GLASS;
typedef struct {
    int capacity;
    int size;
    GLASS *elements;
}GLASSARRAY;
    typedef struct {
    int capacity;
    int top;
GLASS *elements;
}Stack;
    typedef struct{
    int capacity;
    int front;
    int rear;
GLASS *elements;
}Queue;


void readOneGlass(GLASS *glass);
void printOneGlass(GLASS glass);
char *getDescriptionType(enum Type type);

void createGlassArray(int capacity, GLASSARRAY *pGlassArray);
bool isEmptyArray(GLASSARRAY glassArray);
bool isFullArray(GLASSARRAY glassArray);
void insertFirst(GLASSARRAY* pglassArray, GLASS glass);
void insertLast(GLASSARRAY* pglassArray, GLASS glass);
void insertAt(GLASSARRAY* pglassArray, int index, GLASS glass);
void printGlasses(GLASSARRAY glasses);

bool isFullStack(Stack stack);
bool isEmptyStack(Stack stack);
GLASS peek(Stack stack);
void createStack(int capacity, Stack *stack);
void pushStack(Stack *stack, GLASS item);
GLASS popStack(Stack *stack);

void createQueue(int capacity, Queue *queue);
void enqueue(Queue *queue, GLASS item);
GLASS dequeue(Queue *queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);
void display(Queue queue);

void createQueueCirc(Queue *glasscq);
void enqueueCirc(Queue *glasscq, GLASS glass);
bool isEmptyCirc(Queue queue);
bool isFullCirc(Queue queue);
void displayCircQueue(Queue glassacq);
#endif //GLASS_CIRCULAR_QUEUE_H
