#ifndef MAIN_H
#define MAIN_H

  #include  "includes.h"
  #include  "structures.h"
  #include  "window.h"
  #include  "renderer.h"
  #include  "ship.h"
  #include  "enemy.h"
  #include  "moves.h"
  #include  "level.h"
  #include  "event.h"
  #include  "status_bar.h"

  #define   FRAMES_PER_SECOND 14
  #define   MAX_TIME_DIFF(FRAMES_PER_SECOND) (1000 / FRAMES_PER_SECOND)
  #define   RAND_RANGE(min, max) ((rand() % (max - (min + 1))) + min)

  bool      init(t_SDL_objects *);
  void      clear(t_SDL_objects *);
  void      game_loop(t_SDL_objects *);
  void      listen_events(t_SDL_objects *);
#endif