#ifndef SHIP_H
#define SHIP_H

  #include        "includes.h"
  #include        "structures.h"

  void	init_ship();
  void	move_ship(int direction, t_SDL_objects *SDL);
  void  print_ship(t_SDL_objects *SDL);

#endif