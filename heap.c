#include "heap.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Lê uma string do usuário e remove o caractere de nova linha.
 * 
 * @param string Vetor onde a string lida será armazenada.
 * @param tamanho Tamanho máximo da string (incluindo '\0').
 */
void LeString(char string[], int tamanho){
    setbuf(stdin, NULL);
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
} // LEITURA DE STRINGS DO USUARIO


/**
 * @brief Cria uma nova MinHeap com capacidade especificada.
 * 
 * @param capacidade Capacidade máxima de elementos da heap.
 * @return Ponteiro para a nova MinHeap alocada.
 */
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


/**
 * @brief Libera toda a memória alocada por uma MinHeap.
 * 
 * @param heap Ponteiro para a heap a ser destruída.
 */
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


/**
 * @brief Retorna o índice do nó pai de um dado índice.
 * 
 * @param i Índice do nó filho.
 * @return Índice do nó pai.
 */
int pai(int i){
    return (i - 1) / 2;
}


/**
 * @brief Retorna o índice do filho esquerdo de um dado índice.
 * 
 * @param i Índice do nó pai.
 * @return Índice do filho esquerdo.
 */
int filhoEsq(int i){
    return 2 * i + 1;
}


/**
 * @brief Retorna o índice do filho direito de um dado índice.
 * 
 * @param i Índice do nó pai.
 * @return Índice do filho direito.
 */
int filhoDir(int i){
    return 2 * i + 2;
}


/**
 * @brief Verifica se a heap está vazia.
 * 
 * @param heap Ponteiro para a heap.
 * @return 1 se vazia ou NULL, 0 caso contrário.
 */
int estaVazio(MinHeap* heap){
    if(heap == NULL){
        return 1;
    }
    return heap->tamanho == 0; // RETORNA 1 SE O TAMANHO DA HEAP FOR == 0 (VAZIO) 
                               // RETORNA 0 SE O TAMANHO FOR > 0
}


/**
 * @brief Verifica se a heap está cheia.
 * 
 * @param heap Ponteiro para a heap.
 * @return 1 se cheia, 0 caso contrário.
 */
int estaCheio(MinHeap* heap){
    if(heap == NULL){
        return 0;
    }
    return heap->tamanho == heap->capacidade; // RETORNA 1 SE FOR VERDADEIRA A CONDIÇÃO
                                              // E 0 SE FOR FALSO
}


/**
 * @brief Troca dois elementos de posição na heap.
 * 
 * @param heap Ponteiro para a heap.
 * @param i Índice do primeiro elemento.
 * @param j Índice do segundo elemento.
 */
void trocarElementos(MinHeap* heap, int i, int j){
    Elemento temp = heap->dados[i]; // Guarda o elemento de 'i' temporariamente
    heap->dados[i] = heap->dados[j]; // Coloca o elemento de 'j' na posição 'i'
    heap->dados[j] = temp;           // Coloca o elemento temporário (original de 'i') na posição 'j'
}


/**
 * @brief Reorganiza a heap para manter a propriedade da MinHeap após inserção.
 * 
 * @param heap Ponteiro para a heap.
 * @param i Índice do elemento a subir.
 */
void subir(MinHeap* heap, int i) {
    while (i > 0 && heap->dados[i].id < heap->dados[pai(i)].id) {  // se o elemento na posiçao i for menor que a do pai(i) e se o elemento nao for a raiz -> continua o loop
      
        trocarElementos(heap, i, pai(i));                          
        i = pai(i);        // agora a posiçao de i passou a ser a que era de seu pai para que o loop funcione depois

    }
}


/**
 * @brief Insere um novo elemento na heap e reorganiza para manter a ordem.
 * 
 * @param heap Ponteiro para a heap.
 * @param novoElemento Elemento a ser inserido.
 */
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


/**
 * @brief Exibe todos os elementos da heap no terminal.
 * 
 * @param heap Ponteiro para a heap.
 */
void ExibirHeap(MinHeap* heap){
    if(estaVazio(heap)){
        system("clear");
        printf("A heap está vazia!\n");
        return;
    }
    printf("%-8s | %-4s | %s\n","Posição", "ID", "NOME");
    for(int i = 0; i < heap->tamanho; i++){
        printf("%-7i - |%-4i| %-20s\n", i+1, heap->dados[i].id, heap->dados[i].nome);
    }

    return;
}


/**
 * @brief Permite pesquisar elementos na heap por nome ou ID.
 * 
 * @param heap Ponteiro para a heap.
 */
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


/**
 * @brief Reorganiza a heap para manter a propriedade da MinHeap após remoção.
 * 
 * @param heap Ponteiro para a heap.
 * @param i Índice do elemento a descer.
 */
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


/**
 * @brief Remove um elemento da heap com base no ID ou nome.
 * 
 * @param heap Ponteiro para a heap.
 */
void RemoverElemento(MinHeap* heap){
    if(estaVazio(heap)){
        system("clear");
        printf("A Heap está vazia!\n");
        return;
    }

    int opcao,id,i;
    char nome[30];
    bool encontrado = false;

    printf("ID->| 1 | \n NOME->| 2 |\n ");
    scanf("%d", &opcao);

    do{

            switch(opcao){
        
                case 1:
        
                    printf("Digite o ID que deseja remover: \n");
                    scanf("%d", &id);
        
                        for(i = 0; i < heap->tamanho; i++){
                            if(heap->dados[i].id == id){
                                encontrado = true;
                                break;
                            }
                        }
        
                    break;
        
                case 2:
        
                    printf("Digite o NOME  que deseja remover:\n ");
                    LeString(nome, 30);
                    for(i = 0; i < heap->tamanho; i++){
                        if(strcmp(heap->dados[i].nome, nome) == 0){
                            encontrado = true;
                            break;
                        }
                    }
        
                    break;
        
                default:
                printf("opção invalida!\n");
                return;
                    break;
            }
        
        if(!encontrado){
            printf("Elemento não encontrado.\n");
            return;
        }

    }while(opcao < 1 || opcao > 2);


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
