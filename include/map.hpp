#ifndef included_map_hpp
#define included_map_hpp

#include <SDL2/SDL2_gfxPrimitives.h>

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

  // Draw the map to an SDL renderer.
  int draw(SDL_Renderer *ren);

  // Instantiate a map.
  Map(Boundary *boundary);
};

#endif // included_map_hpp
