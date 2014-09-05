#include            "../headers/main.h"

int                 main()
{
  t_SDL_objects     SDL;

  srand(time(NULL));
  if (init(&SDL) == true)
  {
    printf("Initialisation principale : ok\n");
    listen_events(&SDL);
    printf("Traitement des évênements : ok\n");
    clear(&SDL);
    printf("clear géneral: ok\n");
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
    printf("SDL_Init : ok\n");
    if (window_init(SDL) == true)
    {
      printf("window_init : ok\n");
      if (renderer_init(SDL) == true)
      {
        printf("renderer_init : ok\n");
        if (animation_init(SDL) == true)
        {
          printf("animation_init : ok\n");
          if (ship_init(SDL) == true)
          {
            printf("ship_init : ok\n");
            if (level_init(1, SDL) == true)
            {
              printf("level_init : ok\n");
              if (enemy_init(SDL) == true)
              {
                printf("enemy_init : ok\n");
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
  animation_clear(SDL);
  printf("animation_clear : ok\n");
  ship_clear(SDL);
  printf("ship_clear : ok\n");
  enemy_clear(SDL);
  printf("enemy_clear : ok\n");
  if (SDL->renderer != NULL)
  {
    SDL_DestroyRenderer(SDL->renderer);
    printf("SDL_renderer clear : ok\n");
  }
  if (SDL->window != NULL)
  {
    SDL_DestroyWindow(SDL->window);
    printf("SDL_window clear : ok\n");
  }
  SDL_Quit();
  printf("SDL_Quit clear : ok\n");
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
    printf("Fenêtre ouverte !\n");
   /*SDL_PollEvent segfault...*/
    while (SDL_PollEvent(&event))
    {
      printf("On attend un évênement !\n");
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

    printf("On traite le jeu\n");
    currentTime = SDL_GetTicks();
    timeDiff = (currentTime - previousTime);
    if (timeDiff > MAX_TIME_DIFF(FRAMES_PER_SECOND)) /* Code exécuté à la fréquence de FRAMES_PER_SECOND */
    {
      SDL_RenderClear(SDL->renderer);
      game_loop(SDL);
      printf("Game Loop\n");
      if (!ship_is_in_life(SDL))
        opened = false;
      printf("On a regardé si le vaisseau était en vie\n");
      SDL_RenderPresent(SDL->renderer);
      previousTime = currentTime;
    }
    else
    {
      SDL_Delay(MAX_TIME_DIFF(FRAMES_PER_SECOND) - timeDiff);
    }
  }
}