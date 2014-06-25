#include  "../headers/window.h"

bool      window_init(SDL_Window *window)
{
  window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
  if (window != NULL)
  {
    return true;
  }
  else
  {
    printf("Window error: %s\n", SDL_GetError());
    return false;
  }
}

void      window_while_opened(void (*callback)())
{
  bool        opened;
  SDL_Event   event;

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
    callback();
  }
}

void      window_destroy(SDL_Window *window)
{
  SDL_DestroyWindow(window);
}
