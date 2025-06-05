#include "main.h"
#include "menu.h"

/*
Interface completa, funcional e fácil
de usar. Permite inserção, remoção,
pesquisa e visualização clara
*/

void menu(){

    int opcao;

    do{
        printf("=-=-=-=-=-= MENU =-=-=-=-=-=\n");
        printf("1 - Inserção\n2 - Remoção\n3 - Pesquisa rápida\n0 - Sair\n");
        printf("Opcão: ");
        scanf("%i", &opcao);
        switch(opcao){
            case 1:
                InserirElemento();
                break;
            case 2:
                
                break;
            case 3:

                break;
            case 0: 
                printf("Saindo do programa!\n");
                break;
        }
        if(opcao < 0 || opcao > 3){
            system("clear");
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);


    return;
}