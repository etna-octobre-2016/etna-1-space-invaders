#ifndef MAIN_H
#define MAIN_H
  #include        "includes.h"

  typedef         struct
  {
    SDL_Window    *window;
    SDL_Surface   *surface;

  }               t_SDL_objects;

  void            clear(t_SDL_objects *);
  void            init_success(t_SDL_objects *);
#endif