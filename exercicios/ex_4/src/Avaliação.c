#include <stdio.h>

int main () {
    float nota1, nota2, nota3, notag2, media, escolha;
    char disciplina[50];
    int g1 = 0;
    int g2 = 0;
    float gf = 0;

    do {
        printf("Digite o nome da disciplina: ");
        scanf("%s", disciplina);

        printf("Digite a nota 1: ");
        scanf("%f", &nota1);
        printf("Digite a nota 2: ");
        scanf("%f", &nota2);
        printf("Digite a nota 3: ");
        scanf("%f", &nota3);
        
        media = (nota1 + nota2 + nota3) / 3;
        printf("A média do aluno na disciplina %s foi %.2f\n", disciplina, media);

        if (media < 4) {
            printf("Reprovado\n");
        } else if (media >= 4 && media <= 6.99) {
            printf("Passou para G2\n");
            g2 += 1;
        } else {
            printf("Aprovado em G1\n");
            //g1 = media;
        }

        if (g2 == 1) {
            gf = (media + notag2) / 2;
            printf("A nota necessária na g2 para passar por gf é: %f\n", gf);
        }

        printf("Deseja calcular a média de outro aluno? (Y/N): ");

        while (getchar() != '\n');
        escolha = getchar();

        // Limpeza da entrada g1, g2, gf
        g1 = 0;
        g2 = 0;
        gf = 0;

    } while (escolha == 'Y' || escolha == 'y');

    printf("Obrigado por usar o programa!\n");

    return 0;
}