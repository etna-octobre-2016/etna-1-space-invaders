#ifndef ANIMATION_H
#define ANIMATION_H
  bool        animation_init(t_SDL_objects *);
  void        animation_add(t_animation *, t_animation *);
  t_animation *animation_get(int, t_SDL_objects *);
#endif