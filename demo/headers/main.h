#ifndef MAIN_H
#define MAIN_H
  #include        "includes.h"

  typedef         struct
  {
    SDL_Window    *window;
    SDL_Renderer  *renderer;

  }               t_SDL_objects;

  bool            init(t_SDL_objects *);
  void            clear(t_SDL_objects *);
  void            listen_events(t_SDL_objects *);
#endif