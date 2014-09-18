#ifndef BACKGROUND_H
#define BACKGROUND_H
  bool  background_init(t_SDL_objects *);
  void  background_clear(t_SDL_objects *);
  void  background_draw(t_SDL_objects *SDL);
  void 	background_draw_left(t_SDL_objects *SDL);
  void 	background_draw_right(t_SDL_objects *SDL);
#endif