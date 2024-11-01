#include <stdio.h>

int vetor_fibonacci[45];
void call_gera_serie(int valor);

int main()
{
int num;
    printf("Informe o número de interações da série de Fibonacci: ");
    scanf("%d", &num);
    if(num<=45){
    call_gera_serie(num);
    }else {
        printf("O valor deve ser até 45");
    }
    return 0;
}
void call_gera_serie(int num)
{
        int a = 0, b = 1, aux, count = 1; 
    do {
        if (count == 1) {
            printf("%d ", a); 
        } else if (count == 2) {
            printf("%d ", b); 
        } else {
            aux = a + b; 
            printf("%d ", aux); 
            a = b; 
            b = aux;
        }
        count++;
    } while (count <= num);

 }