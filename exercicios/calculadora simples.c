#include <stdio.h>

int main()
{
    float p1, p2, resultado;
    char op;

    printf("** Calculadora 4 operações **\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &p1);
    printf("Digite o segundo número: ");
    scanf("%f", &p2);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &op);
    
    switch (op)
    {
    case '+':
        resultado = p1 + p2;
        printf("Resultado: %.2f\n", resultado);
        break;

    case '-':  
        resultado = p1 - p2;
        printf("Resultado: %.2f\n", resultado);
        break;

    case '*':
        resultado = p1 * p2;
        printf("Resultado: %.2f\n", resultado);
        break;

    case '/':
    if (p2 != 0)
    {
        resultado = p1 / p2;
        printf("Resultado: %.2f\n", resultado);}
        else{
        printf("Divisão inválida\n");}
        break;
    
    default:
        printf("Operação inválida\n");
        break;
    }
}
