#include      "../headers/renderer.h"

void          renderer_init(t_SDL_objects *SDL, void (*callback)())
{
  static bool isRenderer = false;

  if (isRenderer)
  {
    callback(SDL);
  }
  else
  {
    SDL->renderer = SDL_CreateRenderer(SDL->window, -1, RENDERER_FLAGS);
    if (SDL->renderer != NULL)
    {
        isRenderer = true;
        callback(SDL);
    }
    else
    {
        printf("Renderer error: %s\n", SDL_GetError());
        SDL_DestroyWindow(SDL->window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
  }
}