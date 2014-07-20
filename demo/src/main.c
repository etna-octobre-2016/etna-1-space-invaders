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
        init_ship(SDL);
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
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
  SDL_Quit();
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
        move_ship(event.key.keysym.sym, SDL);
      }
      if (opened == false)
      {
        break;
      }
    }
    print_ship(SDL);
    SDL_Delay(FRAMES_PER_SECOND);
  }
  printf("win closed = %s\n", SDL_GetWindowTitle(SDL->window));
}