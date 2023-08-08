#include <stdio.h>

void dec2bin(int dec){
    int resto;

    if (dec >= 2)
    {
        resto = dec % 2;
        dec = dec / 2;
        dec2bin(dec);
        printf("%d", resto);
    }
    else if (dec == 1)
    {
        printf("1");
    }
    else if (dec == 0)
    {
        printf("0");
    }
}

int main(){
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("Resultado: ");
    dec2bin(num);
}
