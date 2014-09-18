/*
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-03 15:46:53
*/
#include      "../headers/main.h"

bool          animation_init(t_SDL_objects *SDL)
{
  t_animation *animation1;
  t_animation *animation2;

  SDL->list_animations = malloc(sizeof(t_animation));
  animation1 = malloc(sizeof(animation1));
  animation2 = malloc(sizeof(animation2));
  if (SDL->list_animations != NULL || animation1 == NULL || animation2 == NULL)
  {
    SDL->list_animations = NULL;
    animation1->id = SHIP_STATE_NORMAL;
    animation1->nb_frames = 12;
    animation1->url_image = "assets/images/dracaufeu.png";
    animation1->next = NULL;
    animation_list_add_end(SDL, animation1);

    animation2->id = SHIP_STATE_CRASH;
    animation2->nb_frames = 12;
    animation2->url_image = "assets/images/dracaufeu_crash.png";
    animation2->next = NULL;
    animation_list_add_end(SDL, animation2);

    return true;
  }
  else
  {
    return false;
  }
}

/**
 * Prépare l'ajout une structure en fin de liste
 * Params :
 *   - t_SDL_objects *SDL
 *   - t_animation *animation
 */
void          animation_list_add_end(t_SDL_objects *SDL, t_animation *animation)
{
  t_animation *current;

  current = SDL->list_animations;
  if (current == NULL)
  {
    SDL->list_animations = animation;
    SDL->list_animations->next = NULL;
  }
  else
  {
    animation_list_add_end_recurs(SDL->list_animations, animation);
  }
}

/**
 * Ajoute une structure en fin de liste de manière récursive
 * Params :
 *   - t_animation *animation
 *   - t_animation *animation_to_add
 */
t_animation   *animation_list_add_end_recurs(t_animation *animation, t_animation *animation_to_add)
{
  if (animation->next != NULL)
  {
    animation_list_add_end_recurs(animation->next, animation_to_add);
  }
  animation->next = animation_to_add;
  animation->next->next = NULL;
  return NULL; /* @todo: demander à Edwige pourquoi ça ne retourne pas un t_animation */
}

/**
 * Prépare le renvoi de l'animation correspondante au statut
 * Params :
 *   - t_SDL_objects *SDL
 *   - int state
 */
t_animation   *animation_get(t_SDL_objects *SDL, int state)
{
  return animation_get_recurs(SDL->list_animations, state);
}

/**
 * Renvoie l'animation correspondante au statut de manière récursive
 * Params :
 *   - t_animation *animation
 *   - int state
 */
t_animation   *animation_get_recurs(t_animation *animation, int state)
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
}

/**
 * Prépare le clear de tout ce qui est en rapport avec les animations
 * Params :
 *   - t_SDL_objects *SDL
 */
void          animation_clear(t_SDL_objects *SDL)
{
  animation_clear_recurs(SDL->list_animations);
}

/**
 * Clear tout ce qui est en rapport avec les animations de manière récursive
 * Params :
 *   - t_animation *animation
 */
void          animation_clear_recurs(t_animation *animation)
{
  if (animation->next != NULL)
  {
    animation_clear_recurs(animation->next);
  }
  free(animation->next);
}