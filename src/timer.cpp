#include <SDL2/SDL.h>

#include <timer.hpp>

void Timer::start() {
  this->elapsed_ms = 0;
}

unsigned int Timer::stop() {
  unsigned int elapsed = this->elapsed_ms;
  this->elapsed_ms = 0;

  return elapsed;
}

unsigned int Timer::ms_since_last_frame() {
  return this->elapsed_ms - this->last_frame_ms;
}

void Timer::limit(unsigned int max_fps) {
  unsigned int min_ms_per_frame = 1000 / max_fps;
  this->tick();

  int to_wait_ms = min_ms_per_frame - ms_since_last_frame();
  if ( to_wait_ms > 0 ) {
    SDL_Delay(to_wait_ms);
  }
}

void Timer::tick() {
  this->last_frame_ms = this->elapsed_ms;
}

Timer::Timer() {
  this->elapsed_ms = 0;
  this->last_frame_ms = 0;
}
