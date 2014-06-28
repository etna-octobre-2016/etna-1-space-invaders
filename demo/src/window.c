#include      "../headers/window.h"

void          window_init(void (*callback)())
{
  bool        opened;
  SDL_Event   event;
  SDL_Window  *window;

  window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
  if (window != NULL)
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
      renderer_init(window, callback);
    }
    SDL_DestroyWindow(window);
  }
  else
  {
    printf("Window error: %s\n", SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
  }
}