#include              "../headers/renderer.h"

void                  renderer_init(SDL_Window *window, void (*callback)())
{
  static bool         isRenderer = false;
  static SDL_Renderer *renderer;

  if (isRenderer)
  {
    callback(window, renderer);
  }
  else
  {
    renderer = SDL_CreateRenderer(window, -1, RENDERER_FLAGS);
    if (renderer != NULL)
    {
        isRenderer = true;
        callback(window, renderer);
    }
    else
    {
        printf("Renderer error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
  }
}