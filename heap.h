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
    int capacidade;
} MinHeap;

MinHeap* criarHeap(int capacidade);
void destruirHeap(MinHeap* heap);
int pai(int i);
int filhoEsq(int i);
int filhoDir(int i);
int estaVazio(MinHeap* heap);
int estaCheio(MinHeap* heap);
void inserirElemento(MinHeap* heap ,Elemento novoElemento); // funçao inserir elemento
void subir(MinHeap* heap, int i);           // funçao que organiza heap das folhas p/ a raiz

#endif