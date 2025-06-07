#include "main.h"
#include "menu.h"
#include "heap.h"

/*
Interface completa, funcional e fácil
de usar. Permite inserção, remoção,
pesquisa e visualização clara
*/

void menu(){

    int opcao;
    int capacidadeInicial = 10;
    MinHeap* heap = criarHeap(capacidadeInicial);

    do{
        printf("=-=-=-=-=-= MENU =-=-=-=-=-=\n");
        printf("1 - Inserção\n2 - Remoção\n3 - Pesquisa rápida\n4 - Destruir Heap\n0 - Sair\n");
        printf("Opcão: ");
        scanf("%i", &opcao);
        switch(opcao){
            case 1:
                //InserirElemento(); 
                //IMPLEMENTAR A MULTIPLICAÇÃO DA CAPACIDADE POR 2 NO INSERIR ELEMENTO
                //AO CHEGAR NO TAMANHO MAX DE ALOCAÇÕES (10) DOBRA PRA (20)
                break;
            case 2:
                
                break;
            case 3:

                break;
            case 4:
                system("clear");
                destruirHeap(heap);
                heap = criarHeap(capacidadeInicial);
                break;
            case 0: 
                printf("Saindo do programa!\n");
                break;
        }
        if(opcao < 0 || opcao > 4){
            system("clear");
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);


    return;
}