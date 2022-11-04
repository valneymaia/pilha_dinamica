#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "npilhas.h"

#define TAMMAX 2



void menu(){
    printf("_______________________________________\n");
    printf("SELECIONE UMA OPCAO: \n");
    printf("  1 - Inserir aluno. \n");
    printf("  2 - Remover aluno. \n");
    printf("  3 - Acessa topo da pilha. \n");
    printf("  4 - Imprimir pilhas. \n");
    printf("  5 - Fechar progama. \n");
    printf("_______________________________________\nSua opcao: ");
}

struct aluno * preencheAluno(Pilha *pilha, struct aluno *dados){
    char nome[50];
    int numero;
    printf("Nome: \n");
    gets(nome);

    printf("Matricula: \n");
    scanf("%d", &numero);
    while(getchar() != '\n');

    strcpy(dados->nome, nome);
    dados->matricula = numero;

    return dados;
}

void ler_Opcao(Pilha *pilha){
    char op;
    char nomeNovo[50];
    struct aluno * dados = (struct aluno*)malloc(sizeof(struct aluno));
    for(;;){
        menu();
        printf("digite a sua opcao: \n");
        scanf("%C", &op);
        while(getchar()!='\n');
        switch(op){
            case '1':{
                dados = preencheAluno(pilha, dados);
                inserir(pilha, *dados);
                break;}
            case '2':
                if(vazia(pilha) == 1)
                    printf("pilha vazia, nao foi possivel remover.\n");
                else {
                    remover(pilha);
                }
                break;
            case '3':{
                acessar(pilha,dados);
                printf("--------------------------------\n");
                printf("Nome: %s\nMatricula: %d\n", dados->nome, dados->matricula);
                printf("--------------------------------\n");
                break;}
            case '4':{
                imprimePilha(pilha);
                break;}
            case '5':{
                printf("\n_______________\nFinalizando...\n");
                return;
                break;}
            default:
                printf("opcao invalida! \n");
        }
    }
}

int main(){
    Pilha *pilha;
    pilha = criar();
//    printf("digite o limite de tamnho da pilha: \n");
 //   scanf("%d", &lim);
 //   while( getchar() != '\n');
    ler_Opcao(pilha);
    return 0;
}



/*Imagine uma pilha de livros (literalmente).
Se a pilha fica muito alta, ela pode tombar. Por isso, na vida real,
quando estamos organizando livros,
n�s geralmente come�amos uma nova pilha quando a pilha anterior excede uma determinada capacidade.
Implemente uma estrutura de dados chamada "conjunto de pilhas" que simula essa situa��o.
Um conjunto de pilhas dever� ser composta de v�rias pilhas e deve criar uma nova pilha quando a pilha anterior exceder a capacidade.
As fun��es de "empilhar" e "desempilhar" devem se comportar de forma id�ntica a uma pilha individual.
Isto �, essa fun��es devem retornar os mesmos valores que uma pilha �nica retornaria.
Voc� pode definir a capacidade m�xima de uma pilha usando uma constante ou pedindo que o usu�rio forne�a como entrada.
*/
