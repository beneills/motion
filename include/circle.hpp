#ifndef included_circle_hpp
#define included_circle_hpp

class Circle {
    double centre_x;
    double centre_y;
    double radius;

    public:

    bool collides(Circle *other);

    Circle(double centre_x, double centre_y, double radius);
};

#endif // included_circle_hpp
