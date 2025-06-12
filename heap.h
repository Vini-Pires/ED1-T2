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

/**
 * @brief Cria uma nova MinHeap com capacidade especificada.
 * @param capacidade Capacidade máxima da heap.
 * @return Ponteiro para a MinHeap criada.
 */
MinHeap* criarHeap(int capacidade);

/**
 * @brief Libera a memória utilizada pela heap.
 * @param heap Ponteiro para a heap a ser destruída.
 */
void destruirHeap(MinHeap* heap);

/**
 * @brief Retorna o índice do nó pai.
 * @param i Índice do nó filho.
 * @return Índice do pai.
 */
int pai(int i);

/**
 * @brief Retorna o índice do filho esquerdo.
 * @param i Índice do nó pai.
 * @return Índice do filho esquerdo.
 */
int filhoEsq(int i);

/**
 * @brief Retorna o índice do filho direito.
 * @param i Índice do nó pai.
 * @return Índice do filho direito.
 */
int filhoDir(int i);

/**
 * @brief Verifica se a heap está vazia.
 * @param heap Ponteiro para a heap.
 * @return 1 se vazia, 0 caso contrário.
 */
int estaVazio(MinHeap* heap);

/**
 * @brief Verifica se a heap está cheia.
 * @param heap Ponteiro para a heap.
 * @return 1 se cheia, 0 caso contrário.
 */
int estaCheio(MinHeap* heap);

/**
 * @brief Insere um novo elemento na heap.
 * @param heap Ponteiro para a heap.
 * @param novoElemento Elemento a ser inserido.
 */
void inserirElemento(MinHeap* heap ,Elemento novoElemento); // funçao inserir elemento

/**
 * @brief Reorganiza a heap de baixo para cima para manter a ordem.
 * @param heap Ponteiro para a heap.
 * @param i Índice do elemento a subir.
 */
void subir(MinHeap* heap, int i);           // funçao que organiza heap das folhas p/ a raiz

/**
 * @brief Exibe todos os elementos da heap.
 * @param heap Ponteiro para a heap.
 */
void ExibirHeap(MinHeap* heap);

/**
 * @brief Lê uma string da entrada padrão e remove o '\n' final.
 * @param string Vetor de caracteres onde será armazenada a string.
 * @param tamanho Tamanho máximo da string.
 */
void LeString(char string[], int tamanho);

/**
 * @brief Realiza pesquisa de elemento na heap por nome ou ID.
 * @param heap Ponteiro para a heap.
 */
void PesquisaRapida(MinHeap* heap);

/**
 * @brief Troca dois elementos de posição na heap.
 * @param heap Ponteiro para a heap.
 * @param i Índice do primeiro elemento.
 * @param j Índice do segundo elemento.
 */
void trocarElementos(MinHeap* heap, int i, int j);

/**
 * @brief Reorganiza a heap de cima para baixo para manter a ordem.
 * @param heap Ponteiro para a heap.
 * @param i Índice do elemento a descer.
 */
void descer(MinHeap* heap, int i);

/**
 * @brief Remove um elemento da heap por ID ou nome.
 * @param heap Ponteiro para a heap.
 */
void RemoverElemento(MinHeap* heap);
#endif
