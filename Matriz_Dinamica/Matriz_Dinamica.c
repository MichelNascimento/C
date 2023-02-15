#include <stdio.h>
#include <string.h>
#include <time.h>


void Quantidade(int *tam)
{
    printf("Digite a quantidade de nomes: ");
    scanf("%d", tam);
    getchar();
}

void Gravar(char **mat, int *tam)
{
    int i;
    printf("Digite %d nomes.\n\n", *tam);
    for (i = 0; i < *tam; i++)
    {
        mat[i] = calloc(20, sizeof(char));
    }

    for (i = 0; i < *tam; i++)
    {
        printf("%d. - ", i + 1);
        fgets(mat[i], 20, stdin);
    }
}

void Imprimir(char **mat, int *tam)
{
    int i;
    puts("\nNomes:");
    for (i = 0; i < *tam; i++)
    {
        printf("\t%s", &mat[i][0]);
    }
}

int main()
{

    int *tam = malloc(sizeof(int));
    char **mat = calloc(3, sizeof(char *));
    Quantidade(tam);

    Gravar(mat, tam);
    Imprimir(mat, tam);

    return 0;
}