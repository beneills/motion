#ifndef included_object_pool_hpp
#define included_object_pool_hpp

#include <vector>

#include <object.hpp>

class ObjectPool {
public:
  std::vector<Object> objects;

public:
  // Add an object to the pool.
  void add_object(Object *o);

  // Number of objects.
  unsigned int num();

  // Access an object.
  Object *object(unsigned int i);
};

#endif // included_object_pool_hpp
