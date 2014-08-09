#include  "../headers/main.h"

bool      renderer_init(t_SDL_objects *SDL)
{
  SDL->renderer = SDL_CreateRenderer(SDL->window, -1, RENDERER_FLAGS);
  if (SDL->renderer != NULL)
  {
    return true;
  }
  else
  {
    printf("Renderer error: %s\n", SDL_GetError());
    return false;
  }
}