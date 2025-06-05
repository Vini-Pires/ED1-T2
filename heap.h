#ifndef HEAP_H
#define HEAP_H

#include "main.h"

typedef struct{
    int id;
    char nome[30];
} Elemento;

typedef struct{
    Elemento* dados;
    int tamanho;
} MinHeap;

#endif