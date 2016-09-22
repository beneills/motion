#include <iostream>
#include <cmath>

#include <circle.hpp>
#include <object.hpp>

#define square(x) ((x)*(x))
#define modulus(x, y) sqrt( square(x) + square(y) )

double Object::velocity_magnitude() {
  return modulus( this->velocity_x, this->velocity_y );
}

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

void Object::rotate(double component_x, double component_y) {
  double rotation_magnitude = modulus(component_x, component_y);

  this->velocity_x = this->velocity_magnitude() * component_x / rotation_magnitude;
  this->velocity_y = this->velocity_magnitude() * component_y / rotation_magnitude;
}

void Object::recalculate_position(double ms) {
  this->position_x += ( this->velocity_x * ms ) / 1000;
  this->position_y += ( this->velocity_y * ms ) / 1000;
}

void Object::rewind_position(double ms) {
  recalculate_position(-ms);
}

bool Object::collides_object(Object *other) {
      return this->net->collides_circle(other->position_x - this->position_x,
        other->position_y - this->position_y,
        other->net);
}

Object::Object(double position_x, double position_y, double velocity_x, double velocity_y, double mass, Circle *net, Label *label) {
  this->position_x = position_x;
  this->position_y = position_y;

  this->velocity_x = velocity_x;
  this->velocity_y = velocity_y;
  this->mass = mass;

  this->net = new Circle(*net);

  if ( label == nullptr ) {
    this->label = new Label(200, 200, 200, 255, "default");
  } else {
    this->label = new Label(*label);
  }
}
