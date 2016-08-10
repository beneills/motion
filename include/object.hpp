#ifndef included_object_hpp
#define included_object_hpp

#include <circle.hpp>

class Object {
public:
  double position_x;
  double position_y;

  double velocity_x;
  double velocity_y;

  double mass;

  Circle *net;

public:
  // The object's minimum (absolute) x coordinate.
  double min_x();

  // The object's maximum (absolute) x coordinate.
  double max_x();

  // The object's minimum (absolute) y coordinate.
  double min_y();

  // The object's maximum (absolute) y coordinate.
  double max_y();

  // Recalculate the object's position, given elapsed time since last calculation.
  void recalculate_position(double ms);

  // Does this object collide with another?
  bool collides_object(Object *other);

  // Instantiate an object given its position/velocity data and a net.
  Object(double position_x, double position_y, double velocity_x, double velocity_y, double mass, Circle *net);
};

#endif // included_object_hpp
