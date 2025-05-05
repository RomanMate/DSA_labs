#include <stdio.h>
#include "binary_search_tree.h"
#include <time.h>
#include <stdlib.h>

int main() {

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
                //printf("%s\n",uj.nev);
                 if(head==NULL) {
                     head = createNewNode(uj);
                 }
                 else
                 {
                     insert(head,uj);
                 }
             }
        inorderTraversal(head);
        return 0;
    }
