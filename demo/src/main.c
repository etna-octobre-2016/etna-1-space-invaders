/*
* @Author: sebastien
* @Date:   2014-09-21 20:02:13
* @Last Modified by:   sebastien
* @Last Modified time: 2014-09-24 21:12:18
*/
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

/**
 * Fonction d'initialisation du programme
 * @param   {t_SDL_objects} SDL la structure principale du programme
 * @return  {bool} renvoie true en cas de succès, ou false en cas d'erreur
 */
bool                init(t_SDL_objects *SDL)
{
  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    if (TTF_Init() == 0)
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
                  if (status_bar_init(SDL) == true)
                  {
                    return true;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      printf("TTF init error\n");
    }
    return false;
  }
  else
  {
    printf("SDL init error: %s\n", SDL_GetError());
    return false;
  }
}

/**
 * Fonction de nettoyage du programme
 * @param {t_SDL_objects}  SDL la structure principale du programme
 */
void                clear(t_SDL_objects *SDL)
{
  status_bar_clear_scores(SDL);
  animation_clear(SDL);
  /*ship_clear(SDL);*/
  enemy_clear(SDL);
  events_clear();
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
}

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
        case 'F':
        SDL->level->completed = true;
        eventTriggered = true;
        break;
      }
      if (eventTriggered == true)
      {
        SDL->level->events[i]->triggered = true;
      }
    }
  }
  status_bar_update_life(SDL);
  status_bar_update_scores(SDL);
  ship_move(SDL);
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
  while(opened)
  {
    currentTime = SDL_GetTicks();
    timeDiff = (currentTime - previousTime);
    if (timeDiff > MAX_TIME_DIFF(FRAMES_PER_SECOND)) /* Code exécuté à la fréquence de FRAMES_PER_SECOND */
    {
      events_update(event);
      if (events_find_key(SDLK_ESCAPE) != NULL && events_find_key(SDLK_ESCAPE)->value == 1)
      {
        opened = false;
      }
      if (!ship_is_in_life(SDL))
      {
        /*opened = false;*/
        end_game(SDL, 1);

      }
      SDL_RenderClear(SDL->renderer);
      if(SDL->level->completed)
        end_game(SDL, 2);
      else
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

/**
 * efface le Dracaufeu et affiche le score à l'écran
 * Params :
 *   - t_SDL_objects *SDL
 */
void                 end_game(t_SDL_objects *SDL, int fin)
{
  static bool       is_clear = true;
  SDL_Surface       *text;
  SDL_Color         color_text;
  SDL_Rect          sourc;
  SDL_Rect          dest;
  SDL_Texture       *texture;
  SDL_DisplayMode   screen;
  char              *text_to_print;

  text = NULL;
  text_to_print = malloc(sizeof(char *));

  printf("%d\n",SDL->level->score);
  if (is_clear)
  {
    printf("test");
    ship_clear(SDL);
    printf("test2");
    SDL->status_bar->scores = TTF_OpenFont("assets/font/truelies.ttf", 30);
    is_clear = false;
  }

  if (text_to_print != NULL)
  {
    if (fin == 2)
      snprintf(text_to_print, 100, "Score final : %d", SDL->level->score);
    else if (fin == 1)
      snprintf(text_to_print, 100, "Game Over \nScore final : %d", SDL->level->score);

    color_text.r = 255;
    color_text.g = 255;
    color_text.b = 255;

    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen); /* @todo: utiliser une variable "globale" à la place */

    text = TTF_RenderText_Blended(SDL->status_bar->scores, text_to_print, color_text);
    texture = SDL_CreateTextureFromSurface(SDL->renderer, text);
    sourc.x = 0;
    sourc.y = 0;
    dest.x = 320;
    dest.y = 100;
    dest.w = text->w;
    dest.h = text->h;

    if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
    {
      printf("text error: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    free(text_to_print);
  }

}