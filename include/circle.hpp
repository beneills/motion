#ifndef included_circle_hpp
#define included_circle_hpp

class Circle {
    double radius;

    public:

    bool collides(double position_x_delta, double position_y_delta, Circle *other);

    Circle(double radius);
};

#endif // included_circle_hpp
