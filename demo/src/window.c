#include  "../headers/window.h"

bool      window_init(t_SDL_objects *SDL)
{
  SDL->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
  if (SDL->window != NULL)
  {
    return true;
  }
  else
  {
    printf("Window error: %s\n", SDL_GetError());
    return false;
  }
}