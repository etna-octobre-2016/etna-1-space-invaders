#ifndef ENEMY_H
#define ENEMY_H
  bool  enemy_init(t_SDL_objects *);
  void  enemy_move(t_SDL_objects *);
  int   enemy_get_random_y_pos(int, int);
#endif