#ifndef included_circle_hpp
#define included_circle_hpp

class Circle {
    double radius;

    public:

      double min_x();
      double max_x();
      double min_y();
      double max_y();

      bool collides_circle(double position_x_delta, double position_y_delta, Circle *other);

      Circle(double radius);
};

#endif // included_circle_hpp
