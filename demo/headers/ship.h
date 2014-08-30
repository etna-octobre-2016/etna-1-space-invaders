#ifndef SHIP_H
#define SHIP_H
  bool  ship_init();
  void  ship_clear(t_SDL_objects *);
  void  ship_move(int direction, t_SDL_objects *);
  void  ship_draw(t_SDL_objects *SDL);
  bool  ship_is_crash(t_SDL_objects *SDL);
  void  ship_update_life(t_SDL_objects *SDL, int number);
  bool  ship_is_in_life(t_SDL_objects *SDL);
  void  ship_update_image(t_SDL_objects *SDL);

#endif