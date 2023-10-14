/*
 Autor: Gabriel Augusto de Lima Maia
 Data: 01/09/2023
 Objetivo: Converter um numero decimal para hexadecimal
*/

#include <stdio.h>

void dec2hex(int dec){
    int resto;

    if (dec >= 16)
    {
        resto = dec % 16;
        dec = dec / 16;
        dec2hex(dec);
        if (resto >= 10)
        {
            printf("%c", resto + 55);
        } else
        {
            printf("%d", resto);
        }

    } else if (dec >= 10)
    {
        printf("%c", dec + 55);
    } else if (dec >= 0 && dec < 10)
    {
        printf("%d", dec);
    }
}


int main(){
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("Resultado: ");
    dec2hex(num);
}