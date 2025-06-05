#ifndef HEAP_H
#define HEAP_H

#include "main.h"

typedef struct NoHeap{
    int id;
    char nome[30];
    struct NoHeap* dir;
    struct NoHeap* esq;
} NoHeap;

typedef struct{
    int id;
    char nome[30];
} Elemento;

typedef struct{
    Elemento dados[20];
    int tamanho;
} MinHeap;

#endif