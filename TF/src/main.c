#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char** argv) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Criar janela
    SDL_Window* window = SDL_CreateWindow(
        "Connect Four", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN
    );
    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Criar renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Carregar texturas
    SDL_Texture* boardTexture = IMG_LoadTexture(renderer, "jogo_tabuleiro.png");
    SDL_Texture* redPieceTexture = IMG_LoadTexture(renderer, "ficha_vermelha.png");
    SDL_Texture* yellowPieceTexture = IMG_LoadTexture(renderer, "ficha_amarela.png");

    if (!boardTexture || !redPieceTexture || !yellowPieceTexture) {
        printf("Erro ao carregar texturas: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Inicializar jogo
    Game game;
    game_init(&game);

    // Loop principal
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                game_handle_input(&game, event.button.x, event.button.y);
            }
        }

        // Atualizar estado do jogo
        game_update(&game);

        // Renderizar
        SDL_RenderClear(renderer);
        game_render(&game, renderer, boardTexture, redPieceTexture, yellowPieceTexture);
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    // Limpar recursos
    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(redPieceTexture);
    SDL_DestroyTexture(yellowPieceTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}