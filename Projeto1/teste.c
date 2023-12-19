#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

typedef int TipoChave;
typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista) {
  Lista -> Primeiro = INICIOARRANJO;
  Lista -> Ultimo = Lista -> Primeiro;
}

int Vazia(TipoLista Lista) {
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
  if (Lista -> Ultimo > MAXTAM) printf("Lista esta cheia\n");
  else { 
    Lista -> Item[Lista -> Ultimo - 1] = x;
    Lista -> Ultimo++;
  }
}

void LeElementos(TipoLista *Lista) {
  int N, i, valor;
  TipoItem item;

  if (scanf("%d", &N) != 1) {
    printf("Erro ao ler o tamanho da lista.\n");
    return;
  }

  for (i = 0; i < N; i++) {
    if (scanf("%d", &valor) != 1) {
      printf("Erro ao ler o elemento da lista.\n");
      return;
    }
    item.Chave = valor;
    Insere(item, Lista);
  }
}
int VerificaSequencia(TipoLista Lista) {
  int padrao[] = {0, 255,128, 255, 0};
  int tamanhoPadrao = sizeof(padrao)/sizeof(padrao[0]);
  int i, j, k;

  // Vamos começar a busca do início da lista
  for (i = Lista.Primeiro - 1; i <= Lista.Ultimo - tamanhoPadrao; i++) {
    // A variável k acompanhará o índice atual do padrão que estamos verificando
    k = 0;
    // Vamos percorrer a lista a partir do ponto i
    for (j = i; j < Lista.Ultimo && k < tamanhoPadrao; j++) {
      // Se o elemento atual da lista corresponder ao elemento atual do padrão,
      // passamos para o próximo elemento do padrão
      if (Lista.Item[j].Chave == padrao[k]) {
        k++;
        // Continuamos avançando até encontrar um número diferente na lista
        while (j + 1 < Lista.Ultimo && Lista.Item[j + 1].Chave == padrao[k - 1]) {
          j++;
        }
      } else if (k > 0) {
        // Se encontrarmos um número diferente no meio do padrão, interrompemos a busca
        break;
      }
      // Se todos os elementos do padrão foram encontrados em sequência, retornamos sucesso
      if (k == tamanhoPadrao) return 1;
    }
  }
  // Se chegamos ao final da lista sem encontrar o padrão completo, retornamos fracasso
  return 0;
}   

int main() {
  TipoLista lista;
  FLVazia(&lista);
  LeElementos(&lista);
     if (VerificaSequencia(lista)) {
    printf("Resultado: Padrao encontrado.\n");
  } else {
    printf("Resultado: Padrao nao encontrado.\n");
  }

  
  return 0;
}