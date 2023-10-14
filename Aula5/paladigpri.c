/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 01/09/2023
 Objetivo: Encontrar palavas na diagonal principal de uma matriz
*/

#include <stdio.h>

int main(){
    int qntPalavras, qntLinhas, qntColunas;
    char palavra[qntPalavras+1][101];
    char matriz[1001][1001];
    palavra[0][0] = '\0';
    matriz[0][0] = '\0';

    scanf("%d %d %d", &qntPalavras, &qntLinhas, &qntColunas);
    for (size_t i = 0; i < qntPalavras; i++)
    {
      scanf("%s", palavra[i]);
      if (i == qntPalavras - 1)
      {
        palavra[i+1][0] = '\0';
      }
    }

    for (size_t i = 0; i < qntLinhas; i++) {
        scanf("%s", matriz[i]);
        if (i == qntLinhas - 1)
        {
            matriz[i+1][0] = '\0';
        }
    }
    /* //Conferindo as palavras
    printf("Palavras:\n");
    for (size_t i = 0; i < qntLinhas; i++) {
        printf("%s\n", matriz[i]); 
    }*/

}