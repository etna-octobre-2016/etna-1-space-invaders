#ifndef WINDOW_H
#define WINDOW_H
  #include  <stdio.h>
  #include  <stdbool.h>
  #include  <SDL2.framework/Headers/SDL.h>
  #include  "renderer.h"

  #define   WINDOW_TITLE    ""
  #define   WINDOW_HEIGHT   0
  #define   WINDOW_WIDTH    0
  #define   WINDOW_POS_X    SDL_WINDOWPOS_UNDEFINED
  #define   WINDOW_POS_Y    SDL_WINDOWPOS_UNDEFINED
  #define   WINDOW_FLAGS    SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED

  void      window_init(void (*)());
#endif