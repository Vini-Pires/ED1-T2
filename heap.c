#include "heap.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MinHeap* criarHeap(int capacidade){
    MinHeap* heap = malloc(sizeof(MinHeap));
    if(!heap){
        printf("Erro ao alocar memória pra heap!\n");
        exit(1);
    }

    if(capacidade > 0){
        heap->dados = malloc(capacidade * sizeof(Elemento));
        if (!heap->dados){
            free(heap);
            exit(1);
        }
    }else{
        heap->dados = NULL;
        printf("A capacidade deve ser maior que 0!\n");
    }

    heap->tamanho = 0; // INICIALIZA O CONTADOR DO TAMANHO DO VETOR COMO 0
    heap->capacidade = capacidade; // ATUALIZA A CAPACIDADE DO VETOR PARA O TAMANHO ALOCADO
    return heap;
}

void destruirHeap(MinHeap* heap){
    if(estaVazio(heap)){
        printf("Não há nada para ser destruido!\n");
        return;
    }    
    if(heap->dados != NULL){
        free(heap->dados);
    }

    free(heap);
    printf("Heap destruida com sucesso!\n");
}

int pai(int i){
    return (i - 1) / 2;
}

int filhoEsq(int i){
    return 2 * i + 1;
}

int filhoDir(int i){
    return 2 * i + 2;
}

int estaVazio(MinHeap* heap){
    if(heap == NULL){
        return 1;
    }
    return heap->tamanho == 0; // RETORNA 1 SE O TAMANHO DA HEAP FOR == 0 (VAZIO) 
                               // RETORNA 0 SE O TAMANHO FOR > 0
}

int estaCheio(MinHeap* heap){
    if(heap == NULL){
        return 0;
    }
    return heap->tamanho == heap->capacidade; // RETORNA 1 SE FOR VERDADEIRA A CONDIÇÃO
                                              // E 0 SE FOR FALSO
}

void trocarElementos(MinHeap* heap, int i, int j) {
    Elemento temp = heap->dados[i]; // Guarda o elemento de 'i' temporariamente
    heap->dados[i] = heap->dados[j]; // Coloca o elemento de 'j' na posição 'i'
    heap->dados[j] = temp;           // Coloca o elemento temporário (original de 'i') na posição 'j'
}

void subir(MinHeap* heap, int i) {
    while (i > 0 && heap->dados[i].id < heap->dados[pai(i)].id) {  // se o elemento na posiçao i for menor que a do pai(i) e se o elemento nao for a raiz -> continua o loop
      
        trocarElementos(heap, i, pai(i));                          
        i = pai(i);        // agora a posiçao de i passou a ser a que era de seu pai para que o loop funcione depois

    }
}

void inserirElemento(MinHeap* heap, Elemento novoElemento) {
    if (heap == NULL) { 
        printf("Erro: Heap não inicializado. Não é possível inserir.\n");
        return;
    }

    if (estaCheio(heap)) {
        printf("Erro: Heap está cheio. Não é possível inserir o elemento (ID: %d, Nome: %s).\n", novoElemento.id, novoElemento.nome);

        // COLOCAR A LOGICA PARA DOBRAR A CAPACIDADE !!!!!

        return;
    }

    heap->dados[heap->tamanho] = novoElemento;  //Insere o novo elemento na primeira posição vazia 

    heap->tamanho++;    //Incrementa o 'tamanho' do heap

    subir(heap, heap->tamanho - 1);     // garantir que o elemento esta no lugar certo

    printf("Elemento (ID: %d, Nome: %s) inserido com sucesso!\n", novoElemento.id, novoElemento.nome);
}