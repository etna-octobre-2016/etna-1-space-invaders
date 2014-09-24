#ifndef ENEMY_H
#define ENEMY_H
  bool  enemy_init(t_SDL_objects *);
  bool  enemy_add(t_level_event_enemies *, t_SDL_objects *);
  bool  enemy_add_level_1(int, t_SDL_objects *);
  void  enemy_clear(t_SDL_objects *);
  void  enemy_move(t_SDL_objects *);
  void  enemy_shoot_launch(t_SDL_objects *);
#endif