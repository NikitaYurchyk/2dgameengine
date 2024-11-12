#pragma once
#include <SDL2/SDL.h>

const int FPS = 120;
const int MILLESECS_PER_FRAME = 1000 / FPS;

class Game {
public:
    Game();
    ~Game();
    void Init();
    void Setup();
    void Run();
    void ProcessInput();
    void Render();
    void Update();
    void Destroy();
    int windowHeight;
    int windowWidth;
private:
    int millsecsPrevFrame = 0;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
};



