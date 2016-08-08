#include <circle.hpp>

#define square(x) ((x)*(x))

bool Circle::collides(double position_x_delta, double position_y_delta, Circle *other) {
      double square_distance = square( position_x_delta ) + square( position_y_delta );

      return square_distance < square( this->radius + other->radius );
}

Circle::Circle(double radius) {
  this->radius = radius;
}
