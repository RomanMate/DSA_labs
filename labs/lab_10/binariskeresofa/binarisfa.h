//
// Created by Román Máté on 2025. 04. 28..
//

#ifndef BINARISFA_H
#define BINARISFA_H

typedef struct Datum {
    int ev;
    int honap;
    int nap;
} Datum;
typedef struct Barat {
    char nev[100];
    Datum szuletesiDatum;
    char nem;
    int bulizas;
} Barat;
typedef struct Node{
    Barat data;
    struct Node* next;
}Node;


#endif //BINARISFA_H
