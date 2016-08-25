#include <iostream>

#include <boundary.hpp>
#include <circle.hpp>
#include <graphics.hpp>
#include <map.hpp>
#include <object.hpp>
#include <rectangle.hpp>
#include <timer.hpp>

int main()
{
	Graphics *g = new Graphics;

	std::cout << "Welcome to motion..." << std::endl;

  Boundary *boundary = new Boundary(400, 400);

  Circle *c1 = new Circle(10);
  Circle *c2 = new Circle(30);
	Rectangle *r1 = new Rectangle(20, 20);

  Object *o1 = new Object(0, 0, 0, 0, 1, c1, nullptr);
  Object *o2 = new Object(0, 2, 0, 0, 1, c2, nullptr);

  std::cout << "o1 collides with o2? " << o1->collides_object(o2) << std::endl;

  std::cout << "o1 collides with boundary? " << boundary->collides(o1) << std::endl;
  std::cout << "o2 collides with boundary? " << boundary->collides(o2) << std::endl;

  Map *map = new Map(boundary);

	Label *l1 = new Label(255, 0, 0, 255, "ball 1");
	Label *l2 = new Label(0, 255, 0, 255, "ball 2");
	Label *l3 = new Label(0, 0, 255, 255, "square");

  Object *moving = new Object(3, 50, 100, 200, 1, c1, l1);
  Object *solid = new Object(60, 50, -300, 20, 1, c2, l2);
	//Object *square = new Object(100, 100, -40, -40, 1, r1, l3);

  map->add_object(moving);
  map->add_object(solid);
	//map->add_object(square);

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
