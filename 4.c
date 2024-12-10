#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define NAVIOS 3

void inicializarTabuleiro(int tabuleiro[]){
    for (int i = 0; i < N; i++) {
        tabuleiro[i] = 0;
    }
}

void posicionarNavios(int tabuleiro[]){
    int naviosColocados = 0;
    srand(time(NULL));

    while(naviosColocados < NAVIOS){
        int posicao = rand() % N;
        if (tabuleiro[posicao] == 0) {
            tabuleiro[posicao] = 1;
            naviosColocados++;
        }
    }
}

void exibirTabuleiro(int tabuleiro[]) {
    printf("Tabuleiro: ");
    for (int i = 0; i < N; i++) {
        if (tabuleiro[i] == -1) {
            printf(" X ");
        } else {
            printf(" ~ ");
        }
    }
    printf("\n");
}

void realizarDisparo(int tabuleiro[]) {
    int posicao;
    printf("Digite a posição (0 a 9) para atirar: ");
    scanf("%d", &posicao);

    if (posicao < 0 || posicao >= N) {
        printf("Posição inválida! Tente novamente.\n");
        return;
    }

    if (tabuleiro[posicao] == -1) {
        printf("Você já atirou nesta posição! Tente novamente.\n");
    } else if (tabuleiro[posicao] == 1) {
        tabuleiro[posicao] = -1;
        printf("Acertou um navio!\n");
    } else {
        tabuleiro[posicao] = -1;
        printf("Água!\n");
    }
}

int verificarVitoria(int tabuleiro[]) {
    for (int i = 0; i < N; i++) {
        if (tabuleiro[i] == 1) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int tabuleiro[N];
    int vitoria = 0;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

     while (!vitoria) {
        exibirTabuleiro(tabuleiro);
        realizarDisparo(tabuleiro);
        vitoria = verificarVitoria(tabuleiro);
    }

    printf("Parabéns! Você destruiu todos os navios!\n");
}