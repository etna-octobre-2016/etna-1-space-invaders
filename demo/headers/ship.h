#ifndef SHIP_H
#define SHIP_H

  #define SHIP_MAX_LIFE 100
  #define SHIP_STATE_UNDEFINED 0
  #define SHIP_STATE_NORMAL 1
  #define SHIP_STATE_CRASH 2

  bool    ship_init();
  void    ship_clear(t_SDL_objects *);
  void    ship_move(t_SDL_objects *);
  void    ship_draw(t_SDL_objects *SDL);
  bool    ship_is_crashed(t_SDL_objects *SDL);
  void    ship_update_life(t_SDL_objects *SDL, int number);
  bool    ship_is_alive(t_SDL_objects *SDL);
  void    ship_update_image(t_SDL_objects *SDL);

#endif