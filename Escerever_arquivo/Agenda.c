#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char nome[50];
    int dia,mes,ano;
}Contato;

void Imprimir(Contato **c, int quant)
{
    int i;
    printf("\n\tLista de contatos\n");
    printf("------------------------------------------------\n");
    for(i=0 ; i<quant ; i++)
    {
        printf("\t%d - %2d/%2d/%4d\t%s\n", i+1, c[i]->dia,c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("------------------------------------------------\n");

}

int Cadastro(Contato **c, int quant, int tam)
{
    if(quant < tam)
    {
        Contato *novo = malloc(sizeof(Contato));

        printf("Digite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario: dd mm aaaa: ");
        scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;

        return 1;
    }
    else
    {
        printf("\nAgenda cheia\n");
        return 0;
    }
}

void Alterar(Contato **c, int quant)
{
    int id;

    Imprimir(c, quant);
    printf("\nDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant)
    {
        Contato *novo = malloc(sizeof(Contato));

        printf("Digite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario: dd mm aaaa: ");
        scanf("%d %d %d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;      

    }

}

void Salvar(Contato **c, int quant)
{
    FILE *file = fopen("arq.txt", "w");
    int i;

    if(file)
    {
        fprintf(file, "%d\n", quant);
        for(i=0 ; i<quant ; i++)
        {
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
    {
        printf("Erro ao abrir o arquivo.\n");
    }

}


int main()
{
    Contato *agenda[50];
    int tam = 50, quant = 0;
    int op;

    do
    {
        printf("\n1 - Cadastrar\n2 - Alterar\n3 - Imprimir\n4 - Salvar\n5 - Ler arquivo\n0 - Sair\n");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
            quant += Cadastro(agenda, quant, tam);
            break;

            case 2:
            Alterar(agenda, quant);
            break;

            case 3:
            Imprimir(agenda, quant);
            break;

            case 4:
            Salvar(agenda, quant);
            break;

            case 5:

            break;

            case 0:
            printf("Saindo...\n");
            exit(0);

            default:
            printf("\nOpcao invalida\n");           

        }


    } while (op !=0);
    

    Imprimir(agenda, quant);
    quant += Cadastro(agenda, quant, tam);
    Imprimir(agenda, quant);



}