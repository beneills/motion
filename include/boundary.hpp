#ifndef included_boundary_hpp
#define included_boundary_hpp

#include <SDL2/SDL2_gfxPrimitives.h>

#include <object.hpp>

// A square boundary for all objects.
class Boundary {
public:
  double width;
  double height;

public:
  // How far are we over the left wall?
  double collision_depth_left(Object *o);

  // How far are we over the right wall?
  double collision_depth_right(Object *o);

  // How far are we over the top wall?
  double collision_depth_top(Object *o);

  // How far are we over the bottom wall?
  double collision_depth_bottom(Object *o);

  // Does the object collide with the left wall?
  bool collides_left(Object *o);

  // Does the object collide with the right wall?
  bool collides_right(Object *o);

  // Does the object collide with the top wall?
  bool collides_top(Object *o);

  // Does the object collide with the bottom wall?
  bool collides_bottom(Object *o);

  // Does the object collide with any walls?
  bool collides(Object *o);

  // Draw the boundary to an SDL renderer.
  int draw(SDL_Renderer *ren, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  // Instantiate a new boundary object of given width and height.
  Boundary(double width, double height);
};

#endif // included_boundary_hpp
