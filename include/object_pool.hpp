#ifndef included_object_pool_hpp
#define included_object_pool_hpp

#include <object.hpp>

#define MAX_OBJECTS 1000

class ObjectPool {
  unsigned int num_objects;
  Object *objects[MAX_OBJECTS];

public:
  // Add an object to the pool.
  bool add_object(Object *o);

  // Number of objects.
  unsigned int num();

  // Access an object.
  Object *object(unsigned int i);

  // Instantiate a new object pool.
  ObjectPool();
};

#endif // included_object_pool_hpp
