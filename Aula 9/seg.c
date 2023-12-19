#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particao(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int removeDuplicados(int arr[], int n) {
    if (n==0 || n==1)
        return n;

    int temp[n];

    int j = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
    temp[j++] = arr[n-1];

    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

// compara dois vetores de tamanhos diferentes e subistitui os valores do vetor1 pelos valores
// do indice do vetor2 +1
void comparaVetores(int* vetor1, int* vetor2, int n1, int n2) {
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (vetor1[i] == vetor2[j]) {
                vetor1[i] = j + 1;
            }
        }
    }
}

int main() {
    int N, i, j, k = 0, count = 1;

    scanf("%d", &N);

    int *vetor = (int *)malloc(N * sizeof(int));
    int **matriz;

    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    // Tentativa de alocação de memória para a matriz
    while ((matriz = (int **)malloc(2 * sizeof(int *))) == NULL) {}

    for (i = 0; i < 2; i++) {
        // Tentativa de alocação de memória para cada linha da matriz
        while ((matriz[i] = (int *)malloc(N * sizeof(int))) == NULL) {}
    }

    for (i = 0; i < N; i++) {
        if (i == 0) {
            matriz[0][k] = vetor[i];
        } else if (vetor[i] == vetor[i - 1]) {
            count++;
        } else {
            matriz[1][k] = count;
            k++;
            matriz[0][k] = vetor[i];
            count = 1;
        }
    }

    matriz[1][k] = count; // Armazenar a contagem do último segmento

    int numSegmentos = k + 1;
    // Ordenar o vetor de segmentos
    int *aux = (int *)malloc(numSegmentos * sizeof(int));
    for (i = 0; i < numSegmentos; i++) {
        aux[i] = matriz[0][i];
    }

    quickSort(aux, 0, numSegmentos - 1);
    removeDuplicados(aux, numSegmentos);

    // Substituir os valores da matriz pelos índices do vetor auxiliar
    comparaVetores(matriz[0], aux, numSegmentos, numSegmentos);

    

    for (i = 0; i < 2; i++) {
        for (j = 0; j <= k; j++) {
            printf("%d", matriz[i][j]);
            if (j < k) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);

    return 0;
}
