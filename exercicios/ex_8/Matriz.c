#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define colunas 5
#define linhas 5

int matriz[linhas][colunas];

int main()
{
    int i, j;
    srand(time(NULL));

    for(i=0; i<linhas;i++)
    {
        for(j=0; j<colunas; j++)
        {
            matriz[i][j] = rand()%100;
            printf("matriz[%d][%d]=%d\n",i,j,matriz[i][j]);
        }
    }
    return 0;
}