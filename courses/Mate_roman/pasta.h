//
// Created by Román Máté on 2025. 04. 07..
//

#ifndef PASTA_H
#define PASTA_H

enum Type {SPAGETTI, PENNE, FUSILLI, TAGLIATELLE, MACRONI, MAS};
typedef struct {
    char name[31];
    int mennyiseg;
    enum Type tipus;
    bool glutenmentes;
}PASTA;

typedef struct {
    int capacity;
    int front;
    int rear;
    PASTA *elements;
}CircularQueue_t;
static const PASTA pasta0 = {"", 0, 0,0};
void createQueue(CircularQueue_t *queue);
void destroyQueue(CircularQueue_t* queue);
bool isFull(CircularQueue_t queue);
bool isEmpty(CircularQueue_t queue);
void readOnePasta(PASTA *pasta);
void printOnePasta(PASTA pasta);
char *getDescriptionType(enum Type type);
char *getDescriptionGluten(bool glutenmentese);
void display(CircularQueue_t queue);
void enqueue(CircularQueue_t* queue, PASTA glass);
PASTA dequeue(CircularQueue_t* queue);
PASTA peek(CircularQueue_t queue);

#endif //PASTA_H
