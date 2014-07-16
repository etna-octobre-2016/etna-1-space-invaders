#include            "../headers/main.h"
#include            "../headers/window.h"

int                 main()
{
  t_SDL_objects     SDL;

  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    window_init(&SDL, &init_success);
    clear(&SDL);
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("SDL init error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void                init_success(t_SDL_objects *SDL)
{
  SDL_RendererInfo  renderer_info;

  printf("voici mon code une fois que tout est bon\n");
  printf("title = %s\n", SDL_GetWindowTitle(SDL->window));

  if (SDL_GetRendererInfo(SDL->renderer, &renderer_info) == 0)
    printf("renderer = %s\n", renderer_info.name);
  else
    printf("error: %s\n", SDL_GetError());
}

void                clear(t_SDL_objects *SDL)
{
  if (SDL->renderer != NULL)
  {
    SDL_DestroyRenderer(SDL->renderer);
  }
  if (SDL->window != NULL)
  {
    SDL_DestroyWindow(SDL->window);
  }
  SDL_Quit();
}