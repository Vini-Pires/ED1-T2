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
    system("clear");

    do{
        printf("=-=-=-=-=-= MENU =-=-=-=-=-=\n");
        printf("1 - Inserção\n");
        printf("2 - Remoção\n");
        printf("3 - Pesquisa rápida\n");
        printf("4 - Destruir Heap\n");
        printf("5 - Listar\n");
        printf("0 - Sair\n");
        printf("Opcão: ");
        scanf("%i", &opcao);
        switch(opcao){
            case 1:
                { 
                    Elemento novoElemento; // Declara uma variável do tipo Elemento

                    system("clear");
                    printf("--- Inserir Novo Elemento ---\n");
                    printf("Digite o ID (numero): ");
                    scanf("%d", &novoElemento.id); // Lê o ID para o campo 'id' do novoElemento

                    printf("Digite o Nome (max 29 caracteres): ");

                    while (getchar() != '\n');      // Limpa o buffer do teclado

                    LeString(novoElemento.nome, 30);

                    inserirElemento(heap, novoElemento);

                    printf("Pressione Enter para voltar ao menu \n");
                    setbuf(stdin, NULL);
                    while (getchar() != '\n');
                    system("clear");
                }
                break;
            case 2:
                system("clear");
                RemoverElemento(heap);
                break;
            case 3:
                PesquisaRapida(heap);
                break;
            case 4:
                system("clear");
                destruirHeap(heap);
                heap = criarHeap(capacidadeInicial);
                break;
            case 5:
                system("clear");
                ExibirHeap(heap);
                break;
            case 0: 
                printf("Saindo do programa!\n");
                break;
        }
        if(opcao < 0 || opcao > 5){
            system("clear");
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);


    return;
}