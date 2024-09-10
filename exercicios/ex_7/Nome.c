#include <stdio.h>
#include <stRing.h>

int main()
{
    char nome [100];
    printf("Digite seu nome: ");
    
    scanf("%99s", nome);
    printf("\nO seu nome é: %s\n", nome);

    int tamanho = strlen(nome);
    printf("O tamanho do seu nome é: %d\n", tamanho);

    char *ptr;
    char *ptr_ultimo;
    
    ptr = nome;
    ptr_ultimo = ptr + tamanho;

    printf("O nome armazenado no vetor usndo ponteiros eh: %s\n", ptr);
    
    printf("O primeiro caractere do nome eh: %c\n", *ptr);

    printf("O seu nome de tras para frente eh: ");

    int i;
    for(i=0; i<tamanho+1; i++)
    {
        printf("%c", *ptr_ultimo);
        ptr_ultimo--;
    }   
    return 0;
}