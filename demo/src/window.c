#include        "../headers/main.h"
#include        "../headers/window.h"
#include        "../headers/renderer.h"

void            window_init(t_SDL_objects *SDL, void (*callback)())
{
  bool          opened;
  SDL_Event     event;

  SDL->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
  if (SDL->window != NULL)
  {
    opened = true;
    while (opened)
    {
      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
          opened = false;
        }
        if (opened == false)
        {
          break;
        }
      }
      renderer_init(SDL, callback);
    }
  }
  else
  {
    printf("Window error: %s\n", SDL_GetError());
    clear(SDL);
    exit(EXIT_FAILURE);
  }
}