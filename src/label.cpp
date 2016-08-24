#include <label.hpp>

Uint32 Label::color() {
   return ( this->r << 0 )
        + ( this->g << 8 )
        + ( this->b << 16 )
        + ( this->a << 24 );
}

Label::Label(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string label) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  this->label = label;
}
