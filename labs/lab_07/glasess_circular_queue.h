//
// Created by balin on 2025. 03. 31.
//

#ifndef GLASESS_CIRCULAR_QUEUE_H
#define GLASESS_CIRCULAR_QUEUE_H



enum Type {glass, plastic, other};
typedef struct {
 char color[25];
 float volum;
 enum Type type;
}GLASS;

static const GLASS glass0 = {"", 0, 0};

typedef struct {
    int capacity;
    int front;
    int rear;
    GLASS *elements;
}CircularQueue_t;

void createQueue(int capacity, CircularQueue_t *queue);
/**
 * Deallocates the elements array -> free
 * @param queue
 */
void destroyQueue(CircularQueue_t* queue);
/**
 * Checks whether the queue is full or not
 * @param queue
 * @return true/false
 */
bool isFull(CircularQueue_t queue);
/**
 * Checks whether the queue is empty or not
 * @param queue
 * @return true/false
 */
bool isEmpty(CircularQueue_t queue);

void readOneGlass(GLASS *glass);
/**
 * Adds a new item to the end of the queue
 * @param queue
 * @param item
 */
void enqueue(CircularQueue_t* queue, GLASS glass);
/**
 * Removes the first item from the queue
 * @param queue
 * @return
 */
GLASS dequeue(CircularQueue_t* queue);

void printOneGlass(GLASS glass);

char *getDescriptionType(enum Type type);

/**
 * Prints all items of the queue
 * @param queue
 */
void display(CircularQueue_t queue);
/**
 * Returns the element in the front
 * @param queue
 * @return the element in the front
 */
GLASS peek(CircularQueue_t queue);

void display_red_glasses(CircularQueue_t glass);

#endif //GLASESS_CIRCULAR_QUEUE_H
