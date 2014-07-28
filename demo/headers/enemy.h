#ifndef ENEMY_H
#define ENEMY_H
  bool  enemy_init(t_level_event_enemies *, t_SDL_objects *);
  bool  enemy_init_level_1(int, SDL_DisplayMode *, t_SDL_objects *);
  void  enemy_move(t_SDL_objects *);
#endif