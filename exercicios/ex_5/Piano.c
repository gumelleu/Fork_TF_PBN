#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define TEMPO 500  // Duração da nota em milissegundos

int main()
{
    char tecla;
    int freq;
    printf("Piano Simples em C\n");
    printf("Pressione as teclas A, S, D, F, G, H, J para tocar diferentes notas.\n");
    printf("Pressione 'ESC' para sair.\n");

    while (1)
    {
        tecla = getch();

        if (tecla == 27)  // 27 é o código ASCII para a tecla 'ESC'
            break;

        switch (tecla)
        {
        
        case 'a':
                freq = 523;  // Dó
                break;
	    case 's':
                freq = 587;  // Ré
                break;
                case 'd':
                freq = 659;  // Mi
                break;
            case 'f':
                freq = 698;  // Fá
                break;
            case 'g':
                freq = 784;  // Sol
                break;
            case 'h':
                freq = 880;  // Lá
                break;
            case 'j':
                freq = 988;  // Si
                break;
            default:
                freq = 0;  // Nenhuma nota para outras teclas
                break;
        }

        if (freq > 0)
        {
            Beep(freq, TEMPO);  // Toca a nota correspondente
        }
    }
    return 0;
}