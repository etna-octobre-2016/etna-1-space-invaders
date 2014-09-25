#include            "../headers/main.h"

int                 main()
{
  t_SDL_objects     SDL;

  srand(time(NULL));
  if (init(&SDL) == true)
  {
    main_loop(&SDL);
    /*clear(&SDL);*/
    exit(EXIT_SUCCESS);
  }
  else
  {
    /*clear(&SDL);*/
    exit(EXIT_FAILURE);
  }
}

/**
 * Fonction d'initialisation du programme
 * @param   {t_SDL_objects} SDL la structure principale du programme
 * @return  {bool} renvoie true en cas de succès, ou false en cas d'erreur
 */
bool                init(t_SDL_objects *SDL)
{
  int               init_sdl;
  int               init_ttf;

  init_sdl = SDL_Init(SDL_INIT_VIDEO);
  init_ttf = TTF_Init();
  if (
    init_sdl == 0
    && init_ttf == 0
    && window_init(SDL) == true
    && renderer_init(SDL) == true
    && background_init(SDL) == true
    && audio_init(SDL) == true
    && animation_init(SDL) == true
    && ship_init(SDL) == true
    && level_init(1, SDL) == true
    && enemy_init(SDL) == true
    && status_bar_init(SDL) == true
  ){
    return true;
  }
  else
  {
    if (init_sdl < 0)
    {
      printf("SDL_Init error: %s\n", SDL_GetError());
    }
    if (init_ttf < 0)
    {
      printf("TTF_Init error: %s\n", TTF_GetError());
    }
    puts("an error occured during initialization");
    return false;
  }
}

/**
 * Fonction de nettoyage du programme
 * @param {t_SDL_objects}  SDL la structure principale du programme
 */
/*void                clear(t_SDL_objects *SDL)
{
  status_bar_clear_scores(SDL);
  animation_clear(SDL);
  ship_clear(SDL);
  enemy_clear(SDL);
<<<<<<< HEAD
  events_clear();
=======
  background_clear(SDL);
  audio_clear(SDL);
>>>>>>> background_music
  if (SDL->renderer != NULL)
  {
    SDL_DestroyRenderer(SDL->renderer);
  }
  if (SDL->window != NULL)
  {
    SDL_DestroyWindow(SDL->window);
  }
  TTF_Quit();
  SDL_Quit();
}*/

/**
 * Fonction principale appellée à la fréquence de FRAMES_PER_SECOND images/seconde (cf. main.h)
 * @param {t_SDL_objects}  SDL la structure principale du programme
 *
 * @note: C'est dans cette fonction que le code du jeu sera executé
 */
void                game_loop(t_SDL_objects *SDL)
{
  bool              eventTriggered;
  int               i;
  Uint32            timestamp;

  eventTriggered = false;
  timestamp = SDL_GetTicks();
  events_update();
  if (events_find_key(SDLK_ESCAPE) != NULL && events_find_key(SDLK_ESCAPE)->value == 1)
  {
    SDL->isOpened = false;
  }
  if (!ship_is_alive(SDL))
  {
    SDL->isOpened = false;
  }
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
  ship_move(SDL);
  background_draw(SDL);
  status_bar_update_life(SDL);
  status_bar_update_scores(SDL);
  ship_draw(SDL);
  ship_is_crashed(SDL);
  enemy_move(SDL);
  /*enemy_shoot_launch(SDL);
  enemy_shoot_draw(SDL);*/
}

void                main_loop(t_SDL_objects *SDL)
{
  Uint32            currentTime;
  Uint32            previousTime;
  Uint32            timeDiff;

  SDL->isOpened = true;
  previousTime = 0;
  while(SDL->isOpened)
  {
    currentTime = SDL_GetTicks();
    timeDiff = (currentTime - previousTime);
    if (timeDiff > MAX_TIME_DIFF(FRAMES_PER_SECOND))
    {
      SDL_RenderClear(SDL->renderer);
      game_loop(SDL);
      SDL_RenderPresent(SDL->renderer);
      previousTime = currentTime;
    }
    else
    {
      SDL_Delay(MAX_TIME_DIFF(FRAMES_PER_SECOND) - timeDiff);
    }
  }
}