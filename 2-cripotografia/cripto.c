/*
    Programador: Gabriel Augusto de Lima Maia
    Data: 17/08/2023
    Objetivo: Descriptografar uma mensagem de um arquivo texto criptografada com o algoritmo de criptografia de César
*/

#include <stdio.h>
#include <string.h>

int main() {

    char arquivo[100], mensagem[1000], troca[2];
    int tamanho;
    arquivo[0] = '\0';
    mensagem[0] = '\0';
    troca[0] = '\0';
    FILE *fp;
    char c;

    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo);
    printf("\n");
    fp = fopen(arquivo,"r"); // Abre arquivo texto para leitura

    if(!fp) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    
    c = fgetc(fp);
    
    while(!feof(fp)){ // Enquanto não chegar ao final do arquivo
        tamanho = strlen(mensagem);
        mensagem[tamanho] = c;
        c = fgetc(fp); 
        mensagem[tamanho+1] = '\0';
    }
    tamanho = strlen(mensagem);

    fclose(fp);

    printf("--------------------\n");
    printf("Mensagem codificada:\n");
    printf("--------------------\n");
    printf("%s\n", mensagem);

    char blocos[tamanho/2][2];

    //transformando as mensagens em blocos

    for (size_t i = 0, j = 0; i < tamanho/2; i++) {
        blocos[i][0] = mensagem[j];
        blocos[i][1] = mensagem[j + 1];
        j += 2;
    }


    //tirando a permutação dos blocos
    for (size_t i = 0; i < tamanho/4; i++) {
        if (i%2 == 0)
        {
            troca[0] = blocos[i][0];
            troca[1] = blocos[i][1];
            blocos[i][0] = blocos[tamanho/2 - 1 - i][0];
            blocos[i][1] = blocos[tamanho/2 - 1 - i][1];
            blocos[tamanho/2 - 1 - i][0] = troca[0];
            blocos[tamanho/2 - 1 - i][1] = troca[1];
        }
    }

    //tirando a reflexão dos blocos
    for (size_t i = 0; i < tamanho/2; i++)
    {
        troca[0]=blocos[i][0];
        troca[1]=blocos[i][1];
        blocos[i][0]=troca[1];
        blocos[i][1]=troca[0];
    }

    //salvando os blocos na mensagem
    for (size_t i = 0, j = 0; i < tamanho/2; i++) {
        mensagem[j] = blocos[i][0];
        mensagem[j + 1] = blocos[i][1];
        j += 2;
    }

    //tirando a rotação de 5 letras pra esquerda
   for (int i = 0; i < tamanho; i++) {
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] = (mensagem[i] - 'A' - 5 + 26) % 26 + 'A';
        } else if (mensagem[i] >= 'a' && mensagem[i] <= 'z') {
            mensagem[i] = (mensagem[i] - 'a' - 5 + 26) % 26 + 'a';
        }
    }

    //troca de # por espaço
    for (size_t i = 0; mensagem[i] != '\0'; i++)
    {
        if (mensagem[i]=='#')
        {
            mensagem[i] = ' ';
        }
    }

    printf("----------------------\n");
    printf("Mensagem decodificada:\n");
    printf("----------------------\n");
    printf("%s", mensagem);
}

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//FGHIJKLMNOPQRSTUVWXYZABCDE