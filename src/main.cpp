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

  Boundary *boundary = new Boundary(150, 60);

  Circle *c1 = new Circle(25);
  Circle *c2 = new Circle(25);

	Label *l1 = new Label(255, 0, 0, 255, "ball 1");
	Label *l2 = new Label(0, 255, 0, 255, "ball 2");

  Object *ball1 = new Object(30, 30, 20, 0, 1, c1, l1);
  Object *ball2 = new Object(100, 30, -20, 0, 1, c2, l2);

	Map *map = new Map(boundary);

  map->add_object(ball1);
  map->add_object(ball2);

	int max_fps = 20;
	Timer *t = new Timer;

	t->start();
	while (t->seconds() < 5) {
		g->render(map);
		map->update(t->ms_since_last_frame());
		t->limit(max_fps);
  }
	t->stop();

	delete t;
	delete map;
	delete l1;
	delete l2;
	delete c1;
	delete c2;

	return 0;
}
