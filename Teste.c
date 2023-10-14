#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa a semente para a função rand() com o tempo atual
    srand(time(0));

    // Gera um número aleatório entre 0 e 100
    int numero = rand() % 101;

    printf("Número aleatório entre 0 e 100: %d\n", numero);

    return 0;
}
