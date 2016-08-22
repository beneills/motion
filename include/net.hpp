#ifndef included_net_hpp
#define included_net_hpp

#include <SDL2/SDL.h>

class Net {

public:
  // The net's minimum x coordinate, relative to the object's position_x.
  virtual double min_x() = 0;

  // The net's maximum x coordinate, relative to the object's position_x.
  virtual double max_x() = 0;

  // The net's minimum y coordinate, relative to the object's position_y.
  virtual double min_y() = 0;

  // The net's maximum y coordinate, relative to the object's position_y.
  virtual double max_y() = 0;

  // Can this net collide with another?
  bool possibly_collides(Net *other);

  // Draw the net to an SDL renderer.
  virtual int draw(SDL_Renderer *ren, double position_x, double position_y, Uint32 color) = 0;
};

#endif // included_net_hpp
