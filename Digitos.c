#include <stdio.h>

int Digitos(int N){
  int cont = 1;

  while(N >= 10){
    N = N /10;
    cont = cont + 1;
  }

  return cont;
}

int main(){
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("Resultado: %d", Digitos(num));
}