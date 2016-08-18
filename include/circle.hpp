#ifndef included_circle_hpp
#define included_circle_hpp

#include <net.hpp>

class Circle : public Net {
public:
  double radius;

public:
  // The net's minimum x coordinate, relative to the object's position_x.
  double min_x();

  // The net's maximum x coordinate, relative to the object's position_x.
  double max_x();

  // The net's minimum y coordinate, relative to the object's position_y.
  double min_y();

  // The net's maximum y coordinate, relative to the object's position_y.
  double max_y();

  // Does this circle collide with another, given the relative distance between their object's positions.
  bool collides_circle(double position_x_delta, double position_y_delta, Circle *other);

  // Instantiate a new circle, given a radius.
  Circle(double radius);
};

#endif // included_circle_hpp
