/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-23 22:53:05
*/
#include          "../headers/main.h"

bool              enemy_init(t_SDL_objects *SDL)
{
  SDL_DisplayMode displayMode;
  t_enemy         *next;
  int             count;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &displayMode);
  next = NULL;
  for (count = 0; count < ENEMY_COUNT; count++)
  {
    SDL->enemy = malloc(sizeof(t_enemy));
    SDL->enemy->width = 49;
    SDL->enemy->height = 49;
    SDL->enemy->x = (displayMode.w - RAND_RANGE(0, 400));
    SDL->enemy->y = RAND_RANGE(0, displayMode.h);
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
    move_enemy_straight(enemy, SDL);
    enemy = enemy->next;
  }
}
