#include <stdio.h>
#include <string.h>

#define N 100

struct Catalogo
{
    char nome[50];
    int tipo;
    int status;
};

void adicionarCatalogo(struct Catalogo cat[], int *pos)
{
    char nome[50];

    if (*pos >= N)
    {
        printf("Número máximo de séries e filmes atingido!\n");
        return;
    }

    printf("Digite o nome da série ou filme que deseja adicionar: ");
    scanf("%s", nome);

    int encontrada = 0;

    for (int i = 0; i < *pos; i++)
    {
        if (strcmp(cat[i].nome, nome) == 0)
        {
            encontrada = 1;
            break;
        }
    }

    if (encontrada)
    {
        printf("Já existe uma série ou filme com esse nome!\n");
    }
    else
    {
        strcpy(cat[*pos].nome, nome);

        do
        {
            printf("1 - Série\n2 - Filme\nDigite o tipo: ");
            scanf("%i", &cat[*pos].tipo);
            if (cat[*pos].tipo != 1 && cat[*pos].tipo != 2)
            {
                printf("Opção inválida! Digite 1 para Série ou 2 para Filme.\n");
            }
        } while (cat[*pos].tipo != 1 && cat[*pos].tipo != 2);

        do {
            printf("\n1 - Não iniciado\n2 - Assistindo\n3 - Concluído\nDigite o status: ");
            scanf("%i", &cat[*pos].status);
            if (cat[*pos].status < 1 || cat[*pos].status > 3) {
                printf("Opção inválida! Escolha entre 1, 2 ou 3.\n");
            }
        } while (cat[*pos].status < 1 || cat[*pos].status > 3);

        (*pos)++;
        printf("\nAdicionado com sucesso!\n");
    }
}

void atualizarStatus(struct Catalogo cat[], int *pos)
{
    char nome[50];
    int status;

    printf("Digite o nome da série ou filme que deseja atualizar o status: ");
    scanf("%s", nome);

    int encontrada = 0;

    for (int i = 0; i < *pos; i++)
    {
        if (strcmp(cat[i].nome, nome) == 0)
        {
            encontrada = 1;

            do {
                printf("\n1 - Não iniciado\n2 - Assistindo\n3 - Concluído\nDigite o status que deseja alterar: ");
                scanf("%d", &status);
                if (status < 1 || status > 3) {
                    printf("Opção inválida! Escolha entre 1, 2 ou 3.\n");
                }
            } while (status < 1 || status > 3);

            cat[i].status = status;

            printf("Status alterado com sucesso!\n");
        }
    }

    if (!encontrada)
    {
        printf("Série ou filme não encontrado!\n");
    }
}

void consultarCatalogo(struct Catalogo cat[], int *pos)
{
    if (*pos < 1)
    {
        printf("Não existe nenhuma série ou filme!\n");
        return;
    }

    for (int i = 0; i < *pos; i++)
    {
        printf("\n--- Série/Filme %d ---\n", i + 1);
        printf("Nome: %s \n", cat[i].nome);

        switch (cat[i].tipo)
        {
        case 1:
            printf("Tipo: Série\n");
            break;
        case 2:
            printf("Tipo: Filme\n");
            break;
        }

        switch (cat[i].status)
        {
        case 1:
            printf("Status: Não iniciado\n");
            break;
        case 2:
            printf("Status: Assistindo\n");
            break;
        case 3:
            printf("Status: Concluido\n");
            break;
        }
    }
}

void excluirCatalogo(struct Catalogo cat[], int *pos)
{
    char nome[50];
    int encontrado = 0;

    if (*pos < 1)
    {
        printf("Não existe nenhuma série ou filme!\n");
        return;
    }

    printf("Digite o nome da série ou filme que deseja remover: ");
    scanf("%s", nome);

    for (int i = 0; i < *pos; i++)
    {
        if (strcmp(cat[i].nome, nome) == 0)
        {
            encontrado = 1;

            for (int j = i; j < *pos; j++)
            {
                cat[j] = cat[j + 1];
            }

            (*pos)--;

            printf("Série/Filme '%s' removido com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Série/Filme '%s' não encontrado!\n", nome);
    }
}

int main()
{
    struct Catalogo cat[N];
    int opcao, pos = 0;

    do
    {
        printf("\n----- Menu -----\n");
        printf("1 - Adicionar série ou filme\n");
        printf("2 - Atualizar status\n");
        printf("3 - Consultar catálogo\n");
        printf("4 - Excluir série ou filme\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarCatalogo(cat, &pos);
            break;
        case 2:
            atualizarStatus(cat, &pos);
            break;
        case 3:
            consultarCatalogo(cat, &pos);
            break;
        case 4:
            excluirCatalogo(cat, &pos);
            break;
        case 5:
            printf("Programa finalizado!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);
}