#include <stdio.h>
int main()
{
int i, j;
char matriz[2][4] = {{'x', 'y', 'z', 'w'}, {'a', 'b', 'c', 'd'}};
char temp;
char *ptr = &matriz[0][0];
for (i = 0; i < 4; i++)
{
temp = *(ptr + i);
*(ptr + i) = *(ptr + i + 4);
*(ptr + i + 4) = temp;
}
printf("Imprime:\n");
for (i = 0; i < 2; i++)
{
for (j = 0; j < 4; j++)
{
printf("%c ", matriz[i][j]);
}
printf("\n");
}
return 0;
}
