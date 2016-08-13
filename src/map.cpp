#include <iostream>

#include <map.hpp>
#include <object_pool.hpp>

bool Map::add_object(Object *o) {
  return this->object_pool->add_object(o);
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
      o->position_x = this->boundary->collision_depth_left(o);
    }

    if ( this->boundary->collides_right(o) ) {
      o->velocity_x = -o->velocity_x;
      o->position_x = this->boundary->width - this->boundary->collision_depth_right(o);
    }

    if ( this->boundary->collides_top(o) ) {
      o->velocity_y = -o->velocity_y;
      o->position_y = this->boundary->collision_depth_top(o);
    }

    if ( this->boundary->collides_bottom(o) ) {
      o->velocity_y = -o->velocity_y;
      o->position_y = this->boundary->height - this->boundary->collision_depth_bottom(o);
    }

    // // Check for other object collisions
    // for (int j = 0; j < this->object_pool->num(); ++j) {
    //   if ( j != i ) {
    //     Object *other = this->object_pool->object(j);
    //
    //     if ( o->collides_object(other) ) {
    //       std::cout << "object collision: " << i << " with " << j << std::endl;
    //
    //       // TODO properly work out bounce direction
    //       double delta_x = other->position_x - this->position_x;
    //       double delta_y = other->position_y - this->position_y;
    //
    //
    //     }
    //   }
    // }
  }
}

void Map::print_objects() {
  std::cout << "map [";

  for (int i = 0; i < this->object_pool->num(); ++i) {
    Object *o = this->object_pool->object(i);
    std::cout << "(" << o->position_x << ", " << o->position_y << ") ";
  }

  std::cout << "]" << std::endl;
}

Map::Map(Boundary *boundary) {
  this->boundary = new Boundary(*boundary);
  this->object_pool = new ObjectPool;
}
