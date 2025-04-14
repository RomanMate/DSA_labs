#include "glass_circular_queue.h"
#include <stdio.h>
int main() {
    /*glass glass1={"light green", 0.5, 0};
    kiirEgyglass(glass1);
    glass glass2;
    beolvasEgyglass(&glass2);
    kiirEgyglass(glass2);*/
    printf("Glasses in array\n");
    int capacity = 100, n;
    freopen("glasses.txt", "r", stdin);
    scanf("%i", &n);//n a glasses szama
    GLASS glass;
    GLASSARRAY glasses;
    Stack stack;
    Queue queue;
    createGlassArray(capacity, &glasses);
    for (int i = 0; i < n; ++i) {
        readOneGlass(&glass);
        insertLast(&glasses, glass);
    }
    printGlasses(glasses);
    printf("Glasses in stack\n");
    createStack(capacity, &stack);
    for (int i = 0; i < n; ++i) {
        readOneGlass(&glass);
        pushStack(&stack, glass);
    }
    printf("The top glass ");
    printOneGlass(peek(stack));
    printf("Glasses in queue\n");
    createQueue(capacity, &queue);
    for (int i = 0; i < n; ++i) {
        readOneGlass(&glass);
        enqueue(&queue, glass);
    }
    displayCircQueue(queue);
    return 0;
}