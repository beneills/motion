#ifndef included_labeling_hpp
#define included_labeling_hpp

#include <iostream>
#include <SDL2/SDL.h>

class Label {
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
  std::string label;

public:
  // Return the color encoded as a 32-bit int.
  Uint32 color();

  // Instantiate a new label with color and text string.
  Label(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string label);
};

#endif // included_labeling_hpp
