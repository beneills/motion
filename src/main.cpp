#include <iostream>

#include <boundary.hpp>
#include <circle.hpp>
#include <graphics.hpp>
#include <map.hpp>
#include <object.hpp>

int main()
{
	// Graphics *g = new Graphics;
	// g->demo();
	// delete g;

	std::cout << "Welcome to motion..." << std::endl;

  Boundary *boundary = new Boundary(100, 100);

  Circle *c1 = new Circle(1.0);
  Circle *c2 = new Circle(1.1);

  Object *o1 = new Object(0, 0, 0, 0, 1, c1);
  Object *o2 = new Object(0, 2, 0, 0, 1, c2);

  std::cout << "o1 collides with o2? " << o1->collides_object(o2) << std::endl;

  std::cout << "o1 collides with boundary? " << boundary->collides(o1) << std::endl;
  std::cout << "o2 collides with boundary? " << boundary->collides(o2) << std::endl;

  Map *map = new Map(boundary);

  Object *moving = new Object(3, 3, 1, 0, 1, c1);
  Object *solid = new Object(60, 3, 0, 0, 1, c1);

  map->add_object(moving);
  map->add_object(solid);

  for (int time = 0; time < 1000; time += 10) {
    map->print_objects();
    map->update(10);
  }

	return 0;
}
