/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:40:56
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-26 14:35:01
*/
#include      "../headers/main.h"

void          move_enemy_straight(t_enemy *enemy, t_SDL_objects *SDL)
{
  SDL_Rect    src;
  SDL_Rect    dest;
  SDL_Texture *texture;

  src.x = enemy->num_frame * enemy->width;
  src.y = 0;
  src.w = enemy->width;
  src.h = enemy->height;
  dest.x = enemy->x - 5;
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
  if (enemy->num_frame < enemy->animation.nb_frames)
  {
    enemy->num_frame++;
  }
  else
  {
    enemy->num_frame = 0;
  }
  enemy->x -= 5;
}