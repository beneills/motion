#include <iostream>

#include <boundary.hpp>
#include <circle.hpp>
#include <graphics.hpp>
#include <map.hpp>
#include <object.hpp>
#include <timer.hpp>

int main()
{
	Graphics *g = new Graphics;

	std::cout << "Welcome to motion..." << std::endl;

  Boundary *boundary = new Boundary(100, 100);

  Circle *c1 = new Circle(10);
  Circle *c2 = new Circle(30);

  Object *o1 = new Object(0, 0, 0, 0, 1, c1);
  Object *o2 = new Object(0, 2, 0, 0, 1, c2);

  std::cout << "o1 collides with o2? " << o1->collides_object(o2) << std::endl;

  std::cout << "o1 collides with boundary? " << boundary->collides(o1) << std::endl;
  std::cout << "o2 collides with boundary? " << boundary->collides(o2) << std::endl;

  Map *map = new Map(boundary);

  Object *moving = new Object(3, 50, 1, 1, 1, c1);
  Object *solid = new Object(60, 50, 0, 0, 1, c2);

  map->add_object(moving);
  map->add_object(solid);

	int max_fps = 20;
	Timer *t = new Timer;

	t->start();
	while (t->seconds() < 5) {
		g->render(map);
		map->update(t->ms_since_last_frame());
		t->limit(max_fps);
  }
	t->stop();

	return 0;
}
