#include <boundary.hpp>
#include <object.hpp>

#include <object_pool.hpp>

double Boundary::collision_depth_left(Object *o) {
  return -o->min_x();
}

double Boundary::collision_depth_right(Object *o) {
  return o->max_x() - this->width;
}

double Boundary::collision_depth_top(Object *o) {
  return -o->min_y();
}

double Boundary::collision_depth_bottom(Object *o) {
  return o->max_y() - this->height;
}

bool Boundary::collides_left(Object *o) {
  return this->collision_depth_left(o) > 0;
}

bool Boundary::collides_right(Object *o) {
  return this->collision_depth_right(o) > 0;
}

bool Boundary::collides_bottom(Object *o) {
  return this->collision_depth_bottom(o) > 0;
}

bool Boundary::collides_top(Object *o) {
  return this->collision_depth_top(o) > 0;
}

bool Boundary::collides(Object *o) {
  return this->collides_left(o)
    || this->collides_right(o)
    || this->collides_top(o)
    || this->collides_bottom(o);
}

int Boundary::draw(SDL_Renderer *ren, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = this->width;
  rect.h = this->height;

  SDL_SetRenderDrawColor(ren, r, g, b, a);
  return SDL_RenderDrawRect(ren, &rect);
}

Boundary::Boundary(double width, double height) {
  this->width = width;
  this->height = height;
}
