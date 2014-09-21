/*
* @Author: ahemt_s
* @Date:   2014-09-20 16:05:12
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-21 22:19:17
*/
#include  "../headers/main.h"

bool      shoot_enemy_init(t_shoot *shoot, t_enemy *enemy)
{
  switch (enemy->level)
  {
    case 1:
      return shoot_enemy_level_1_init(shoot, enemy);
    default:
      return shoot_enemy_level_1_init(shoot, enemy);
  }
}

bool      shoot_enemy_level_1_init(t_shoot *shoot, t_enemy *enemy)
{
  shoot->x = enemy->x;
  shoot->y = enemy->y;
  shoot->height = enemy->height;
  shoot->width = enemy->width;
  shoot->next = NULL;
  shoot->image = IMG_Load("assets/images/shoot_enemy_lvl_1.png");
  if (shoot->image == NULL)
  {
    printf("shoot_enemy_level_1_init error: %s\n", IMG_GetError());
    return false;
  }
  return true;
}