#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "npilhas.h"


struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

struct elementoLista{
    Pilha *pd;
    struct elementoLista *prox;
};

typedef struct elementoLista Elmlista;
//struct conjunto pilhas{

//};

Pilha * inicializar(Pilha *pd){
 //   pd->prox = NULL;

    return pd;
}


Pilha* criar(){
    Pilha *pd;
    pd = (Pilha*) malloc(sizeof(Pilha));
    if(pd != NULL){
        *pd = NULL;
    }
    return pd;
}

int vazia(Pilha *pd){
    if(pd == NULL){
        return 1;
    }else if(*pd == NULL){
        return 1;
    }else{
        return 0;
    }
}


int cheia(Pilha *pd, int n){
    if(vazia)
        return 0;
    if(tamanho == n)
        return 1;
    return 0;
}

int tamanho(Pilha *pd){
    if(pd == NULL){
        return 0;
    }else if(vazia(pd)){
        return 0;
    }else{
        int cont = 0;
        Elemento *aux = *pd;
        while(aux != NULL){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
}

int inserir(Pilha *pd, struct aluno dados){
    if (pd == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->prox = *pd;
            *pd = novo;
            return 1;
        }
    }
}

int remover(Pilha *pd){
    if(vazia(pd)){
        return 0;
    }else{
        Elemento *aux = *pd;
        *pd = aux->prox;
        free(aux);
        return 1;
    }
}


int acessar(Pilha *pd, struct aluno *a){
    if(vazia(pd)){
        return 0;
    }else{
        *a = (*pd)->dados;
        return 1;
    }
}


int imprimePilha(Pilha *pd){
    if(vazia(pd)){
        printf("lista vazia, tente outra vez!\n");
        return 0;
    }else{
        Elemento *aux = *pd;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", aux->dados.nome, aux->dados.matricula);
            printf("--------------------------------\n");
            aux = aux->prox;
        }
        return 1;
    }
}


//codgio lista


Lista* criarLista(){
    Lista *ldse;
    ldse = (Lista *)malloc(sizeof(Lista));
    if(ldse != NULL){
        *ldse = NULL;
    }
    return ldse;
}



/*int imprimeLista(Lista *ldse){
    if(ldse == NULL){
        return 0;
    }else{
        Elemento *aux = *ldse;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", aux->dados.nome, aux->dados.matricula);
            printf("--------------------------------\n");
//            aux = aux->proximo;
        }
        return 1;
    }
}
*/
