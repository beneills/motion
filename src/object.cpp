#include <iostream>

#include <circle.hpp>
#include <object.hpp>

bool Object::collides(Object *other) {
      return this->net->collides(other->position_x - this->position_x,
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
