#include <iostream>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <rectangle.hpp>

#define square(x) ((x)*(x))

double Rectangle::min_x() {
  return 0;
}

double Rectangle::max_x() {
  return this->width;
}

double Rectangle::min_y() {
  return 0;
}

double Rectangle::max_y() {
  return this->height;
}

int Rectangle::draw(SDL_Renderer *ren, double position_x, double position_y, Label *label) {
  return boxColor(ren, position_x, position_y, position_x + this->width, position_y + this->height, label->color());
}

Rectangle::Rectangle(double width, double height) {
  this->width = width;
  this->height = height;
}
