#include <iostream>

#include <object.hpp>
#include <object_pool.hpp>

void ObjectPool::add_object(Object *o) {
  this->objects.push_back(*o);
}

unsigned int ObjectPool::num() {
  return this->objects.size();
}

Object *ObjectPool::object(unsigned int i) {
  return &this->objects[i];
}
