/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 15/09/2023
 Objetivo: calcular fatorial com números grandes
 Entrada: inteiro n 0<= n >= 10^3
 Saida: números de zero do resultado.
 V2 do programa
*/

#include <stdio.h>

// Define o número máximo de elementos na linha
#define TAM_LIN 50000

// Função para multiplicar um número representado por uma array por um inteiro
void multiplicacao(unsigned long int res[], unsigned long int *resLin, unsigned long int multiplicador) {
    unsigned long int transporte = 0;

    for (unsigned long int i = 0; i < *resLin; i++) {
        unsigned long int temp = res[i] * multiplicador + transporte;
        res[i] = temp % 10;
        transporte = temp / 10;
    }

    while (transporte > 0) {
        res[*resLin] = transporte % 10;
        transporte /= 10;
        (*resLin)++;
    }
}

// Função para calcular o fatorial de um número grande e retornar o número de zeros
void fatorial(unsigned long int n) {
    unsigned long int res[TAM_LIN] = {0};
    res[0] = 1;
    unsigned long int resLin = 1;

    for (unsigned long int i = 2; i <= n; i++) {
        multiplicacao(res, &resLin, i);
    }

    unsigned long int zeros = 0;

    for (unsigned long int j = 0; j < resLin; j++) {
        if (res[j] == 0) {
            zeros++;
        } else {
            break;
        }
    }

    //imprime os numeros
    /*for (unsigned long int j = resLin-1; j >= 0; j--) {
        printf("%lu", res[j]);
    }*/

    printf("%lu\n", zeros);
}

int main() {
    unsigned long int num;
    scanf("%lu", &num);
    fatorial(num);
    return 0;
}
