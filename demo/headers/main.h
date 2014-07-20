#ifndef MAIN_H
#define MAIN_H

  #include  "includes.h"
  #include  "structures.h"
  #include  "window.h"
  #include  "renderer.h"
  #include  "ship.h"
  #include  "enemy.h"
  #include  "moves.h"

  #define   FRAMES_PER_SECOND 12
  #define   MAX_TIME_DIFF(FRAMES_PER_SECOND) (1000 / FRAMES_PER_SECOND)

  bool      init(t_SDL_objects *);
  void      clear(t_SDL_objects *);
  void      game_loop(t_SDL_objects *);
  void      listen_events(t_SDL_objects *);
#endif