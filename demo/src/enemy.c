/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-21 00:07:17
*/
#include          "../headers/main.h"

bool              enemy_init(t_SDL_objects *SDL)
{
  SDL_DisplayMode displayMode;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &displayMode);
  SDL->enemy = malloc(sizeof(t_enemy));
  SDL->enemy->x = displayMode.w;
  SDL->enemy->y = 0;
  SDL->enemy->width = 32;
  SDL->enemy->height = 32;
  SDL->enemy->image = IMG_Load("assets/images/enemy_1.png");
  if (SDL->enemy->image == NULL)
  {
    printf("Enemy init error: %s\n", IMG_GetError());
    return false;
  }
  return true;
}

void          enemy_move(t_SDL_objects *SDL)
{
  move_enemy_straight(SDL->enemy, SDL);
}