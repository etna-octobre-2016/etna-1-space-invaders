#ifndef WINDOW_H
#define WINDOW_H
  #include  <stdio.h>
  #include  <stdbool.h>
  #include  <SDL2.framework/Headers/SDL.h>

  #define   WINDOW_TITLE    "Ma fenetre de ouf"
  #define   WINDOW_HEIGHT   400
  #define   WINDOW_WIDTH    400
  #define   WINDOW_POS_X    SDL_WINDOWPOS_UNDEFINED
  #define   WINDOW_POS_Y    SDL_WINDOWPOS_UNDEFINED
  #define   WINDOW_FLAGS    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

  void      window_destroy(SDL_Window *);
  bool      window_init(SDL_Window *);
  void      window_while_opened(void (*)());
#endif