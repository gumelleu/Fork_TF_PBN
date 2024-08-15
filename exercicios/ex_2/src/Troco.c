#include <stdio.h>

int main(void)
{
    int valor, n100, n50, n20, n10, n5, n2;
    int resto;

    printf("** Caixa Eletrônico **\n");
    printf("Digite o valor do saque: ");
    scanf("%d", &valor);
    
    n100 = valor / 100;
    resto = valor % 100;

    n50 = resto / 50;
    resto = resto % 50;

    n20 = resto / 20;
    resto = resto % 20;

    n10 = resto / 10;
    resto = resto % 10;

    n5 = resto / 5;
    resto = resto % 5;

    n2 = resto / 2;
    resto = resto % 2;

    printf("Notas de 100=%d, de 50=%d, de 20=%d, de 10=%d, de 5=%d, de 2=%d\n", n100, n50, n20, n10, n5, n2);


}