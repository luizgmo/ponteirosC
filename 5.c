#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Formiga{
    char nome[20];
    int energia;
    int status;

};

void movimentar(struct Formiga colonia[], int qntd){
    for (int i = 0; i < qntd; i++){
        if (colonia[i].status == 0){
            colonia[i].energia -= 5;
            if (colonia[i].energia < 0){
                colonia[i].energia = 0;
                colonia[i].status = -1;
            }
        }
    }
    printf("Todas as formigas foram movimentadas!\n");
}

void simularColeta(struct Formiga colonia[], int indice){
    if (colonia[indice].status == 0){
        int energiaGanha = (rand() % 21) + 10;
        colonia[indice].energia += energiaGanha;
        if (colonia[indice].energia > 100){
            colonia[indice].energia = 100;
        }
        colonia[indice].status = 1;
        printf("%s coletou alimento e ganhou %d de energia!\n", colonia[indice].nome, energiaGanha);
    } else{
        printf("A %s não está procurando alimento.\n", colonia[indice].nome);
    }
}

void gerenciarEnergia(struct Formiga colonia[], int indice){
    if (colonia[indice].status == -1){
        colonia[indice].energia = 50;
        colonia[indice].status = 0;
        printf("%s foi resgatada e restaurada com 50 de energia.\n", colonia[indice].nome);
    } else{
        printf("A %s não precisa ser resgatada.\n", colonia[indice].nome);
    }
}

void exibirColonia(struct Formiga colonia[], int qntd){
    printf("\n--- Estado da colonia ---\n");
    for (int i = 0; i < qntd; i++){
        printf("%s \t Energia: %d \t Status: %s\n", colonia[i].nome, colonia[i].energia,(colonia[i].status == 0 ? "Procurando alimento" : (colonia[i].status == 1 ? "Voltando ao formigueiro" : "Parada")));
    }
}

int main(){

    struct Formiga colonia[20];
    int opcao, qntd = 0, indice;

    colonia[0] = (struct Formiga){"Formiga0", 100, 0};
    colonia[1] = (struct Formiga){"Formiga1", 90, 0};
    colonia[2] = (struct Formiga){"Formiga2", 80, 0};
    colonia[3] = (struct Formiga){"Formiga3", 70, 0};
    colonia[4] = (struct Formiga){"Formiga4", 60, 0};
    qntd = 5;

    srand(time(NULL));

    do
    {
        printf("----- Menu -----\n");
        printf("1 - Movimentar\n");
        printf("2 - Simular coleta de alimento\n");
        printf("3 - Gerenciar energia\n");
        printf("4 - Exibir colonia\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            movimentar(colonia, qntd);
            break;
        case 2:
            printf("Escolha o índice da formiga (0 a %d): ", qntd - 1);
            scanf("%d", &indice);
            if (indice >= 0 && indice < qntd)
                simularColeta(colonia, indice);
            else
                printf("Índice inválido!\n");
            break;
        case 3:
            printf("Escolha o índice da formiga (0 a %d): ", qntd - 1);
            scanf("%d", &indice);
            if (indice >= 0 && indice < qntd)
                gerenciarEnergia(colonia, indice);
            else
                printf("Índice inválido!\n");
            break;
        case 4:
            exibirColonia(colonia, qntd);
            break;
        case 5:
            printf("Programa finalizado!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);
}