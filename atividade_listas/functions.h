#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define MAX 150

int menu(){
    int opcao;
    printf("1- Criar Lista\n");
    printf("2- Inserir no INICIO da lista\n");
    printf("3- Inserir no MEIO da lista\n");
    printf("4- Inserir no FINAL da lista\n");
    printf("5- Inserir em ordem crescente\n");
    printf("6- Remover no INICIO da lista\n");
    printf("7- Remover no MEIO da lista\n");
    printf("8- Remover no FINAL da lista\n");
    printf("9- Buscar PRIMEIRO  elemento da lista\n");
    printf("10- Buscar elemento no MEIO da lista\n");
    printf("11- Buscar ULTIMO elemento da lista\n");
    printf("11- Mostrar Todos\n");
    printf("0- Sair\n");
    scanf("%d",&opcao);
    system("clear");
    return opcao;
}

int

struct lista{
  int tamanho;
  int registros[MAX];
};

typedef struct lista Lista;

//cria lista
Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));

    if(li != NULL){
        li -> tamanho = 0;
    }
    return li;
}
//libera lista
void libera_lista(Lista* li) {
    free(li);
}
//tamanho lista
int tamanho_lista(Lista* li) {
    if(li == NULL) {
        return -1;
    }else {
        return li -> tamanho;
    }
}

//lista vazia
int lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        return (li -> tamanho == 0);
    }
}
//lista cheia
int lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        return (li -> tamanho == MAX);
    }
}
//lista dados
void lista_dados(Lista* li){
    int i=0;
    printf("O tamanho da lista e: %d\n", li->tamanho);
    while(i < li-> tamanho){
        printf("%d\t", li -> registros[i]);
        i++;
    }
    printf("\n");
}
//insere final
int insere_final_lista(Lista* li, int valor){
    if(li == NULL){
        return -1;
    }if(lista_cheia(li)){
        return -1;
    }else{
        li -> registros[li -> tamanho] = valor;
        li -> tamanho++;
        return li -> tamanho;
    }
}
//insere inicio
int insere_inicio_lista(Lista* li, int valor){
    int i;
    if(li == NULL){
        return -1;
    }if (lista_cheia(li)){
        return -1;
    }else{
        for (i = li -> tamanho-1;  i >= 0; i--){
            li -> registros[i+1] = li -> registros[i];
        }
        li -> registros[0] = valor;
        li -> tamanho++;
        return 0;
    }
}
//insere ordenado
int insere_ordenado_lista(Lista* li, int valor){
    int i = 0,k;
    if (li == NULL){
        return -1;
    }if (lista_cheia(li)){
        return -1;
    }else{
        while(i < li -> tamanho && li -> registros[i] < valor){
            i++;
        }
        for (k = li -> tamanho-1; k >= i; k--){
            li -> registros[k+1] = li -> registros[k];
        }
        li -> registros[i] = valor;
        li -> tamanho++;
        return i;
    }
}
//insere meio
void insere_posicao_lista(Lista* li, int valor, int posicao){
    int i;
    if(li == NULL){
        return -1;
    }if(lista_cheia(li)){
        return -1;
    }if(posicao > li -> tamanho){
        return -1;
    }else{
        for (i = li -> tamanho-1; i >= posicao-1; i--){
            li -> registros[i+1] = li -> registros[i];
        }
        li -> registros[posicao-1] = valor;
        li -> tamanho ++;
        return posicao;
    }
}
//remocao final lista
void remove_final_lista(Lista* li){
    if(li == NULL){
        return -1;
    }if (lista_vazia(li)){
        return -1;
    }else{
        li -> tamanho--;
        return 1;
    }
}
//remocao posicao lista
int remove_posicao_lista(Lista* li, int posicao){
    int i;
    if(li == NULL){
        return -1;
    }if(lista_vazia(li)){
        return -1;
    }if(posicao > li -> tamanho){
        return -1;
    }else{
        for (i = posicao-1;i < li -> tamanho-1; i++){
            li -> registros[i] = li -> registros[i+1];
        }
        li -> tamanho--;
        return 1;
    }
}
//busca
int busca(Lista* li, int valor){
    int i;
    if(li == NULL || lista_vazia(li)){
        return -1;
    }else{
        for (i = 0; i< li -> tamanho; i++){
            if(li -> registros[i] == valor){
                return i+1;
            }
        }
        return -1;
    }
}
#endif // FUNCOESLISTAS_H_INCLUDED
