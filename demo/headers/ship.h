#ifndef SHIP_H
#define SHIP_H
	#include            "main.h"
  bool  ship_init();
  void  ship_clear(t_SDL_objects *);
  void  ship_move(int direction, t_SDL_objects *);
  void  ship_draw(t_SDL_objects *);
  void	ship_move2(t_SDL_objects *);
#endif