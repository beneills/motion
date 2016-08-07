#include <circle.hpp>

#define square(x) ((x)*(x))

bool Circle::collides(Circle *other) {
      double square_distance = square( this->centre_x - other->centre_x ) + square( this->centre_y - other->centre_y );

      return square_distance < square( this->radius + other->radius );
}

Circle::Circle(double centre_x, double centre_y, double radius) {
  this->centre_x = centre_x;
  this->centre_y = centre_y;
  this->radius = radius;
}
