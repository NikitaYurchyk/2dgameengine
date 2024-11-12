#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "../ECS/ECS.h"
#include <glm/glm.hpp>
#include <SDL2/SDL_image.h>



Game::Game(){
  isRunning = false;
  std::cout<<"Game Constructor called"<<std::endl;
}
Game::~Game(){
  std::cout<<"Game Destructor called"<<std::endl;
}



void Game::Init(){
  if(SDL_Init(SDL_INIT_EVERYTHING)!= 0){
     std::cout<< "SDL_Init Error: "<< SDL_GetError() << std::endl;
    return;
  }
  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(0, &displayMode);
  windowHeight = displayMode.w;
  windowWidth = displayMode.h;
  window = SDL_CreateWindow(NULL,
		  SDL_WINDOWPOS_CENTERED,
		  SDL_WINDOWPOS_CENTERED,
		  windowHeight,
		  windowWidth,
		  SDL_WINDOW_BORDERLESS);
  if(!window){
    std::cerr << "Error creating SDL window" << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(!renderer){
    std::cerr << "Error creating SDL render" << std::endl;
    return;
  }
  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
  isRunning = true;
}
glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup(){
  // TODO: 
  // Entity tank = registery.CreateEntity()
  // tank.AddComponent<TransformComponent>();
  // tank.AddComponent<BoxColliderComponent>();
  // tank.AddComponent<SpriteComponent>("./asstes/images/tank.png")
  playerPosition = glm::vec2(10.0, 20.0);
  playerVelocity = glm::vec2(20.0, 2.0);
}
void Game::Update(){
  //if we are too fast waste some time until we reach the MILLISECS_PER_FRAME
  int timeToWait = MILLESECS_PER_FRAME - (SDL_GetTicks() - millsecsPrevFrame);
  if(timeToWait > 0 && timeToWait <= MILLESECS_PER_FRAME){
    SDL_Delay(timeToWait);
  }
  //The difference in ticks since the last frame, converted to sec
  double deltaTime = (SDL_GetTicks() - millsecsPrevFrame) / 1000.0f;
  millsecsPrevFrame = SDL_GetTicks();
  // playerPosition.x += playerVelocity.x * deltaTime;
  // playerPosition.y += playerVelocity.y * deltaTime;
  //TODO:
  // MovementSystem.Update();
  // CollisionSystem.Update();
  // DamageSystem.Update();

}

void Game::Render(){
  SDL_SetRenderDrawColor(renderer, 15, 100, 50, 255);
  SDL_RenderClear(renderer);
  //draw a rectangle 
  SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect dstRect = {static_cast<int>(playerPosition.x), static_cast<int>(playerPosition.y), 32, 32};

  SDL_RenderCopy(renderer, texture, NULL, &dstRect);
  SDL_DestroyTexture(texture);
  SDL_RenderPresent(renderer);
}

void Game::Destroy(){}

void Game::Run(){
  Setup();
  while(isRunning){
    ProcessInput();
    Update();
    Render();
  }
}
void Game::ProcessInput(){
  SDL_Event sdlEvent;
  while(SDL_PollEvent(&sdlEvent)){
      switch(sdlEvent.type){
        case SDL_QUIT:
          isRunning = false;
          break;
         case SDL_KEYDOWN:
           if(sdlEvent.key.keysym.sym == SDLK_ESCAPE){
             isRunning = false;
           }
           break;
      }
   }
}
