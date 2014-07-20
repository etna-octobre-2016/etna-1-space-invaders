#include            "../headers/main.h"

int                 main()
{
  bool              error;
  t_SDL_objects     SDL;

  error = false;
  if (init(&SDL) == true)
  {
    listen_events(&SDL);
  }
  else
  {
    error = true;
  }
  clear(&SDL);
  if (error == true)
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    exit(EXIT_SUCCESS);
  }
}

bool                init(t_SDL_objects *SDL)
{
  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    if (window_init(SDL) == true)
    {
      if (renderer_init(SDL) == true)
      {
        if (ship_init(SDL) == true)
        {
          if (enemy_init(SDL) == true)
          {
            return true;
          }
        }
      }
    }
    return false;
  }
  else
  {
    printf("SDL init error: %s\n", SDL_GetError());
    return false;
  }
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
  if (SDL->enemy->image != NULL)
  {
    SDL_FreeSurface(SDL->enemy->image);
  }
  free(SDL->ship);
  free(SDL->enemy);
  SDL_Quit();
}

void                draw(t_SDL_objects *SDL)
{
  SDL_RenderClear(SDL->renderer);
  ship_draw(SDL);
  enemy_draw(SDL);
  SDL_RenderPresent(SDL->renderer);
}

void                listen_events(t_SDL_objects *SDL)
{
  bool              opened;
  SDL_Event         event;

  opened = true;
  while (opened)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
      {
        opened = false;
      }
      if (event.type == SDL_KEYDOWN)
      {
        ship_move(event.key.keysym.sym, SDL);
      }
      if (opened == false)
      {
        break;
      }
    }
    draw(SDL);
    SDL_Delay(FRAMES_PER_SECOND);
  }
}