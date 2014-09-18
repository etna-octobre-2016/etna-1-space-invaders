/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-03 13:02:19
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

/**
 * Crée pour chaque type d'ennemi, le nombre d'ennemis associés dans une structure t_level_event_enemies
 * @param   {t_level_event_enemies}   enemies La structure contenant le nombre d'ennemis par type
 * @param   {t_SDL_objects}           SDL     La structure principale du programme
 *
 * @return  {bool}  Renvoie true en cas de succès, ou false en cas d'erreur
 */
bool              enemy_add(t_level_event_enemies *enemies, t_SDL_objects *SDL)
{
  if (enemy_add_level_1(enemies->level1, SDL) == true)
  {
    return true;
  }
  return false;
}

/**
 * Crée un nombre défini d'ennemis de niveau 1
 * @param   {int}            count   Le nombre d'ennemis à créer
 * @param   {t_SDL_objects}  SDL     La structure principale du programme
 *
 * @return  {bool}  Renvoie true en cas de succès, ou false en cas d'erreur
 */
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
      enemy->width = 50;
      enemy->height = 50;
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

/**
 * Détruit tous les ennemis créés (fonction de nettoyage)
 * @param   {t_SDL_objects}   SDL   La structure principale du programme
 */
void              enemy_clear(t_SDL_objects *SDL)
{
  t_enemy         **temp;

  while (SDL->enemy != NULL)
    {
      if (SDL->enemy->image != NULL)
      {
        /* Seg fault pourquoi ?*/
        /*SDL_FreeSurface(SDL->enemy->image);*/
      }
      temp = &SDL->enemy;
      SDL->enemy = SDL->enemy->next;
      free(*temp);
    }
}

/**
 * Définit la trajectoire de chaque ennemi créé, selon son niveau
 * @param   {t_SDL_objects}   SDL   La structure principale du programme
 */
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
