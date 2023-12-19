/*
    Nome: Gabriel Augusto de Lima Maia
    Data: 19/10/2023
    Objetivo: Resolver o probelma da mochila, em que é dado um número de pedidos e o tempo e o número de pizzas de cada pedido,
    e é dado o número maximo de pizzas a serem levadas, e é preciso calcular o tempo máximo que se pode levar pizzas.
    
    Descrição do algoritmo:
    - O algoritmo utiliza a técnica de programação dinâmica para resolver o problema da mochila.
    - A ideia é criar uma matriz de tamanho (numPedidos+1) x (maxPizzas+1), onde cada posição (i,j) representa o tempo máximo que se pode levar pizzas
      considerando os i primeiros pedidos e uma mochila com capacidade j.
    - Para preencher a matriz, é utilizado um loop duplo que percorre cada posição da matriz e verifica se é possível adicionar o i-ésimo pedido na mochila.
      Caso seja possível, é verificado se o tempo total para entregar os pedidos anteriores mais o tempo do i-ésimo pedido é maior do que o tempo total
      para entregar os pedidos anteriores sem o i-ésimo pedido. Se for, o tempo total é atualizado.
    - Ao final, o tempo máximo que se pode levar pizzas é o valor da posição (numPedidos, maxPizzas).
*/
#include <stdio.h>

int main() {
    int numPedidos, maxPizzas, i, j;
    int tempo[21], pizzas[31], tempoMax[31]; //

    while (scanf("%d", &numPedidos) && numPedidos) {
        scanf("%d", &maxPizzas);

        // Lê os tempos e o número de pizzas de cada pedido
        for (i = 1; i <= numPedidos; i++) {
            scanf("%d %d", &tempo[i], &pizzas[i]);
        }

        // Inicializa a matriz tempoMax com zeros
        for (i = 0; i <= maxPizzas; i++) {
            tempoMax[i] = 0;
        }

        // Preenche a matriz tempoMax utilizando programação dinâmica
        for (i = 1; i <= numPedidos; i++) {
            for (j = maxPizzas; j >= pizzas[i]; j--) {
                if (tempoMax[j-pizzas[i]] + tempo[i] > tempoMax[j]) {
                    tempoMax[j] = tempoMax[j-pizzas[i]] + tempo[i];
                }
            }
        }

        // Imprime o tempo máximo que se pode levar pizzas
        printf("%d min.\n", tempoMax[maxPizzas]);
    }

    return 0;
}
