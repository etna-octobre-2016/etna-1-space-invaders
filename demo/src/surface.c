#include      "../headers/main.h"
#include      "../headers/surface.h"

void          surface_init(t_SDL_objects *SDL, void (*callback)())
{
  SDL->surface = SDL_GetWindowSurface(SDL->window);
  if (SDL->surface != NULL)
  {
    callback(SDL);
  }
  else
  {
    printf("Surface error: %s\n", SDL_GetError());
    clear(SDL);
    exit(EXIT_FAILURE);
  }
}