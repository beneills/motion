#ifndef included_object_hpp
#define included_object_hpp

#include <circle.hpp>

class Object {
  double position_x;
  double position_y;

  double velocity_x;
  double velocity_y;

  double mass;

  Circle *net;

  public:

    double min_x();
    double max_x();
    double min_y();
    double max_y();

    bool collides_object(Object *other);

    Object(double position_x, double position_y, double velocity_x, double velocity_y, double mass, Circle *net);
};

#endif // included_object_hpp
