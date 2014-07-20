#ifndef MAIN_H
#define MAIN_H

  #include  "includes.h"
  #include  "structures.h"
  #include  "window.h"
  #include  "renderer.h"
  #include  "ship.h"

  #define   FRAMES_PER_SECOND 100

  bool      init(t_SDL_objects *);
  void      clear(t_SDL_objects *);
  void      listen_events(t_SDL_objects *);
#endif