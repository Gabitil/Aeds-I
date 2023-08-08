#include <stdio.h>

int mult(int base, int exp){
    if(exp == 0){
        return 1;
    } else{
        return base * mult(base, exp - 1);
    }
}

int main(){
    int base, exp;

    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &base, &exp);
    printf("Resultado: %d", mult(base, exp));
}