#include <iostream>

#include <object.hpp>
#include <object_pool.hpp>

bool ObjectPool::add_object(Object *o) {
  if (this->num_objects < 1000) {
    this->objects[this->num_objects++] = new Object(*o);
    return true;
  } else {
    return false;
  }
}

unsigned int ObjectPool::num() {
  return this->num_objects;
}

Object *ObjectPool::object(unsigned int i) {
  return this->objects[i];
}

ObjectPool::ObjectPool() {
  this->num_objects = 0;
}
