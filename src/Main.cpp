#include <iostream>
#include <SDL2/SDL.h>
#include "./Game/Game.h"

int main() {
    Game game;

    game.Init();
    game.Run();
    game.Destroy();


    return 0;
}
