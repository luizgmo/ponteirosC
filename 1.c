#include <stdio.h>
#include <string.h>

#define N 50
#define MUSICA 3

struct playlist
{
    char nomePlaylist[50];
    char nomeCriador[50];
    int numeroMusicas;
    int tempoPlaylist;
};

void criarPlaylist(struct playlist pl[], int *pos)
{
    if (*pos >= N)
    {
        printf("Número máximo de playlists atingido!\n");
        return;
    }

    char nome[50];
    int nomeRepetido = 0;

    printf("Nome da playlist: ");
    scanf("%s", nome);

    for (int i = 0; i < *pos; i++)
    {
        if (strcmp(pl[i].nomePlaylist, nome) == 0)
        {
            nomeRepetido = 1;
            break;
        }
    }

    if (nomeRepetido)
    {
        printf("Já existe uma playlist com esse nome. Tente novamente.\n");
    }
    else
    {
        strcpy(pl[*pos].nomePlaylist, nome);
        printf("Digite o nome do criador: ");
        scanf("%s", pl[*pos].nomeCriador);
        pl[*pos].numeroMusicas = 0;
        pl[*pos].tempoPlaylist = 0;
        (*pos)++;
        printf("Playlist '%s' criada com sucesso!\n", nome);
    }
}

void removerPlaylist(struct playlist pl[], int *pos){
    char nome[50];
    int encontrado = 0;

    if (*pos < 1){
        printf("Não existe nenhuma playlist!\n");
        return;
    }

    printf("Digite o nome da playlist que deseja remover: ");
    scanf("%s", nome);

    for (int i = 0; i < *pos; i++){
        if (strcmp(pl[i].nomePlaylist, nome) == 0){
            encontrado = 1;

            for (int j = i; j < *pos; j++){
                pl[j] = pl[j + 1];
            }

            (*pos)--;

            printf("Playlist '%s' removida com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado){
        printf("Playlist '%s' não encontrada!\n", nome);
    }
}

void adicionarMusica(struct playlist pl[], int *pos){
    int quantidade;
    char nome[50];

    printf("Digite o nome da playlist que deseja adicionar músicas: ");
    scanf("%s", nome);

    int encontrada = 0;
    for (int i = 0; i < *pos; i++){
        if (strcmp(pl[i].nomePlaylist, nome) == 0){
            encontrada = 1;

            printf("Digite quantas músicas deseja adicionar: ");
            scanf("%d", &quantidade);

            pl[i].numeroMusicas += quantidade;
            pl[i].tempoPlaylist += quantidade * MUSICA;

            printf("Músicas adicionadas à playlist!\n");
        }
    }

    if (!encontrada){
        printf("Playlist '%s' não encontrada!\n", nome);
    }
}

void removerMusica(struct playlist pl[], int *pos){
    int quantidade;
    char nome[50];

    printf("Digite o nome da playlist que deseja remover músicas: ");
    scanf("%s", nome);

    int encontrada = 0;
    for (int i = 0; i < *pos; i++){
        if (strcmp(pl[i].nomePlaylist, nome) == 0){
            encontrada = 1;

            printf("Digite quantas músicas deseja remover: ");
            scanf("%d", &quantidade);

            if (quantidade > pl[i].numeroMusicas){
                printf("A playlist não possui músicas suficientes para serem removidas!\n");
                return;
            } else{
                pl[i].numeroMusicas -= quantidade;
                pl[i].tempoPlaylist -= quantidade * MUSICA;
            }

            printf("Músicas removidas da playlist!\n");
        }
    }

    if (!encontrada){
        printf("Playlist '%s' não encontrada!\n", nome);
    }
}

void exibirPlaylists(struct playlist pl[], int *pos){
    if (*pos < 1){
        printf("Não existe nenhuma playlist!\n");
        return;
    }

    for (int i = 0; i < *pos; i++){
        printf("\n--- Playlist %d ---\n", i + 1);
        printf("Nome da playlist %s \n", pl[i].nomePlaylist);
        printf("Nome do criador %s: \n", pl[i].nomeCriador);
        printf("Número de músicas %d: \n", pl[i].numeroMusicas);
        printf("Tempo total da playlist %d minutos: \n", pl[i].tempoPlaylist);
    }
}

int main()
{
    struct playlist pl[N];
    int opcao, pos = 0;

    do
    {
        printf("----- Menu -----\n");
        printf("1 - Criar nova playlist\n");
        printf("2 - Excluir playlist\n");
        printf("3 - Adicionar música\n");
        printf("4 - Remover música\n");
        printf("5 - Exibir playlists\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criarPlaylist(pl, &pos);
            break;
        case 2:
            removerPlaylist(pl, &pos);
            break;
        case 3:
            adicionarMusica(pl, &pos);
            break;
        case 4:
            removerMusica(pl, &pos);
            break;
        case 5:
            exibirPlaylists(pl, &pos);
            break;
        case 6:
            printf("Programa finalizado!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);
}