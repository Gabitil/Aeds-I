/****

LAED1 - Projeto (Parte III) - Detecção de impedimentos na pista

Alunos(as): Gabriel Augusto, Gabriel Araujo

Data: 01/12/2023

****/
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */
void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));//aloca memoria para o primeiro elemento
  Lista -> Ultimo = Lista -> Primeiro;//o ultimo elemento recebe o primeiro
  Lista -> Primeiro -> Prox = NULL;//o proximo elemento do primeiro elemento recebe null
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));//
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL) 
  { printf(" Erro Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}

/* ========================================================================= */
static const int padrao[] = {0, 255, 128, 255, 0};
static const int tamanhoPadrao = sizeof(padrao) / sizeof(padrao[0]);


/**
 * Reduz a lista removendo elementos repetidos.
 * 
 * @param Lista A lista original.
 * @param ListaReduzida Ponteiro para a lista reduzida.
 * @param qtdLista A quantidade de elementos na lista original.
 */
void ReduzLista(TipoLista Lista, TipoLista *ListaReduzida, int qtdLista) {
    TipoItem itemReduzido; // Item que será inserido na lista reduzida

    TipoApontador Aux; // Apontador auxiliar para percorrer a lista
    Aux = Lista.Primeiro->Prox; // Começamos a percorrer a lista a partir do primeiro elemento
    itemReduzido.Chave = Aux->Item.Chave; // O primeiro elemento da lista será o primeiro elemento da lista reduzida
    Insere(itemReduzido, ListaReduzida); // Inserimos o primeiro elemento na lista reduzida

    int elementoAtual = itemReduzido.Chave; // Variável que armazena o elemento atual da lista
    int elementoAnterior = Aux->Item.Chave; // Variável que armazena o elemento anterior da lista

    for (int i = 1; i < qtdLista; i++) { // Percorremos a lista a partir do segundo elemento
        Aux = Aux->Prox; // Avançamos para o próximo elemento da lista
        elementoAtual = Aux->Item.Chave; // Atualizamos o elemento atual
        if (elementoAtual != elementoAnterior) { // Se o elemento atual for diferente do elemento anterior, inserimos na lista reduzida
            itemReduzido.Chave = elementoAtual; // Atualizamos o item que será inserido na lista reduzida
            Insere(itemReduzido, ListaReduzida); // Inserimos o item na lista reduzida
        }
        elementoAnterior = elementoAtual; // Atualizamos o elemento anterior
    }
}



/**
 * Função responsável por ler os elementos de uma lista e criar uma lista reduzida.
 * 
 * @param Lista A lista original.
 * @param ListaReduzida A lista reduzida que será criada.
 */
void LeElementos(TipoLista *Lista, TipoLista *ListaReduzida) {
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

    ReduzLista(*Lista, ListaReduzida, N);
}

/**
 * Libera a memória alocada por uma lista encadeada.
 * 
 * @param Lista Ponteiro para a lista encadeada a ser liberada.
 */
void LiberaLista(TipoLista *Lista) {
    TipoApontador Aux = Lista->Primeiro->Prox;
    TipoApontador Temp;
    while (Aux != NULL) {
        Temp = Aux;
        Aux = Aux->Prox;
        free(Temp);
    }
    Lista->Primeiro->Prox = NULL;
    Lista->Ultimo = Lista->Primeiro;
}

/**
 * Calcula o ponto médio entre a primeira ocorrência de uma cor vermelha que é precedida por uma cor branca
 * e a primeira ocorrência de uma cor branca que é precedida por uma cor vermelha em uma lista encadeada.
 * 
 * @param Lista A lista encadeada a ser percorrida.
 * @return O ponto médio entre as duas ocorrências de cores, ou -1 caso não seja encontrada a sequência desejada.
 */
double pontoMedio(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;//começa a percorrer a lista a partir do primeiro elemento
    int contador = 0;
    int inicio = -1, fim = -1;
    int corPreta = 0; // Valor que representa a cor preta
    int corVermelha = 128; // Valor que representa a cor vermelha
    int corBranca = 255; // Valor que representa a cor branca

    /*Percorre a lista até encontrar um vermelho que veio antes de um branco*/
    while (Aux != NULL) {
        if (Aux->Item.Chave == corBranca && Aux->Prox->Item.Chave == corVermelha) {
            // Início da parte vermelha
            inicio = contador + 1;
        } else if (Aux->Item.Chave == corVermelha && Aux->Prox->Item.Chave == corBranca && inicio != -1) {
            // Fim da parte vermelha
            fim = contador;
            break;
        } else if (Aux->Item.Chave == corPreta && inicio != -1) {
            // Reiniciar caso encontre algo que não pertença à parte vermelha
            inicio = -1;
            fim = -1;
        }
        contador++;
        Aux = Aux->Prox;
    }

    if (inicio != -1 && fim != -1) {
        // A parte vermelha entre preto e branco foi encontrada, calculamos o ponto médio
        return (double)(inicio + fim) / 2;
    } else {
        // A parte vermelha não foi encontrada
        return -1;
    }
}







/**
 * Verifica se uma sequência de elementos está presente em uma lista encadeada.
 * 
 * @param Lista A lista encadeada a ser verificada.
 * @return Retorna 1 se a sequência foi encontrada, 2 se houve um bloqueio no meio do padrão, ou 0 caso contrário.
 */
int VerificaSequencia(TipoLista Lista) {
    int k = 0;  // Índice atual do padrão
    int achou = 0;  // Flag para indicar se o padrão foi encontrado
    int padraoComecou = 0; // Flag para indicar se o padrão começou a ser correspondido

    TipoApontador Aux = Lista.Primeiro->Prox;

   

    while (Aux != NULL) {
        if(Aux->Item.Chave == padrao[k]) {// Se o elemento atual for igual ao elemento do padrão
            padraoComecou = 1; // Marque que o padrão começou a ser correspondido
            k++;
            if (k == tamanhoPadrao) {
                achou = 1;
            }
        } else {
            // se o padrão começou e estamos no meio do padrão, então tem um bloqueio
            if (padraoComecou == 1 && k > 3 && k < tamanhoPadrao) {
                return 2;
            }
            k = 0;
            padraoComecou = 0; // Reinicie a busca pelo padrao
        }

        Aux = Aux->Prox;
    }


    return achou;
}

/**
 * Função que retorna o tamanho da lista encadeada.
 * 
 * @param Lista A lista encadeada.
 * @return O tamanho da lista.
 */
int TamanhoLista(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    int tamanho = 0;

    while (Aux != NULL) {
        tamanho++;
        Aux = Aux->Prox;
    }

    return tamanho;
}





/**
 * Verifica a direção com base nos pontos médios fornecidos.
 * 
 * @param pontoMedio1 O primeiro ponto médio.
 * @param pontoMedio2 O segundo ponto médio.
 */
void VerificaDirecao(double pontoMedio1, double pontoMedio2) {
    double tolerancia = 30; // Ajuste conforme necessário
    double inclinacao = pontoMedio1 - pontoMedio2;

    if (fabs(inclinacao) < tolerancia) {
        printf("Resultado: Pista em linha reta.\n");
    } else if (inclinacao < -tolerancia) {
        printf("Resultado: Curva a esquerda.\n");
    } else if (inclinacao > tolerancia){
        printf("Resultado: Curva a direita.\n");
    }
}



/**
 * Calcula a taxa de erro com base no número de falhas e acertos.
 * 
 * @param falhas O número de falhas.
 * @param acertos O número de acertos.
 * @return A taxa de erro em porcentagem.
 */
double VerificaTaxadeErro(int falhas, int acertos) {
    double taxaErro = ((double)falhas / (falhas + acertos)) * 100;
    return taxaErro;
}

/**
 * Função principal do programa.
 * Realiza a leitura de uma quantidade de linhas e, para cada linha,
 * lê os elementos de uma lista e verifica se uma sequência específica
 * foi encontrada. Contabiliza os acertos, falhas e bloqueios encontrados.
 * Ao final, exibe o resultado com base na taxa de erro.
 * 
 * @return 0 se o programa for executado com sucesso.
 */
int main() {
    TipoLista lista;
    FLVazia(&lista);
    TipoLista ListaReduzida;
    FLVazia(&ListaReduzida);
    double pontoMedio1, pontoMedio2;

    int Linhas, falhas = 0, acertos = 0, achou = 0, bloqueios = 0;
    scanf("%d", &Linhas);

       while (Linhas > 0) {
        LeElementos(&lista, &ListaReduzida);

        // Verifica se a sequência específica foi encontrada
        if (VerificaSequencia(ListaReduzida) == 1) {
            achou = 1;
            acertos++;
        } else if (VerificaSequencia(ListaReduzida) == 2) {
            printf("Resultado: Pista com impedimento.\n");
            LiberaLista(&lista);
            LiberaLista(&ListaReduzida);
            return 0;
        }else {
            falhas++;
        }

        // Limpa as listas para a próxima iteração
        LiberaLista(&lista);
        LiberaLista(&ListaReduzida);
        Linhas--;
        }

    if(VerificaTaxadeErro(falhas, acertos) > 30.0){
        printf("Resultado: Formato da pista nao estimado.\n");
    } else {
        printf("Resultado: Pista sem impedimento.\n");
    }

    // Limpa as listas antes de encerrar o programa
    LiberaLista(&lista);
    LiberaLista(&ListaReduzida);

    return 0;
}
