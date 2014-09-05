#ifndef SHIP_H
#define SHIP_H
  bool  ship_init();
  void  ship_clear(t_SDL_objects *);
  void  ship_move(int direction, t_SDL_objects *);
  void  ship_draw(t_SDL_objects *);
  void  ship_update_bar(t_SDL_objects *SDL);
#endif