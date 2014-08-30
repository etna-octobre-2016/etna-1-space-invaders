#ifndef ANIMATION_H
#define ANIMATION_H
  bool  		animation_init(t_SDL_objects *);
  void 			animation_list_add_end(t_SDL_objects *SDL, t_animation *animation);
  t_animation 	*animation_get(t_SDL_objects *SDL, int state);
  void          animation_clear(t_SDL_objects *SDL);

#endif