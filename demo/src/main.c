#include            "../headers/main.h"

int                 main()
{
  t_SDL_objects     SDL;

  srand(time(NULL));
  if (init(&SDL) == true)
  {
    listen_events(&SDL);
    clear(&SDL);
    exit(EXIT_SUCCESS);
  }
  else
  {
    clear(&SDL);
    exit(EXIT_FAILURE);
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
        if (animation_init(SDL) == true)
        {
          if (ship_init(SDL) == true)
          {
            if (level_init(1, SDL) == true)
            {
              if (enemy_init(SDL) == true)
              {
                  return true;
              }
            }
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
  ship_clear(SDL);
  enemy_clear(SDL);
  animation_clear(SDL);
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

void                game_loop(t_SDL_objects *SDL)
{
  bool              eventTriggered;
  int               i;
  Uint32            timestamp;

  eventTriggered = false;
  timestamp = SDL_GetTicks();
  for (i = 0; !eventTriggered && i < SDL->level->eventsCount; i++)
  {
    if (SDL->level->events[i]->triggered == false && timestamp > SDL->level->events[i]->timestamp)
    {
      switch (SDL->level->events[i]->type)
      {
        case 'E':
          enemy_add(&SDL->level->events[i]->enemies, SDL);
          eventTriggered = true;
          break;
      }
      if (eventTriggered == true)
      {
        SDL->level->events[i]->triggered = true;
      }
    }
  }
  ship_is_crashed(SDL);
  ship_draw(SDL);
  enemy_move(SDL);
}

void                listen_events(t_SDL_objects *SDL)
{
  bool              opened;
  Uint32            currentTime;
  Uint32            previousTime;
  Uint32            timeDiff;
  SDL_Event         event;

  opened = true;
  previousTime = 0;
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
    currentTime = SDL_GetTicks();
    timeDiff = (currentTime - previousTime);
    if (timeDiff > MAX_TIME_DIFF(FRAMES_PER_SECOND)) /* Code exécuté à la fréquence de FRAMES_PER_SECOND */
    {
      SDL_RenderClear(SDL->renderer);
      game_loop(SDL);
      if (!ship_is_in_life(SDL))
        opened = false;
      SDL_RenderPresent(SDL->renderer);
      previousTime = currentTime;
    }
    else
    {
      SDL_Delay(MAX_TIME_DIFF(FRAMES_PER_SECOND) - timeDiff);
    }
  }
}