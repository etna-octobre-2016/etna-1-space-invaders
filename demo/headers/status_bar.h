#ifndef STATUS_BAR_H
#define STATUS_BAR_H
  bool 		status_bar_init(t_SDL_objects *SDL);
  void  	status_bar_update_life(t_SDL_objects *SDL);
  void 		status_bar_update_scores(t_SDL_objects *SDL);
  void 		status_bar_clear_scores(t_SDL_objects *SDL);
#endif