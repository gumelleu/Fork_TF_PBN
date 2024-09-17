#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
    char nome[100], tipoSanguineo[3];
    int primeiraDoacao;
    float peso, idade;

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    printf("Digite a sua idade: ");
    scanf("%f", &idade);
    printf("Digite o seu peso: ");
    scanf("%f", &peso);
    printf("Digite o seu tipo sanguineo: ");
    scanf("%s", tipoSanguineo);

    if (idade < 16 || idade > 69 || peso < 50) {
        printf("Você não pode doar sangue\n");
    } else if (idade <= 60 && peso >= 50) {
        printf("A sua primeira doação foi antes dos 60 anos?\n");
        printf("Digite 1 para sim e 2 para não: ");
        scanf("%d", &primeiraDoacao);
        if (primeiraDoacao == 1) {
            printf("Você pode doar sangue\n");
        } else {
            printf("Você não pode doar sangue\n");
        }
    } else {
        printf("Você pode doar sangue\n");
    }

    if (strcmp(tipoSanguineo, "A") == 0 || strcmp(tipoSanguineo, "a") == 0) {
        printf("Nome %s, idade %.1f, peso %.1f kg: Você pode doar para A e AB\n", nome, idade, peso);
    } else if (strcmp(tipoSanguineo, "B") == 0 || strcmp(tipoSanguineo, "b") == 0) {
        printf("Nome %s, idade %.1f, peso %.1f kg: Você pode doar para B e AB\n", nome, idade, peso);
    } else if (strcmp(tipoSanguineo, "AB") == 0 || strcmp(tipoSanguineo, "ab") == 0) {
        printf("Nome %s, idade %.1f, peso %.1f kg: Você pode doar para AB\n", nome, idade, peso);
    } else if (strcmp(tipoSanguineo, "O") == 0 || strcmp(tipoSanguineo, "o") == 0) {
        printf("Nome %s, idade %.1f, peso %.1f kg: Você pode doar para todos os tipos sanguineos\n");
    } else {
        printf("Tipo sanguineo inválido\n");
    }

    return 0;
}