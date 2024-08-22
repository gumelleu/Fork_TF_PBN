#include <stdio.h>

int main () {
    float nota1, nota2, nota3, notag2, media, escolha, g1, gf, g2;
    char disciplina[50];
    int g1contador = 0;
    int g2contador = 0;
    float gfcontador = 0;

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
            g2contador = 1;
        } else {
            printf("Aprovado em G1\n");
            g1 = media;
        }

        if (g2contador == 1) {
            g2 = (10 - media);
            printf("A nota necessária na g2 para passar por gf é: %f\n", g2);
            printf("Digite a nota da G2: \n");
            scanf("%f", &notag2);
            gf = (g1 + notag2) / 2;
        } 
        
        if (notag2>= 5) {
            printf("Aprovado por GF\n");
        } else {
            printf("Reprovado por GF\n");
        }


        printf("Deseja calcular a média de outro aluno? (Y/N): ");

        while (getchar() != '\n');
        escolha = getchar();

        // Limpeza da entrada g1, g2, gf
        g1contador = 0;
        g2contador = 0;
        gfcontador = 0;

    } while (escolha == 'Y' || escolha == 'y');

    printf("Obrigado por usar o programa!\n");

    return 0;
}