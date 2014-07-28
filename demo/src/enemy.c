/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-28 20:50:02
*/
#include          "../headers/main.h"

bool              enemy_init(t_SDL_objects *SDL)
{
  SDL->enemy = malloc(sizeof(t_enemy));
  if (SDL->enemy != NULL)
  {
    SDL->enemy->next = NULL;
    return true;
  }
  else
  {
    return false;
  }
}

bool              enemy_add(t_level_event_enemies *enemies, t_SDL_objects *SDL)
{
  if (enemy_add_level_1(enemies->level1, SDL) == true)
  {
    return true;
  }
  return false;
}

bool              enemy_add_level_1(int count, t_SDL_objects *SDL)
{
  int             i;
  t_enemy         *current;
  t_enemy         *enemy;
  SDL_DisplayMode screen;

  current = SDL->enemy;
  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
  for (i = 0; i < count; i++)
  {
    enemy = malloc(sizeof(t_enemy));
    if (enemy != NULL)
    {
      enemy->level = 1;
      enemy->next = NULL;
      enemy->width = 49;
      enemy->height = 49;
      enemy->x = screen.w + RAND_RANGE(0, 400);
      enemy->y = RAND_RANGE(0, screen.h);
      enemy->num_frame = 0;
      enemy->animation.nb_frames = 7;
      enemy->image = IMG_Load("assets/images/lunatone.png");
      if (enemy->image == NULL)
      {
        printf("Enemy init error: %s\n", IMG_GetError());
        return false;
      }
      while (current->next != NULL)
      {
        current = current->next;
      }
      current->next = enemy;
    }
  }
  return true;
}

void              enemy_clear(t_SDL_objects *SDL)
{
  t_enemy         *enemy;
  t_enemy         *tmp;

  enemy = SDL->enemy;
  while (enemy->next != NULL)
  {
    tmp = enemy;
    enemy = enemy->next;
    SDL_FreeSurface(tmp->image);
    free(tmp);
  }
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
