#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Escrever(char nome[])
{
    FILE *file = fopen(nome, "w");
    char text;

    if(file)
    {
        printf("\nDigite um texto e pressione ENTER ao finalizar.\n");
        scanf("%c", &text);

        while(text != '\n')
        {
            fputc(text, file);
            scanf("%c", &text);
        }
        
        fclose(file);
    }
    else
    {
        printf("\nErro ao abrir o arquivo.");
    }
}

void Ler(char nome[])
{
    FILE *file = fopen(nome, "r");
    char text;

    if(file)
    {
        printf("\nLendo texto do arquivo.\n");
        while(!feof(file))
        {
            text = fgetc(file);
            printf("%c", text);
        }

        fclose(file);
    }
    else
    {
        printf("\nErro ao abrir o arquivo.");
    }
}

int main()
{
    char nome[] = {'\0'};
    char txt[] = {".txt"};
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    getchar();
    strcat(nome, txt);    

    Escrever(nome);
    Ler(nome);

    return 0;
}