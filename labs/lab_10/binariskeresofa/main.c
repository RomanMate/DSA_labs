#include <stdio.h>
#include "binarisfa.h"

int main(void) {
    freopen("data.txt", "r", stdin);
    Barat uj;
    Node *head=NULL;
    while ((scanf("%[^;];%d;%d;%d;%c;%d\n",
            uj.nev,
            &uj.szuletesiDatum.ev,
            &uj.szuletesiDatum.honap,
            &uj.szuletesiDatum.nap,
            &uj.nem,
            &uj.bulizas) != EOF))
    {
        if(head==NULL) {
            head = newNode(uj);
        }
         else
         {
             insertAtEnd(&head,uj);
         }
    }
    printList(head);
    return 0;
}
