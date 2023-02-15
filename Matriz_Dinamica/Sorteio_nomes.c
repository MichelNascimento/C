#include <stdio.h>
#include <string.h>
#include <time.h>

void Quantidade(int *tam)
{
    printf("Digite a quantidade de nomes: ");
    scanf("%d", tam);
    getchar();
}

void Gravar(char **nomes, int *tam)
{
    int i;
    printf("Digite %d nomes.\n\n", *tam);
    for (i = 0; i < *tam; i++)
    {
        nomes[i] = calloc(20, sizeof(char));
    }

    for (i = 0; i < *tam; i++)
    {
        printf("%d. - ", i + 1);
        fgets(nomes[i], 20, stdin);
    }
}

void Sorteio(char **nomes, int *tam)
{
    int sort;
    srand(time(NULL));

    sort = rand() % *tam;
    printf("%d", sort);
    printf("\n\nO nome sorteado foi: %s\n", &nomes[sort][0]);
}

void Menu()
{
    printf("Opcao\n1 - Gravar Nomes\n2 - Sortear.\n3 - Sair.");
}

int main()
{
    int op;

    int *tam = malloc(sizeof(int));
    char **nomes = calloc(3, sizeof(char *));

    for (;;)
    {
        Menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Quantidade(tam);
            Gravar(nomes, tam);
            break;
        case 2:
            Sorteio(nomes, tam);
            break;
        case 3:
            puts("\n\nSaindo...");
            exit(0);
        default:
            puts("opcao invalida.\n");
        }
    }

    return 0;
}