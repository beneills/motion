#define ASSERT(p) if (!(p)) { return 1; } else { std::cout << "checking " << #p << std::endl; }
#define RUN_TEST(t) if (t()) { std::cout << "FAILED: " << #t << std::endl; return 1; } else { std::cout << "PASSED: " << #t << std::endl; }

#include <iostream>

#include <circle.hpp>


int test_circle() {
  Circle *c1 = new Circle(0.0, 0.0, 1.0);
  Circle *c2 = new Circle(2.0, 0.0, 1.1);
  Circle *c3 = new Circle(2.0, 0.0, 0.9);

  ASSERT( c1->collides(c2) );
  ASSERT( !c1->collides(c3) );

  return 0;
}

int run_tests()
{
	std::cout << "Testing motion..." << std::endl;

  RUN_TEST( test_circle );

	return 0;
}

int main()
{
  int result = run_tests();

  std::cout << "====================" << std::endl;

  if ( 0 != result ) {
    std::cout << "Some test failed." << std::endl;
  } else {
    std::cout << "All tests passed." << std::endl;
  }

  return result;
}
