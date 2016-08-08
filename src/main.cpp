#include <iostream>

#include <circle.hpp>
#include <object.hpp>

int main()
{
	std::cout << "Welcome to motion..." << std::endl;

  Circle *c1 = new Circle(1.0);
  Circle *c2 = new Circle(1.1);

  Object *o1 = new Object(0, 0, 0, 0, 1, c1);
  Object *o2 = new Object(0, 2, 0, 0, 1, c2);

  std::cout << "o1 collides with o2? " << o1->collides(o2) << std::endl;

	return 0;
}
