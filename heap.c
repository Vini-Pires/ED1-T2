#include "heap.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeString(char string[], int tamanho){
    setbuf(stdin, NULL);
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
} // LEITURA DE STRINGS DO USUARIO

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
        system("clear");
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

void trocarElementos(MinHeap* heap, int i, int j){
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

        heap->capacidade *= 2;
        heap->dados = realloc(heap->dados, heap->capacidade * sizeof(Elemento));
        if (heap->dados == NULL){
        printf("Erro ao realocar heap\n");
        exit(1);
        }
        printf("Capacidade Realocada para %i\n", heap->capacidade);

        return;
    }

    heap->dados[heap->tamanho] = novoElemento;  //Insere o novo elemento na primeira posição vazia 

    heap->tamanho++;    //Incrementa o 'tamanho' do heap

    subir(heap, heap->tamanho - 1);     // garantir que o elemento esta no lugar certo

    printf("Elemento (ID: %d, Nome: %s) inserido com sucesso!\n", novoElemento.id, novoElemento.nome);
}

void ExibirHeap(MinHeap* heap){
    if(estaVazio(heap)){
        system("clear");
        printf("A heap está vazia!\n");
        return;
    }
    printf("%-8s | %-4s | %s\n","Posição", "ID", "NOME");
    for(int i = 0; i < heap->tamanho; i++){
        printf("%-7i - %-4i | %-20s\n", i+1, heap->dados[i].id, heap->dados[i].nome);
    }

    return;
}

void PesquisaRapida(MinHeap* heap){
    bool encontrado;
    int opcao, id;
    char nome[30];

    if(estaVazio(heap)){
        system("clear");
        printf("A heap está vazia!\n");
        return;
    }

    system("clear");
    printf("=-=-=-= PESQUISAR =-=-=-=\n");
    printf("1 - Nome\n2 - ID\n3 - Voltar ao menu\n");
    printf("Opcao: ");
    setbuf(stdin, NULL);
    scanf("%i", &opcao);
    switch(opcao){
        case 1:
            system("clear");
            printf("Digite o nome do caboclo: ");
            LeString(nome, 30);
            for(int i = 0; i < heap->tamanho; i++){
                if(strcmp(heap->dados[i].nome, nome) == 0){
                    encontrado = true;
                    printf("%i | %s foi encontrado!\n", heap->dados[i].id, heap->dados[i].nome);
                    break;
                }else{
                    encontrado = false;
                }
            }
            break;  
        case 2:
            system("clear");
            printf("Digite o id do caboclo: ");
            setbuf(stdin, NULL);
            scanf("%i", &id);
            for(int i = 0; i < heap->tamanho; i++){
                if(heap->dados[i].id == id){
                    encontrado = true;
                    printf("%i | %s foi encontrado!\n", heap->dados[i].id, heap->dados[i].nome);
                    break;
                }else{
                    encontrado = false;
                }
            }
            break;
        case 3: 
            system("clear");
            return;
        default: NULL;
    }

    if(!encontrado){
        system("clear");
        printf("O valor não foi encontrado!\n");
    }
    return;
}

void descer(MinHeap* heap, int i){
    int menor = i;                    // Assume que o menor é o próprio nó atual (índice i)
    int esq = filhoEsq(i);        
    int dir = filhoDir(i); 
    
    // Verifica se o filho esquerdo existe e é menor que o nó atual
    if(esq < heap->tamanho && heap->dados[esq].id < heap->dados[menor].id){
        menor = esq;                 // Atualiza o menor para o filho esquerdo
    }

    // Verifica se o filho direito existe e é ainda menor que o menor atual
    if(dir < heap->tamanho && heap->dados[dir].id < heap->dados[menor].id){
        menor = dir;                 // Atualiza o menor para o filho direito
    }

    // Se o menor não for o próprio i, faz a troca e continua descendo
    if(menor != i){
        trocarElementos(heap, i, menor);  // Troca o nó atual com o menor filho
        descer(heap, menor);              // Chamada recursiva para continuar descendo
    }

    // Se menor == i, significa que o nó está na posição correta, então nada é feito
}

void RemoverElemento(MinHeap* heap){
    if(estaVazio(heap)){
        system("clear");
        printf("A Heap está vazia!\n");
        return;
    }

    int id;
    printf("Digite o id do elemento que deseja remover: ");
    scanf("%d", &id);

    int i;
    for(i = 0; i < heap->tamanho; i++){
        if(heap->dados[i].id == id){
            break;
        }
    }

    if(i == heap->tamanho){
        printf("Elemento com id %d não encontrado.\n", id);
        return;
    }

    Elemento removido = heap->dados[i];

    // Substitui pelo último elemento e reduz o tamanho
    heap->dados[i] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;

    // Corrige a heap
    if (i > 0 && heap->dados[i].id < heap->dados[pai(i)].id){
        subir(heap, i);
    } else {
        descer(heap, i);
    }

    printf("Elemento com id %d removido com sucesso.\n", removido.id);
}