#include      "../headers/main.h"

int           main()
{
  SDL_Window  *window;

  window = NULL;
  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    if (window_init(window))
    {
      window_while_opened(callback_window_opened);
      window_destroy(window);
      exit(EXIT_SUCCESS);
    }
    else
    {
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    printf("Error SDL init: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void          callback_window_opened()
{

}