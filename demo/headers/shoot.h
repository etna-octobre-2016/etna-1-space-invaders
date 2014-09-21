/*
* @Author: ahemt_s
* @Date:   2014-09-20 17:23:40
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-21 23:28:49
*/
#ifndef SHOOT_H
#define SHOOT_H

  bool shoot_enemy_init(t_shoot *, t_enemy *);
  bool shoot_enemy_level_1_init(t_shoot *, t_enemy *);

  bool shoot_enemy_draw(t_shoot *, t_enemy *, t_SDL_objects *);
  bool shoot_enemy_level_1_draw(t_shoot *shoot, t_SDL_objects *);

#endif