#include <iostream>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <circle.hpp>

#define square(x) ((x)*(x))

double Circle::min_x() {
  return -this->radius;
}

double Circle::max_x() {
  return this->radius;
}

double Circle::min_y() {
  return -this->radius;
}

double Circle::max_y() {
  return this->radius;
}

bool Circle::collides_circle(double position_x_delta, double position_y_delta, Circle *other) {
  double square_distance = square( position_x_delta ) + square( position_y_delta );

  return square_distance < square( this->radius + other->radius );
}

int Circle::draw(SDL_Renderer *ren, double position_x, double position_y, Label *label) {
  return filledCircleColor(ren, position_x, position_y, this->radius, label->color());
}

Circle::Circle(double radius) {
  this->radius = radius;
}
