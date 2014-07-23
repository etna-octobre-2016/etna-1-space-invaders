/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:40:56
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-23 22:15:31
*/
#include      "../headers/main.h"

void          move_enemy_straight(t_enemy *enemy, t_SDL_objects *SDL)
{
  SDL_Rect    src;
  SDL_Rect    dest;
  SDL_Texture *texture;

  src.x = 0;
  src.y = 0;
  src.w = enemy->width;
  src.h = enemy->height;

  dest.x = enemy->x - 10;
  dest.y = enemy->y;
  dest.w = enemy->width;
  dest.h = enemy->height;

  texture = SDL_CreateTextureFromSurface(SDL->renderer, enemy->image);

  if (texture == 0)
  {
    printf("move_enemy_straight error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (SDL_RenderCopy(SDL->renderer, texture, &src, &dest) < 0)
  {
    printf("move_enemy_straight error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  enemy->x -= 10;
}