/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 15/09/2023
 Objetivo: calcular fatorial com números grandes
 Entrada: inteiro n 0<= n >= 10^3
 Saida: números de zero do resultado.
*/
#include <stdio.h>

int zero(int num){
    int cont = 0;
    for (int i = 5; i <= num; i*=5)
    {
        cont += num/i;
    }
    return cont;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n", zero(num));
    return 0;
}