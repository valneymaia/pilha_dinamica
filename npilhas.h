#ifndef NPILHAS_H_INCLUDED
#define NPILHAS_H_INCLUDED

#define MAX 5

struct aluno{
    char nome[50];
    int matricula;
};

typedef struct elemento* Pilha;
typedef struct elementoLista *Lista;

Pilha* criar();
int vazia(Pilha *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
int acessar(Pilha*, struct aluno *);
int imprimePilha(Pilha* pd);
int cheia(Pilha *pd, int n);
int tamanho(Pilha *pd);


Lista* criarLista();
int imprimeLista(Lista *ldse);


#endif // NPILHAS_H_INCLUDED
