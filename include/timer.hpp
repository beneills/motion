#ifndef included_timer_hpp
#define included_timer_hpp

class Timer {
  unsigned int elapsed_ms;
  unsigned int last_frame_ms;

public:
  // Start the timer.
  void start();

  // Stop the timer, returning the total time in ms.
  unsigned int stop();

  // Return the time since the last frame.
  unsigned int ms_since_last_frame();

  // Limit to a max framerate by sleeping.
  void limit(unsigned int max_fps);

  // Signal that a frame has been rendered (no fps limiting).
  void tick();

  // Instantiate a new timer.
  Timer();
};

#endif // included_timer_hpp
