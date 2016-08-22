#ifndef included_graphics_hpp
#define included_graphics_hpp

#include <SDL2/SDL.h>

#include <map.hpp>

class Graphics {
  SDL_Window *win;
  SDL_Renderer *ren;
  SDL_Texture *tex;

public:
  // Demo graphics.
  bool demo();

  // Render a map.
  bool render(Map *map);

  // Delay some milliseconds.
  void delay(unsigned int ms);

  // Setup graphics.
  Graphics();

  // Destroy graphics.
  ~Graphics();
};

#endif // included_graphics_hpp
