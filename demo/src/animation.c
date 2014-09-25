/*
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-25 01:01:27
*/
#include      "../headers/main.h"

bool          animation_init(t_SDL_objects *SDL)
{
  t_animation *animation1;
  t_animation *animation2;

  SDL->animation = malloc(sizeof(t_animation));
  animation1 = malloc(sizeof(t_animation));
  animation2 = malloc(sizeof(t_animation));
  if (SDL->animation == NULL || animation1 == NULL || animation2 == NULL)
  {
    return false;
  }
  animation1->id = SHIP_STATE_NORMAL;
  animation1->nb_frames = 12;
  animation1->url_image = "assets/images/dracaufeu.png";

  animation2->id = SHIP_STATE_CRASH;
  animation2->nb_frames = 12;
  animation2->url_image = "assets/images/dracaufeu_crash.png";

  animation1->next = animation2;
  animation2->next = animation1;
  SDL->animation = animation1;
  return true;
}

t_animation   *animation_get(int id, t_SDL_objects *SDL)
{
  t_animation *current;

  current = SDL->animation;
  while (current->next != NULL)
  {
    if (current->id == id)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
