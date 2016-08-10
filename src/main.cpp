#include <iostream>

#include <boundary.hpp>
#include <circle.hpp>
#include <object.hpp>

int main()
{
	std::cout << "Welcome to motion..." << std::endl;

  Boundary *boundary = new Boundary(100, 100);

  Circle *c1 = new Circle(1.0);
  Circle *c2 = new Circle(1.1);

  Object *o1 = new Object(0, 0, 0, 0, 1, c1);
  Object *o2 = new Object(0, 2, 0, 0, 1, c2);

  std::cout << "o1 collides with o2? " << o1->collides_object(o2) << std::endl;

  std::cout << "o1 collides with boundary? " << boundary->collides(o1) << std::endl;
  std::cout << "o2 collides with boundary? " << boundary->collides(o2) << std::endl;

  Object *moving = new Object(0, 0, 1, 0, 1, c1);

  std::cout << "moving position: " << moving->position_x << std::endl;

  moving->recalculate_position(50);

  std::cout << "moving position: " << moving->position_x << std::endl;

	return 0;
}
