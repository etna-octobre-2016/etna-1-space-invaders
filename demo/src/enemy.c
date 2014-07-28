/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-28 18:09:22
*/
#include          "../headers/main.h"

bool              enemy_init(t_level_event_enemies *enemies, t_SDL_objects *SDL)
{
  SDL_DisplayMode screen;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
  if (enemy_init_level_1(enemies->level1, &screen, SDL) == false)
  {
    return false;
  }
  return true;
}

bool              enemy_init_level_1(int enemiesCount, SDL_DisplayMode *screen, t_SDL_objects *SDL)
{
  int             i;
  t_enemy         *next;

  next = NULL;
  for (i = 0; i < enemiesCount; i++)
  {
    SDL->enemy = malloc(sizeof(t_enemy));
    SDL->enemy->level = 1;
    SDL->enemy->width = 49;
    SDL->enemy->height = 49;
    SDL->enemy->x = (screen->w - RAND_RANGE(0, 400));
    SDL->enemy->y = RAND_RANGE(0, screen->h);
    SDL->enemy->num_frame = 0;
    SDL->enemy->animation.nb_frames = 7;
    SDL->enemy->image = IMG_Load("assets/images/lunatone.png");
    if (SDL->enemy->image == NULL)
    {
      printf("Enemy init error: %s\n", IMG_GetError());
      return false;
    }
    SDL->enemy->next = next;
    next = SDL->enemy;
  }
  return true;
}

void              enemy_move(t_SDL_objects *SDL)
{
  t_enemy         *enemy;

  enemy = SDL->enemy;
  while (enemy != NULL)
  {
    switch (enemy->level)
    {
      case 1:
        move_enemy_straight(enemy, SDL);
        break;
    }
    enemy = enemy->next;
  }
}
