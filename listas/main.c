#include <stdio.h>
#include <stdlib.h>
#include "funcoesLista.h"

int main()
{
    Lista* li;

    li = cria_lista();

    printf("Lista vazia %d\n", lista_vazia(li));

    insere_ordenado_lista(li, 25);
    insere_ordenado_lista(li, 20);
    insere_ordenado_lista(li, 15);
    insere_ordenado_lista(li, 10);
    insere_final_lista(li, 30);
    insere_inicio_lista(li, 35);
    insere_posicao_lista(li, 40, 2);
    remove_final_lista(li);

    printf("Lista vazia %d\n", lista_vazia(li));

    printf("Lista cheia %d\n", lista_cheia(li));

    lista_dados(li);

    if(busca(li, 10) > 0){
        printf("O elemento 10 esta inserido na posicao: %d\n", busca(li, 10));
    }else{
        printf("O elemento nao esta inserido\n");
    }

    if(busca(li, 30) > 0){
        printf("O elemento 30 esta inserido na posicao: %d\n", busca(li, 30));
    }else{
        printf("O elemento nao esta inserido\n");
    }

    if(busca(li, 25) > 0){
        printf("O elemento 25 esta inserido na posicao: %d\n", busca(li, 25));
    }else{
        printf("O elemento nao esta inserido\n");
    }
    return 0;
}
