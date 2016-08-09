#include <boundary.hpp>
#include <object.hpp>

bool Boundary::collides_left(Object *o) {
  return o->min_x() < 0;
}

bool Boundary::collides_right(Object *o) {
  return o->max_x() >= this->width;
}

bool Boundary::collides_bottom(Object *o) {
  return o->min_y() < 0;
}

bool Boundary::collides_top(Object *o) {
  return o->max_y() >= this->height;
}

bool Boundary::collides(Object *o) {
  return this->collides_left(o)
    || this->collides_right(o)
    || this->collides_top(o)
    || this->collides_bottom(o);
}

Boundary::Boundary(double width, double height) {
  this->width = width;
  this->height = height;
}
