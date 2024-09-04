#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeros[6];
    int i, j;

    // Semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Gerar 6 números únicos
    for (i = 0; i < 6; i++) {
        int numero_ja_gerado;
        do {
            numero_ja_gerado = 0;
            numeros[i] = rand() % 60 + 1; // Gera um número entre 1 e 60

            // Verifica se o número já foi gerado
            for (j = 0; j < i; j++) {
                if (numeros[i] == numeros[j]) {
                    numero_ja_gerado = 1;
                    break;
                }
            }
        } while (numero_ja_gerado); // Se o número já foi gerado, gera outro
    }

    // Exibe os números gerados
    printf("Números da MegaSena: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}