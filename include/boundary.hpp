#ifndef included_boundary_hpp
#define included_boundary_hpp

#include <object.hpp>

// A square boundary for all objects.
class Boundary {
  double width;
  double height;

public:

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

  // Instantiate a new boundary object of given width and height.
  Boundary(double width, double height);
};

#endif // included_boundary_hpp
