#include  "../headers/main.h"

int       main()
{
  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    window_init(&init_success);
    SDL_Quit();
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("SDL init error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void      init_success(SDL_Window *window, SDL_Renderer *renderer)
{
  SDL_RendererInfo renderer_info;

  printf("voici mon code une fois que tout est bon\n");
  printf("title = %s\n", SDL_GetWindowTitle(window));

  if (SDL_GetRendererInfo(renderer, &renderer_info) == 0)
    printf("renderer = %s\n", renderer_info.name);
  else
    printf("error: %s\n", SDL_GetError());
}