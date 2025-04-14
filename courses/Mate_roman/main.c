#include <stdio.h>

#include "pasta.h"

int main(void)
{
    PASTA pasta1;
    readOnePasta(&pasta1);
    printOnePasta(pasta1);
    CircularQueue_t pastas;
    createQueue(&pastas);
    int db;
    printf("hany pasztat olvassunk be:");
    scanf("%i",&db);
    if(!freopen("paszta.txt","r",stdin)) {
        printf("hiba a filemegnyitas soran");
    }
    PASTA pasta;
    for(int i=1;i<=db;++i) {
        if(i>20) {
            printf("A talca megtelt");
            break;
        }
        enqueue(&pastas, pasta);
    }
    display(pastas);
    dequeue(&pastas);
    dequeue(&pastas);
    enqueue(&pastas, pasta);
    enqueue(&pastas, pasta);
    display(pastas);
    CircularQueue_t pastagluten;
    createQueue(&pastagluten);
    CircularQueue_t pastaglutenmentes;
    createQueue(&pastaglutenmentes);

    return 0;
}
