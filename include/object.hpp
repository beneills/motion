#ifndef included_object_hpp
#define included_object_hpp

class Object {
  double position_x;
  double position_y;

  double velocity_x;
  double velocity_y;

  double mass;

  Circle *net;

  public:

    bool collides(Object *other);

    Object(double position_x, double position_y, double velocity_x, double velocity_y, double mass, Circle *net);
};

#endif // included_object_hpp
