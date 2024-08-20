#include <stdio.h>

int main() {
    float peso, altura, imc;
    char escolha;

    do {
        printf("Digite o seu peso (kg): ");
        scanf("%f", &peso);

        printf("Digite a sua altura (m): ");
        scanf("%f", &altura);

        imc = peso / (altura * altura);

        printf("IMC = %.2f\n", imc);

        if (imc < 18.5) {
            printf("Abaixo do peso\n");
        } else if (imc < 25) {
            printf("Peso normal\n");
        } else if (imc < 30) {
            printf("Sobrepeso\n");
        } else if (imc < 35) {
            printf("Obesidade grau 1\n");
        } else if (imc < 40) {
            printf("Obesidade grau 2\n");
        } else {
            printf("Obesidade grau 3\n");
        }

        printf("Deseja calcular o IMC de outra pessoa? (Y/N): ");
        while (getchar() != '\n');  // Limpa o buffer
        escolha = getchar(); 

    } while (escolha == 'Y' || escolha == 'y');

    printf("Obrigado por usar o programa!\n");

    return 0;
}