#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox, Ant;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista)
{ 
  Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  Lista -> Primeiro -> Ant = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ 
  Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo -> Prox -> Ant = Lista -> Ultimo;
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ 
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL) 
  { 
    printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) 
    Lista -> Ultimo = p;
  else
    p -> Prox -> Ant = p;
  free(q);
}


void InsereLista(TipoLista *Lista1, TipoLista *Lista2) {
    if (Vazia(*Lista2)) {
        printf("Erro: a lista 2 está vazia.\n");
        return;
    }

    TipoApontador p = Lista2->Primeiro->Prox;
    while (p != NULL) {
        Insere(p->Item, Lista1);
        p = p->Prox;
    }
  free(p);
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}

/* ========================================================================== */

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Particao(TipoApontador Esq, TipoApontador Dir, TipoApontador *i, TipoApontador *j, TipoLista *Lista)
{
  TipoItem x, w;
  *i = Esq; *j = Dir;
  x = (*i)->Item; /* obtem o pivo x */
  do
  { while (x.Chave > (*i)->Item.Chave) *i = (*i)->Prox;
    while (x.Chave < (*j)->Item.Chave) *j = (*j)->Ant;
    if (*i <= *j)
    { w = (*i)->Item; (*i)->Item = (*j)->Item; (*j)->Item = w; /* troca */
      (*i) = (*i)->Prox; (*j) = (*j)->Ant;
    }
  } while (*i <= *j);
}

void Ordena(TipoApontador Esq, TipoApontador Dir, TipoLista *Lista)
{
  TipoApontador i,j;
  Particao(Esq, Dir, &i, &j, Lista);
  if (Esq < j) Ordena(Esq, j, Lista);
  if (i < Dir) Ordena(i, Dir, Lista);
}

void QuickSort(TipoLista *Lista)
{
  Ordena(Lista->Primeiro->Prox, Lista->Ultimo, Lista);
}



int removeDuplicados(int arr[], int n) {
    if (n==0 || n==1)
        return n;

    int temp[n];

    int j = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
    temp[j++] = arr[n-1];

    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

void comparaVetores(int* vetor1, int* vetor2, int n1, int n2) {
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (vetor1[i] == vetor2[j]) {
                vetor1[i] = j + 1;
            }
        }
    }
}
/*
void segmentaLista(TipoLista* Lista, int* segmentos, int* numSegmentos) {
    int i, k = 0;
    TipoApontador p = Lista->Primeiro->Prox;

    for (i = 0; i < Lista->Ultimo->Item.Chave; i++) {
        if (i == 0) {
            segmentos[k] = p->Item.Chave;
        } else if (p->Item.Chave != p->Prox->Item.Chave) {
            k++;
            segmentos[k] = p->Prox->Item.Chave;
        }
        p = p->Prox;
    }

    *numSegmentos = k + 1;
    int *aux = (int *)malloc(*numSegmentos * sizeof(int));
    for (i = 0; i < *numSegmentos; i++) {
        aux[i] = segmentos[i];
    }

    quickSort(aux, 0, *numSegmentos - 1);
    removeDuplicados(aux, *numSegmentos);

    comparaVetores(segmentos, aux, *numSegmentos, *numSegmentos);

    free(aux);
} */

int main() {
    TipoLista Lista;
    TipoLista Listaaux;
    FLVazia(&Lista);
    FLVazia(&Listaaux);

    printf("Digite os elementos da lista:\n");

    int N, i, valor;
    TipoItem item;

    if (scanf("%d", &N) != 1) {
      printf("Erro ao ler o tamanho da lista.\n");
    }

    for (i = 0; i < N; i++) {
      if (scanf("%d", &valor) != 1) {
        printf("Erro ao ler o elemento da lista.\n");
      }
      item.Chave = valor;
      Insere(item, &Lista);
    }

    InsereLista(&Listaaux, &Lista);
    QuickSort(&Listaaux);
    Imprime(Listaaux);


}
