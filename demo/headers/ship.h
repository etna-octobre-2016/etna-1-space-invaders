#ifndef SHIP_H
#define SHIP_H
  #define SHIP_MAX_LIFE 100

  bool    ship_init();
  void    ship_clear(t_SDL_objects *);
  void    ship_move(t_SDL_objects *);
  void    ship_draw(t_SDL_objects *);
#endif