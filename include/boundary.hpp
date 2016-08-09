#ifndef included_boundary_hpp
#define included_boundary_hpp

#include <object.hpp>

// A square boundary for all objects.
class Boundary {
  double width;
  double height;

  public:

    bool collides_left(Object *o);
    bool collides_right(Object *o);
    bool collides_top(Object *o);
    bool collides_bottom(Object *o);

    bool collides(Object *o);

    Boundary(double width, double height);
};

#endif // included_boundary_hpp
