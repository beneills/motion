#include <iostream>

#include <net.hpp>

bool Net::possibly_collides(Net *other) {
  return ( this->min_x() <= other->max_x() )
  && ( this->max_x() >= other->min_x() )
  && ( this->min_y() <= other->max_y() )
  && ( this->max_y() >= other->min_y() );
}
