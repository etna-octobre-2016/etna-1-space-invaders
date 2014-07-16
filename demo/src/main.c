#include            "../headers/main.h"
#include            "../headers/window.h"

int                 main()
{
  t_SDL_objects     SDL;

  init_ship(&SDL);

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
  SDL_Rect pos;
  SDL_Texture *texture;

  pos.x = SDL->ship->x;
  pos.y = SDL->ship->y;
  pos.w = SDL->ship->width;
  pos.h = SDL->ship->height;

  SDL_RenderClear(SDL->renderer);

  texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->ship->image);
  if (texture < 0)
  {
    printf("Texture non chargée");
    exit(EXIT_FAILURE);
  }
  if (SDL_RenderCopy(SDL->renderer, texture, NULL, &pos) < 0)
  {
    printf("RenderCopy non chargée");
    exit(EXIT_FAILURE);
  }


  SDL_Event     event;
  SDL_PollEvent(&event);

  if (event.type == SDL_KEYDOWN)
  {
    move(event.key.keysym.sym, SDL);
  }

  SDL_RenderPresent(SDL->renderer);
  /*Fin*/

  
  /*printf("voici mon code une fois que tout est bon\n");
  printf("title = %s\n", SDL_GetWindowTitle(SDL->window));*/
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
  if (SDL->ship->image != NULL)
  {
    SDL_FreeSurface(SDL->ship->image);
  }
  SDL_Quit();
}