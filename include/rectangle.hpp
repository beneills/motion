#ifndef included_rectangle_hpp
#define included_rectangle_hpp

#include <label.hpp>
#include <net.hpp>

// A rectangle with position coordinates corresponding to the top left.
class Rectangle : public Net {
public:
  double width;
  double height;

public:
  // The net's minimum x coordinate, relative to the object's position_x.
  double min_x();

  // The net's maximum x coordinate, relative to the object's position_x.
  double max_x();

  // The net's minimum y coordinate, relative to the object's position_y.
  double min_y();

  // The net's maximum y coordinate, relative to the object's position_y.
  double max_y();

  // Draw the rectangle to an SDL renderer.
  int draw(SDL_Renderer *ren, double position_x, double position_y, Label *label);

  // Instantiate a new rectangle, given a width and height.
  Rectangle(double width, double height);
};

#endif // included_rectangle_hpp
