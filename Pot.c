/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 07/08/2023
*/

#include <stdio.h>

long double mult(long double base,long double exp){
    if(exp == 0){
        return 1;
    } else{
        return base * mult(base, exp - 1);
    }
}

int main(){
    long double base, exp;

    printf("Digite a base e o expoente inteiros: ");
    scanf("%Lf %Lf", &base, &exp);
    printf("Resultado: %.Lf", mult(base, exp));
}