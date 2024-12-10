#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define FINAL 1000

struct Carro{
    int id;
    int veloMax;
    int dist;
};

void inicializar(struct Carro carros[]){
    for (int i = 0; i < N; i++){
        carros[i].id = i + 1;
        carros[i].veloMax = (rand() % 101) + 100;
        carros[i].dist = 0;
    }
}

void exibirCarros(struct Carro carros[]){
    printf("ID\tVelocidade Máxima (km/h)\tDistância Percorrida (m)\n");
    for (int i = 0; i < N; i++){
        printf("%d\t%d\t\t\t\t%d\n", carros[i].id, carros[i].veloMax, carros[i].dist);
    }
}

void atualizarDistancia(struct Carro carros[], int *vencedor){
    printf("Iniciando rodada\n");
    for (int i = 0; i < N; i++){
        if (carros[i].dist < FINAL){
            int distancia = (rand() % 101) + 100;
            carros[i].dist += distancia;
            if (carros[i].dist > FINAL){
                carros[i].dist = FINAL;
            }
            printf("Carro %d avançou %d metros (Total: %d m)\n", carros[i].id, distancia, carros[i].dist);

            if (carros[i].dist >= FINAL && *vencedor == 0){
                *vencedor = carros[i].id;
                printf("\n--- O Carro %d é o primeiro a cruzar a linha de chegada! ---\n", carros[i].id);
            }
        }
    }
}

void ajustarVelocidade(struct Carro *carro){
    int novaVelocidade;
    printf("Digite a nova velocidade máxima para o Carro %d: ", carro->id);
    scanf("%d", &novaVelocidade);

    carro -> veloMax = novaVelocidade;
    printf("Velocidade do Carro %d ajustada para %d km/h\n", carro->id, carro->veloMax);
}

int todosTerminaram(struct Carro carros[]){
    for (int i = 0; i < N; i++){
        if (carros[i].dist < FINAL){
            return 0;
        } 
    }
    return 1;
}

int main() {
    struct Carro carros[N];
    int opcao;
    int vencedor = 0;
    int idCarro;

    srand(time(NULL));

    inicializar(carros);

    do{
        printf("\n----- Menu -----\n");
        printf("1 - Iniciar rodada\n");
        printf("2 - Ajustar velocidade de um carro\n");
        printf("3 - Exibir status dos carros\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            atualizarDistancia(carros, &vencedor);
            if (todosTerminaram(carros)){
                printf("\nTodos os carros cruzaram a linha de chegada!\n");
                exibirCarros(carros);
                opcao = 4;
            }
            break;
        case 2:
            printf("Digite o ID do carro (1 a %d): ", N);
            scanf("%d", &idCarro);
            if (idCarro >= 1 && idCarro <= N) {
                ajustarVelocidade(&carros[idCarro - 1]);
            } else {
                printf("ID inválido!\n");
            }
            break;
        case 3:
            exibirCarros(carros);
            break;
        case 4:
            printf("Programa finalizado!\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 4);

}
