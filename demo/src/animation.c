/*
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-25 00:00:53
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
  SDL->animation->id = SHIP_STATE_UNDEFINED;

  animation1->id = SHIP_STATE_NORMAL;
  animation1->nb_frames = 12;
  animation1->url_image = "assets/images/dracaufeu.png";
  animation1->next = NULL;

  animation2->id = SHIP_STATE_CRASH;
  animation2->nb_frames = 12;
  animation2->url_image = "assets/images/dracaufeu_crash.png";
  animation2->next = NULL;

  animation_add(animation1, SDL->animation);
  animation_add(animation2, SDL->animation);
  return true;
}

void          animation_add(t_animation *animation, t_animation *animation_list)
{
  t_animation *current;

  if (animation_list->id == SHIP_STATE_UNDEFINED)
  {
    animation_list->id = animation->id;
    animation_list->nb_frames = animation->nb_frames;
    animation_list->url_image = animation->url_image;
    animation_list->next = animation->next;
  }
  else
  {
    current = animation_list;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = animation;
  }
}

/**
 * Prépare le renvoi de l'animation correspondante au statut
 * Params :
 *   - t_SDL_objects *SDL
 *   - int state
 */
/*t_animation   *animation_get(t_SDL_objects *SDL, int state)
{
  return animation_get_recurs(SDL->list_animations, state);
}
*/
/**
 * Renvoie l'animation correspondante au statut de manière récursive
 * Params :
 *   - t_animation *animation
 *   - int state
 */
/*t_animation   *animation_get_recurs(t_animation *animation, int state)
{
  if (animation == NULL)
  {
    return NULL;
  }
  if (animation->id == state)
  {
    return animation;
  }
  return animation_get_recurs(animation->next, state);
}*/

/**
 * Prépare le clear de tout ce qui est en rapport avec les animations
 * Params :
 *   - t_SDL_objects *SDL
 */
/*void          animation_clear(t_SDL_objects *SDL)
{
  animation_clear_recurs(SDL->list_animations);
}*/

/**
 * Clear tout ce qui est en rapport avec les animations de manière récursive
 * Params :
 *   - t_animation *animation
 */
/*void          animation_clear_recurs(t_animation *animation)
{
  if (animation->next != NULL)
  {
    animation_clear_recurs(animation->next);
  }
  free(animation->next);
}*/