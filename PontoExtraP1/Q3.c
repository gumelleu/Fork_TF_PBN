#include <stdio.h>

int main()
{
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;
int i;
printf("Valores antes das operações:\n");
for (i = 0; i < 5; i++)
{
printf("Valor em arr[]: %d\n",ptr[i]); //1
}
int temp = *(ptr + 4);
*(ptr + 4) = *ptr;
*ptr = temp; //2
 ptr++;
*(ptr + 4) -= 10;
ptr--;
printf("\nValores após as operações:\n");
for (i = 0; i < 5; i++)
{
printf("Valor em arr[]: %d\n", ptr[i]); //3
}
return 0;
}