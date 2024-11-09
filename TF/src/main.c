// main.c
#include "game.h"
#include "graphics.h"

int main() {
    if (!graphics_init()) {
        return 1;
    }

    game_init();
    game_loop();
    game_cleanup();

    return 0;
}