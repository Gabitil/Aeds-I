/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 07/08/2023
*/

#include <stdio.h>

int mdc(int a, int b){
    int resto;

    resto = a % b;

    if (b == 0)
    {
        return a;
    }
    if (resto == 0)
    {
        return b;
    } else{
        return mdc(b, resto);
    }
}

int main(){
    int a, b;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d", mdc(a, b));
}