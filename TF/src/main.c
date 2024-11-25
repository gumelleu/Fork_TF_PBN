#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

int jogada = 0;
int joga=0;

int valor_maximo = 0;
SDL_Renderer *renderer = NULL;
SDL_Texture *tabuleiro = NULL;
SDL_Texture *ficha_vermelha = NULL;
SDL_Texture *ficha_amarela = NULL;
SDL_Texture *ficha_transparente = NULL;
SDL_Window* window = NULL;
SDL_Rect quad1;



int matriz[7] = {0,0,0,0,0,0,0};

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
        "Conect Four",
        100, 100,
        1500, 1024,
        SDL_WINDOW_SHOWN
        );

    renderer = SDL_CreateRenderer(window, -1, 0);
    tabuleiro = IMG_LoadTexture(renderer, "jogo_tabuleiro.png");
    ficha_vermelha = IMG_LoadTexture(renderer, "ficha_vermelha.png");
    ficha_amarela = IMG_LoadTexture(renderer, "ficha_amarela.png");
    ficha_transparente = IMG_LoadTexture(renderer, "ficha_transparente.png");

    quad1.x = 200;
    quad1.y = 150;
    quad1.w = 1108;
    quad1.h = 887;

    SDL_RenderClear(renderer);
    
//    SDL_SetRenderDrawColor(renderer, 240, 250, 50, 255);
//    SDL_RenderFillRect(renderer, &quad2);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Posição inicial da peça
    int posicaoX = 275; // posição X
    int posicaoY = 50;   // posição Y
    int pos_antY;

    int seleciona_ficha = 0;
    int running = 1;
    SDL_RenderClear(renderer);


    while (running){
        // Processar eventos
        
        // Esse loop while só é realizado se ocorre algum evento (event = teclado, mouse, fechamento da janela, etc..)
        SDL_Event event;
        while(SDL_PollEvent(&event))
	    {
            // Verifica se o evento foi "fechar janela"
      	    if( event.type == SDL_QUIT )
	        {
        	    exit(0);
      	    }

            // Verifica se o evento foi do tipo clique (MOUSEBUTTONDOWN) do botão esquerdo (BUTTON_LEFT) do mouse
	        else if( event.type == SDL_MOUSEBUTTONDOWN && event.button.button== SDL_BUTTON_LEFT)
	        {
                // Se for, captura a cordenada x e y.....
                int mouse_x = event.button.x;
                int mouse_y = event.button.y;
                
                printf("A coord_x eh: %d\n", mouse_x);
                printf("A coord_y eh: %d\n", mouse_y);

                // Agora verifica se as coordenadas xy correspondem a ficha vermelha ou....
                if(mouse_x>100 && mouse_x<232 && mouse_y>200 && mouse_y<332)
                {
                    posicaoY = 50;
                    joga=1;
                    seleciona_ficha = 0;    // ficha VERMELHA
                    printf("ficha vermelha\n");
                }

                // ....é a ficha amarela.
                else if(mouse_x>100 && mouse_x<232 && mouse_y>400 && mouse_y<532)
                {
                    posicaoY = 50;
                    joga=1;
                    seleciona_ficha = 1;    // ficha AMARELA
                    printf("ficha amarela\n");
                }
            }
        }

            // Atualizar a posição da peça
            // Faz a peça descer

        if(joga==1)
        {
            if(matriz[6]==0) valor_maximo = 850;
            else if(matriz[6]==1 && matriz[5]==0) valor_maximo = 718;
            else if(matriz[5]==1 && matriz[4]==0) valor_maximo = 586;
            else if(matriz[4]==1 && matriz[3]==0) valor_maximo = 454;
            else if(matriz[3]==1 && matriz[2]==0) valor_maximo = 320;
            else if(matriz[2]==1 && matriz[1]==0) valor_maximo = 188;
            else if(matriz[1]==1 && matriz[0]==0) valor_maximo = 50;
            joga=0;
        }

        if (posicaoY < valor_maximo)
        {
            pos_antY = posicaoY;
            posicaoY += 1; 
            printf("O valor da coordenada eh: %d\n", posicaoY);
        }
        else
        {
            if(valor_maximo==850) matriz[6]=1;
            else if(valor_maximo==718) matriz[5]=1;
            else if(valor_maximo==586) matriz[4]=1;
            else if(valor_maximo==454) matriz[3]=1;
            else if(valor_maximo==320) matriz[2]=1;
            else if(valor_maximo==188) matriz[1]=1;
            else if(valor_maximo==50) matriz[0]=1;

            pos_antY = posicaoY;
            posicaoY = posicaoY; 
        } // Reiniciar a posição se passar da tela
        // Limpar a tela

        // Renderizar a peça
        SDL_Rect local_vermelha = { 100, 200, 132, 132};   // Ajuste a largura e altura conforme necessário
        SDL_RenderCopy(renderer, ficha_vermelha, NULL, &local_vermelha);

        SDL_Rect local_amarela = { 100, 400, 132, 132};   // Ajuste a largura e altura conforme necessário
        SDL_RenderCopy(renderer, ficha_amarela, NULL, &local_amarela);

        // Renderizar a peça
        if(seleciona_ficha == 0)
        {
            SDL_Rect posicao_anterior = { posicaoX, pos_antY, 132, 132};   // Ajuste a largura e altura conforme necessário
            SDL_RenderCopy(renderer, ficha_transparente, NULL, &posicao_anterior);

            SDL_Rect posicao_inicial = { posicaoX, posicaoY, 132, 132};   // Ajuste a largura e altura conforme necessário
            SDL_RenderCopy(renderer, ficha_vermelha, NULL, &posicao_inicial);
        }
        else if(seleciona_ficha == 1)
        {
            SDL_Rect posicao_anterior = { posicaoX, pos_antY, 132, 132};   // Ajuste a largura e altura conforme necessário
            SDL_RenderCopy(renderer, ficha_transparente, NULL, &posicao_anterior);

            SDL_Rect posicao_inicial = { posicaoX, posicaoY, 132, 132};   // Ajuste a largura e altura conforme necessário
            SDL_RenderCopy(renderer, ficha_amarela, NULL, &posicao_inicial);
        }
        // Renderizar o tabuleiro
        SDL_RenderCopy(renderer, tabuleiro, NULL, &quad1);

        // Mostrar na tela
        SDL_RenderPresent(renderer);
        SDL_Delay(10); // Aproximadamente 60 FPS
    }

  SDL_DestroyTexture(tabuleiro);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}