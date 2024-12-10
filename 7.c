#include <stdio.h>
#include <string.h>

#define N 20

struct Animal {
    int id;
    char especie[30];
    float peso;
    int status;
};

void registrarAnimal(struct Animal zoologico[], int *pos) {
    if (*pos >= N) {
        printf("Número máximo de animais atingido!\n");
        return;
    }

    zoologico[*pos].id = *pos + 1;

    printf("Espécie: ");
    scanf("%s", zoologico[*pos].especie);

    printf("Peso: ");
    scanf("%f", &zoologico[*pos].peso);

    do {
        printf("Status\n1 - Saudável\n2 - Em tratamento\nEscolha: ");
        scanf("%d", &zoologico[*pos].status);

        if (zoologico[*pos].status != 1 && zoologico[*pos].status != 2) {
            printf("Entrada inválida! Digite 1 para Saudável ou 2 para Em tratamento.\n");
        }

    } while (zoologico[*pos].status != 1 && zoologico[*pos].status != 2);

    printf("Animal registrado com sucesso!\n");
    (*pos)++;
}

void atualizarStatus(struct Animal zoologico[], int *pos, int id){
    int encontrado = 0;

    for (int i = 0; i < *pos; i++) {
        if (zoologico[i].id == id) {
            if (zoologico[i].status == 1) {
                zoologico[i].status = 2;
                printf("Status do animal com ID %d alterado para 'Em tratamento'.\n", id);
            } else {
                zoologico[i].status = 1;
                printf("Status do animal com ID %d alterado para 'Saudável'.\n", id);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum animal com ID %d foi encontrado!\n", id);
    }
}

void calcularPeso(struct Animal zoologico[], int *pos, char especie[]){
    float soma = 0;
    int contador = 0;

    for (int i = 0; i < *pos; i++){
        if (strcasecmp(zoologico[i].especie, especie) == 0){
            soma += zoologico[i].peso;
            contador++;
        }
    }

    if (contador > 0){
        printf("A media de peso dos animais da especie %s é %.2f kg\n", especie, soma / contador);
    } else{
        printf("Nenhum animal da especie %s encontrado!", especie);
    }
}

void animaisTratamento(struct Animal zoologico[], int *pos){
    for (int i = 0; i < *pos; i++){
        if (zoologico[i].status == 2){
            printf("\nID do animal em tratamento: %d\n", zoologico[i].id);
            printf("Especie do animal em tratamento: %s\n", zoologico[i].especie);
            printf("Peso do animal em tratamento: %.2f kg\n", zoologico[i].peso);
        }
    }
}

void transferirAnimal(struct Animal zoologico[], int *pos, int id){
    int encontrado = 0;

    for (int i = 0; i < *pos; i++){
        if (zoologico[i].id == id){
            encontrado = 1;

            for (int j = i; j < *pos; j++){
                zoologico[j] = zoologico[j + 1];
            }

            (*pos)--;

            printf("Animal transferido com sucesso!\n");
            break;
        }
    }

    if (!encontrado){
        printf("Animal nao encontrado!\n");
    }
}

int main() {
    struct Animal zoologico[N];
    int opcao, pos = 0, id;
    char especie[30];

    do {
        printf("\n----- Menu -----\n");
        printf("1 - Registrar animal\n");
        printf("2 - Atualizar status\n");
        printf("3 - Calcular média de peso por espécie\n");
        printf("4 - Animais em tratamento\n");
        printf("5 - Transferir animal\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarAnimal(zoologico, &pos);
                break;
            case 2:
                printf("Digite o ID do animal que deseja alterar o status: ");
                scanf("%d", &id);
                atualizarStatus(zoologico, &pos, id);
                break;
            case 3:
                printf("Digite a espécie que deseja calcular a média de peso: ");
                scanf("%s", especie);
                calcularPeso(zoologico, &pos, especie);
                break;
            case 4:
                animaisTratamento(zoologico, &pos);
                break;
            case 5:
                printf("Digite o ID do animal que deseja transferir: ");
                scanf("%d", &id);
                transferirAnimal(zoologico, &pos, id);
                break;
            case 6:
                printf("Programa finalizado!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

}
