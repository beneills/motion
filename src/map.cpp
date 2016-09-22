#include <iostream>

#include <map.hpp>
#include <object_pool.hpp>

#define square(x) ((x)*(x))
#define modulus(x, y) sqrt( square(x) + square(y) )
#define dot(x1, y1, x2, y2) ((x1) * (x2) + (y1) * (y2))

bool Map::add_object(Object *o) {
  this->object_pool->add_object(o);
  return true;
}

void Map::update(double ms) {
  // Update positions
  for (int i = 0; i < this->object_pool->num(); ++i) {
    Object *o = this->object_pool->object(i);
    o->recalculate_position(ms);
  }

  // Check for collisions
  for (int i = 0; i < this->object_pool->num(); ++i) {
    Object *o = this->object_pool->object(i);

    // Check for boundary collisions
    if ( this->boundary->collides_left(o) ) {
      o->velocity_x = -o->velocity_x;
      o->position_x = this->boundary->collision_depth_left(o) + o->net->radius;
    }

    if ( this->boundary->collides_right(o) ) {
      o->velocity_x = -o->velocity_x;
      o->position_x = this->boundary->width - o->net->radius - this->boundary->collision_depth_right(o);
    }

    if ( this->boundary->collides_top(o) ) {
      o->velocity_y = -o->velocity_y;
      o->position_y = this->boundary->collision_depth_top(o) + o->net->radius;
    }

    if ( this->boundary->collides_bottom(o) ) {
      o->velocity_y = -o->velocity_y;
      o->position_y = this->boundary->height - o->net->radius - this->boundary->collision_depth_bottom(o);
    }

    // Check for other object collisions
    for (int j = 0; j < this->object_pool->num(); ++j) {
      if ( j != i ) {
        Object *other = this->object_pool->object(j);

        if ( o->collides_object(other) ) {
          std::cout << "object collision: " << i << " with " << j << std::endl;

          // Rewind until it doesn't collide
          double rewind_ms;
          for (rewind_ms = 0; rewind_ms < ms && o->collides_object(other); rewind_ms += ms/1000) {
            o->rewind_position(ms/1000);
            other->rewind_position(ms/1000);
          }

          // Based on http://www.gamasutra.com/view/feature/131424/pool_hall_lessons_fast_accurate_.php?page=3

          // Determine normalised vector d from centre of o to centre of other
          double v_x = other->position_x - o->position_x;
          double v_y = other->position_y - o->position_y;
          double d_x = v_x / modulus(v_x, v_y);
          double d_y = v_y / modulus(v_x, v_y);

          // Find component of both velocity vectors with d
          float a_1 = dot(d_x, d_y, o->velocity_x, o->velocity_y);
          float a_2 = dot(d_x, d_y, other->velocity_x, other->velocity_y);

          // Generate intermediate constant p
          float p = (2.0 * (a_1 - a_2)) / (o->mass + other->mass);

          // Compute new velocities
          o->velocity_x = o->velocity_x - p * other->mass * d_x;
          o->velocity_y = o->velocity_y - p * other->mass * d_y;
          other->velocity_x = other->velocity_x + p * o->mass * d_x;
          other->velocity_y = other->velocity_y + p * o->mass * d_y;

          // Fast forward to make up for the time we rewinded
          o->recalculate_position(ms - rewind_ms);
          other->recalculate_position(ms - rewind_ms);
        }
      }
    }
  }
}

std::vector<Object> *Map::objects() {
  return &this->object_pool->objects;
}

void Map::print_objects() {
  std::cout << "map [";

  for (int i = 0; i < this->object_pool->num(); ++i) {
    Object *o = this->object_pool->object(i);
    std::cout << "(" << o->position_x << ", " << o->position_y << ") ";
  }

  std::cout << "]" << std::endl;
}

int Map::draw(SDL_Renderer *ren) {
  this->boundary->draw(ren, 0, 0, 255, 255);

  std::vector<Object>::iterator o;
  for (o = this->objects()->begin() ; o != this->objects()->end(); o++ ) {
    int result = o->net->draw(ren, o->position_x, o->position_y, o->label);

    if ( 0 != result ) {
      return result;
    }
  }

  return 0;
}

Map::Map(Boundary *boundary) {
  this->boundary = new Boundary(*boundary);
  this->object_pool = new ObjectPool;
}

Map::~Map() {
  delete this->boundary;
  delete this->object_pool;
}
