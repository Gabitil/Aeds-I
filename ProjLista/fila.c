/*
  Nome: Gabriel Augusto de Lima Maia
  Data: 01/11/2023

  Objetivo, implementar uma fila com prioridade, onde o primeiro elemento a ser desenfileirado é o que tem a maior prioridade.
  Utilizando a implementação de fila do ziviani.
*/

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#define MAX 10

typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); } 

void Enfileira(TipoItem x, TipoFila *Fila)
{ Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Fila)) { printf("Erro fila esta vazia\n"); return; }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
} 

void Imprime(TipoFila Fila)
{ TipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux->Item.Chave);
      Aux = Aux->Prox;
    }
}

void AumentaPrioridade(TipoFila *Fila, TipoChave chave) {
    if (Vazia(*Fila)) {
        printf("Erro: a fila está vazia\n");
        return;
    }

    TipoApontador anterior = Fila->Frente;
    TipoApontador atual = Fila->Frente->Prox;

    while (atual != NULL && atual->Item.Chave != chave) {
        anterior = atual;
        atual = atual->Prox;
    }

    if (atual == NULL) {
        printf("Erro: chave não encontrada na fila\n");
        return;
    }

    anterior->Prox = atual->Prox;
    if (Fila->Tras == atual) {
        Fila->Tras = anterior;
    }

    atual->Prox = Fila->Frente->Prox;
    Fila->Frente->Prox = atual;
}



int main() {
    TipoFila fila;
    TipoItem item;
    int i;

    FFVazia(&fila);

    for (i = 0; i < 10; i++) {
        item.Chave = i;
        Enfileira(item, &fila);
    }

    printf("Fila apos enfileirar 10 itens:\n");
    Imprime(fila);

    AumentaPrioridade(&fila, 5);
    printf("Fila apos aumentar a prioridade do item com chave 5:\n");
    Imprime(fila);

    for (i = 0; i < 10; i++) {
        Desenfileira(&fila, &item);
        printf("Item desenfileirado: %d\n", item.Chave);
        if(Vazia(fila)) {
            printf("Fila vazia\n");
        } else {
            printf("Fila apos desenfileirar um item:\n");
            Imprime(fila);
        }
    }

    return 0;
}







