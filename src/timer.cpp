#include <assert.h>
#include <iostream>
#include <sys/time.h>
#include <SDL2/SDL.h>

#include <timer.hpp>

long long int Timer::ms_since_epoch() {
  struct timeval tp;
  gettimeofday(&tp, NULL);

  return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

void Timer::start() {
  assert( this->start_ms == -1 );

  this->start_ms = this->ms_since_epoch();
}

unsigned int Timer::stop() {
  assert( this->start_ms != -1 );

  unsigned int elapsed = this->elapsed_ms();
  this->start_ms = -1;

  return elapsed;
}

unsigned int Timer::elapsed_ms() {
  assert( this->start_ms != -1 );

  return this->ms_since_epoch() - this->start_ms;
}

unsigned int Timer::ms_since_last_frame() {
  assert( this->start_ms != -1 );

  return this->elapsed_ms() - this->last_frame_ms;
}

unsigned int Timer::seconds() {
    return this->elapsed_ms() / 1000;
}


void Timer::limit(unsigned int max_fps) {
  assert( this->start_ms != -1 );

  unsigned int min_ms_per_frame = 1000 / max_fps;
  this->tick();

  int to_wait_ms = min_ms_per_frame - ms_since_last_frame();
  if ( to_wait_ms > 0 ) {
    SDL_Delay(to_wait_ms);
  }
}

void Timer::tick() {
  this->last_frame_ms = this->elapsed_ms();
}

Timer::Timer() {
  this->start_ms = -1;
  this->last_frame_ms = -1;
}
