/*
    Programador: Gabriel Augusto de Lima Maia
    Data: 18/08/2023
    Objetivo: Escolher uma caixa em que a soma das filas acima dela seja a maior possivel
*/


#include <stdio.h>
#include <string.h>

int main(){
    char arquivo[100];

    FILE *fp;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", arquivo);
    fp = fopen(arquivo,"r"); // Abre arquivo texto para leitura
    
    if(!fp) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }

    int niveis;
    fscanf(fp, "%d", &niveis); // Lê o número de níveis da fileira

    int caixas[niveis][niveis];

    for (int i = 0; i < niveis; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(fp, "%d", &caixas[i][j]); 
        }
    }

    /* Imprime as fileiras
    for (int i = 0; i < niveis; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", caixas[i][j]);
        }
        printf("\n");
    }
    */

    fclose(fp);

    int soma = 0;
    int maiorSoma = 0;
    int maiorCaixa = 0;
    int filaMaiorCaixa = 0;

    for (int i = niveis - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
        soma = caixas[i][j]; // Começa com o valor da caixa atual

            for (int k = i-1; k >= 0; k--)
            {
                for (int l = k; l >= 0; l--)
                {
                    soma += caixas[k][l];
                }
            }
        

        if (soma > maiorSoma) {
            maiorSoma = soma;
            maiorCaixa = j;
            filaMaiorCaixa = i;
        }
    }
}


    printf("Resposta: fileira %d, caixa %d.", filaMaiorCaixa + 1, maiorCaixa + 1);
    return 0;
}
