#ifndef included_timer_hpp
#define included_timer_hpp

class Timer {
  unsigned int start_ms;
  unsigned int last_frame_ms;

private:
  long long int ms_since_epoch();

public:
  // Start the timer.
  void start();

  // Stop the timer, returning the total time in ms.
  unsigned int stop();

  // Return elapsed milliseconds.
  unsigned int elapsed_ms();

  // Return the time since the last frame.
  unsigned int ms_since_last_frame();

  // Return elapsed seconds.
  unsigned int seconds();

  // Limit to a max framerate by sleeping, returning ms slept.
  void limit(unsigned int max_fps);

  // Signal that a frame has been rendered (no fps limiting).
  void tick();

  // Instantiate a new timer.
  Timer();
};

#endif // included_timer_hpp
