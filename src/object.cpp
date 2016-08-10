#include <iostream>

#include <circle.hpp>
#include <object.hpp>

double Object::min_x() {
  return this->position_x + this->net->min_x();
}

double Object::max_x() {
  return this->position_x + this->net->max_x();
}

double Object::min_y() {
  return this->position_y + this->net->min_y();
}

double Object::max_y() {
  return this->position_y + this->net->max_y();
}

void Object::recalculate_position(double ms) {
  this->position_x += this->velocity_x * ms;
  this->position_y += this->velocity_y * ms;
}

bool Object::collides_object(Object *other) {
      return this->net->collides_circle(other->position_y - this->position_x,
        other->position_y - this->position_y,
        other->net);
}

Object::Object(double position_x, double position_y, double velocity_x, double velocity_y, double mass, Circle *net) {
  this->position_x = position_x;
  this->position_y = position_y;

  this->velocity_x = velocity_x;
  this->velocity_y = velocity_y;
  this->mass = mass;

  // TODO make safer
  this->net = (Circle *) malloc(sizeof(*net));
  memcpy(this->net, net, sizeof(*net));
}
