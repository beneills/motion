#ifndef included_map_hpp
#define included_map_hpp

#include <boundary.hpp>
#include <object_pool.hpp>

class Map {
  Boundary *boundary;
  ObjectPool *object_pool;

public:
  // Add an object to the map.
  bool add_object(Object *o);

  // Update object positions, given time.
  void update(double ms);

  // Objects vector.
  std::vector<Object> *objects();

  // Pretty print all objects.
  void print_objects();

  // Instantiate a map.
  Map(Boundary *boundary);
};

#endif // included_map_hpp
