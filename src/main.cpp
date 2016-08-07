#include <iostream>

#include <circle.hpp>

int main()
{
	std::cout << "Welcome to motion..." << std::endl;

  Circle *c1 = new Circle(0.0, 0.0, 1.0);
  Circle *c2 = new Circle(2.0, 2.0, 1.9);

  std::cout << "c1 collides with c2? " << c1->collides(c2) << std::endl;

	return 0;
}
