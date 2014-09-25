/*
* @Author: ahemt_s
* @Date:   2014-09-20 16:05:12
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-25 03:33:13
*/
#include  "../headers/main.h"

bool          shoot_enemy_init(t_shoot *shoot, t_enemy *enemy)
{
  switch (enemy->level)
  {
    case 1:
      return shoot_enemy_level_1_init(shoot, enemy);
    default:
      return false;
  }
}

bool          shoot_enemy_draw(t_shoot *shoot, t_enemy *enemy, t_SDL_objects *SDL)
{
  switch (enemy->level)
  {
    case 1:
      return shoot_enemy_level_1_draw(shoot, SDL);
    default:
      return false;
  }
}

bool          shoot_enemy_level_1_init(t_shoot *shoot, t_enemy *enemy)
{
  shoot->is_first = false;
  shoot->x = enemy->x;
  shoot->y = enemy->y;
  shoot->height = 15;
  shoot->width = 15;
  shoot->next = NULL;
  shoot->image = IMG_Load("assets/images/shoot_enemy_lvl_1.png");
  if (shoot->image == NULL)
  {
    printf("shoot_enemy_level_1_init error: %s\n", IMG_GetError());
    return false;
  }
  return true;
}

bool          shoot_enemy_level_1_draw(t_shoot *shoot, t_SDL_objects *SDL)
{
  SDL_Rect    src;
  SDL_Rect    dest;
  SDL_Texture *texture;

  src.x = shoot->x;
  src.y = shoot->y;
  src.w = shoot->width;
  src.h = shoot->height;

  dest.x = shoot->x;
  dest.y = shoot->y;
  dest.w = shoot->width;
  dest.h = shoot->height;

  texture = SDL_CreateTextureFromSurface(SDL->renderer, shoot->image);
  if (texture == 0)
  {
    printf("shoot_enemy_level_1_draw error: %s\n", SDL_GetError());
    return false;
  }
  if (SDL_RenderCopy(SDL->renderer, texture, &src, &dest) < 0)
  {
    printf("shoot_enemy_level_1_draw error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}