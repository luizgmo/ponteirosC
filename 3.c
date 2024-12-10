#include <stdio.h>

#define N 10

void calcularMmm(float temperaturas[], float *media, float *min, float *max){
    float soma = 0;
    *min = temperaturas[0];
    *max = temperaturas[0];

    for (int i = 0; i < N; i++){
        soma += temperaturas[i];
        if (temperaturas[i] < *min){
            *min = temperaturas[i];
        }
        if (temperaturas[i] > *max){
            *max = temperaturas[i];
        }
    }

    *media = soma / N;
}

int identificarSequencia(float temperaturas[]){
    int maxSeq = 0, seqAtual = 0;

    for (int i = 0; i < N; i++) {
        if (temperaturas[i] < 15.0) {
            seqAtual++;
        } else {
            if (seqAtual > maxSeq) {
                maxSeq = seqAtual;
            }
            seqAtual = 0;
        }
    }

    if (seqAtual > maxSeq) {
        maxSeq = seqAtual;
    }

    return maxSeq;
}

int acimaMedia(float temperaturas[], float *media){
    int diasAcima = 0;
    
    for (int i = 0; i < N; i++){
        if (temperaturas[i] > *media){
            diasAcima++;
        }
    }

    return diasAcima;
}

void alterarTemperatura(float temperaturas[], int dia, float novaTemp){
    if (dia >= 1 && dia <= N){
        temperaturas[dia - 1] = novaTemp;
        printf("Temperatura do dia %d alterada para %.2f°C\n", dia, novaTemp);
    } else{
        printf("Dia inválido! Por favor, insira um dia entre 1 e %d.\n", N);
    }
}

int main(){
    float temperaturas[N];
    float media, min, max;
    int opcao, dia;
    float novaTemp;

    printf("Digite as temperaturas do dias:\n");
    for (int i = 0; i < N; i++){
        printf("Dia %d: ", i + 1);
        scanf("%f", &temperaturas[i]);
    }

    calcularMmm(temperaturas, &media, &min, &max);

    do {
        printf("\n----- Menu -----\n");
        printf("1 - Calcular média, mínima e máxima\n");
        printf("2 - Identificar maior sequência de dias abaixo de 15°C\n");
        printf("3 - Estimar número de dias acima da média\n");
        printf("4 - Alterar temperatura de um dia\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Média: %.2f°C, Mínima: %.2f°C, Máxima: %.2f°C\n", media, min, max);
                break;
            case 2:
                printf("Maior sequência de dias abaixo de 15°C: %d dias\n", identificarSequencia(temperaturas));
                break;
            case 3:
                printf("Quantidade de dias acima da média: %d\n", acimaMedia(temperaturas, &media));
                break;
            case 4:
                printf("Digite o dia que deseja alterar (1-%d): ", N);
                scanf("%d", &dia);
                printf("Digite a nova temperatura: ");
                scanf("%f", &novaTemp);
                alterarTemperatura(temperaturas, dia, novaTemp);
                calcularMmm(temperaturas, &media, &min, &max);
                break;
            case 5:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);
}