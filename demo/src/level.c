#include  "../headers/main.h"

bool      level_init(int levelNumber, t_SDL_objects *SDL)
{
  SDL->level = malloc(sizeof(t_level));
  if (SDL->level != NULL)
  {
    SDL->level->completed = false;
    SDL->level->number = levelNumber;
    SDL->level->timestamp = SDL_GetTicks();
    return level_events_init(SDL);
  }
  else
  {
    printf("level_init() error\n");
    return false;
  }
}

bool      level_events_init(t_SDL_objects *SDL)
{
  switch (SDL->level->number)
  {
    case 1:
      return level_1_events_init(SDL);
    default:
      printf("level_events_init error: wrong level number (%d)\n", SDL->level->number);
      return false;
  }
}

bool      level_1_events_init(t_SDL_objects *SDL)
{
  int     i;
  int     timestamp;

  SDL->level->eventsCount = 4;
  SDL->level->events = malloc(sizeof(t_level_event) * SDL->level->eventsCount);
  timestamp = SDL->level->timestamp;
  if (SDL->level->events != NULL)
  {
    for (i = 0; i < SDL->level->eventsCount; i++)
    {
      SDL->level->events[i] = malloc(sizeof(t_level_event));
      if (SDL->level->events[i] != NULL)
      {
        SDL->level->events[i]->triggered = false;
        switch (i)
        {
          case 0:
            timestamp += 1000;
            SDL->level->events[i]->type = 'E';
            SDL->level->events[i]->timestamp = timestamp;
            SDL->level->events[i]->enemies.level1 = 10;
            SDL->level->events[i]->enemies.level2 = 0;
            SDL->level->events[i]->enemies.level3 = 0;
            break;
          case 1:
            timestamp += 1000;
            SDL->level->events[i]->type = 'E';
            SDL->level->events[i]->timestamp = timestamp;
            SDL->level->events[i]->enemies.level1 = 5;
            SDL->level->events[i]->enemies.level2 = 0;
            SDL->level->events[i]->enemies.level3 = 0;
            break;
          case 2:
            timestamp += 5000;
            SDL->level->events[i]->type = 'E';
            SDL->level->events[i]->timestamp = timestamp;
            SDL->level->events[i]->enemies.level1 = 15;
            SDL->level->events[i]->enemies.level2 = 0;
            SDL->level->events[i]->enemies.level3 = 0;
            break;
          case 3:
            timestamp += 8000;
            SDL->level->events[i]->type = 'E';
            SDL->level->events[i]->timestamp = timestamp;
            SDL->level->events[i]->enemies.level1 = 30;
            SDL->level->events[i]->enemies.level2 = 0;
            SDL->level->events[i]->enemies.level3 = 0;
            break;
        }
      }
      else
      {
        printf("level_events_init() error: malloc unsuccessful on level->events[i]\n");
        return false;
      }
    }
    return true;
  }
  else
  {
    printf("level_events_init() error: malloc unsuccessful on level->events\n");
    return false;
  }
}