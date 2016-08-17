#include <exception>
#include <iostream>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <graphics.hpp>

bool Graphics::demo() {
  SDL_SetRenderDrawColor(this->ren, 0, 0, 0, 255);
  SDL_RenderClear(this->ren);

  int result = filledCircleColor(this->ren, 100, 100, 50, 0xFF0000FF);

  SDL_RenderPresent(this->ren);

  SDL_Delay(3000);

  return true;
}

Graphics::Graphics() {
  // Code based on http://www.willusher.io/pages/sdl2/

  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    throw std::runtime_error("SDL_Init error");
  }

  this->win = SDL_CreateWindow("motion", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (this->win == nullptr){
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    throw std::runtime_error("SDL_CreateWindow error");
  }

  this->ren = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (this->ren == nullptr){
    SDL_DestroyWindow(this->win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    throw std::runtime_error("SDL_CreateRenderer error");
  }
}

Graphics::~Graphics() {
  SDL_DestroyTexture(this->tex);
  SDL_DestroyRenderer(this->ren);
  SDL_DestroyWindow(this->win);
  SDL_Quit();
}
