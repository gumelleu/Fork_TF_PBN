#include <stdio.h>

int main () {
    float nota1, nota2, nota3, media, escolha;
    char disciplina[50];

do{
    printf("Digite o nome da disciplina: ");
    scanf("%s", disciplina);

    printf("Digite a nota 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota 3:");
    scanf("%f", &nota3);
    media = (nota1 + nota2 + nota3) / 3;
    printf("A media do aluno na disciplina %s foi %.2f\n", disciplina, media);
    printf("Deseja calcular a media de outro aluno? (Y/N): ");
    while (getchar() != '\n');
        escolha = getchar();

}while (escolha == 'Y' || escolha == 'y');

    printf("Obrigado por usar o programa!\n");

    return 0;
}