/*
* @Author: ahemt_s
* @Date:   2014-07-20 23:24:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-25 20:45:37
*
* @todo:
*   - ajouter une fonction enemy_each pour parcourir tous les ennemis
*   - changer le prototype de enemy_clear() pour supprimer 1 ennemi lorsqu'il depasse l'ecran
*   - changer le prototype de enemy_move() pour déplacer 1 ennemi
*   - changer le prototype de enemy_shoot() pour faire tirer 1 ennemi
*   - ajouter une fonction enenmy_clear_all() qui servira de fonction de nettoyage
*/
#include          "../headers/main.h"

bool              enemy_init(t_SDL_objects *SDL)
{
  SDL->enemy = malloc(sizeof(t_enemy));
  if (SDL->enemy != NULL)
  {
    SDL->enemy->level = 0;
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
  bool            is_first;
  int             i;
  t_enemy         *current;
  t_enemy         *enemy;
  SDL_DisplayMode screen;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
  is_first = false;
  for (i = 0; i < count; i++)
  {
    if (SDL->enemy->level == 0)
    {
      enemy = SDL->enemy;
      is_first = true;
    }
    else
    {
      enemy = malloc(sizeof(t_enemy));
      if (enemy == NULL)
      {
        return false;
      }
    }
    enemy->image = IMG_Load("assets/images/lunatone.png");
    /*enemy->shoot = malloc(sizeof(t_shoot));*/
    if (enemy->image == NULL)
    {
      printf("enemy_add_level_1 error: %s\n", IMG_GetError());
      return false;
    }
    /*if (enemy->shoot == NULL)
    {
      puts("enemy_add_level_1 error: shoot malloc failed");
      return false;
    }*/
    enemy->level = 1;
    enemy->next = NULL;
    enemy->width = 50;
    enemy->height = 50;
    enemy->x = screen.w + RAND_RANGE(0, 400);
    enemy->y = RAND_RANGE(0, (screen.h - STATUS_BAR_HEIGHT - enemy->height));
    enemy->num_frame = 0;
    enemy->animation.nb_frames = 7;
    /*enemy->shoot->is_first = true;*/
    if (!is_first)
    {
      current = SDL->enemy;
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
  t_enemy         *enemy;
  t_enemy         *tmp;

  enemy = SDL->enemy;
  while (enemy->next != NULL)
  {
    tmp = enemy;
    enemy = enemy->next;
    /*SDL_FreeSurface(tmp->image); @todo: vérifier s'il y a toujours un segfault ici*/
    free(tmp);
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
  while (enemy->next != NULL)
  {
    switch (enemy->level)
    {
      case 1:
        move_enemy_straight(enemy, SDL);
        break;
      default:
        return;
    }
    enemy = enemy->next;
  }
}

/**
 * Lance un tir pour chaque ennemi
 * @param   {t_SDL_objects}   SDL   La structure principale du programme
 */
/*void              enemy_shoot_launch(t_SDL_objects *SDL)
{
  t_enemy         *enemy;
  t_shoot         *enemy_shoot;
  t_shoot         *new_shoot;

  if (SDL->enemy->level == 0)
  {
    return;
  }
  enemy = SDL->enemy;
  enemy_shoot = enemy->shoot;
  while (enemy->next != NULL)
  {
    new_shoot = malloc(sizeof(t_shoot));
    if (new_shoot != NULL)
    {
      if (shoot_enemy_init(new_shoot, enemy) == true)
      {
        if (enemy_shoot->is_first == false)
        {
          while (enemy_shoot->next != NULL)
          {
            enemy_shoot = enemy_shoot->next;
          }
          enemy_shoot->next = new_shoot;
        }
        else
        {
          enemy->shoot = new_shoot;
        }
      }
      else
      {
        puts("enemy_shoot_launch error: new_shoot init failed");
      }
    }
    else
    {
      puts("enemy_shoot_launch error: new_shoot malloc failed");
    }
    enemy = enemy->next;
  }
}

void              enemy_shoot_draw(t_SDL_objects *SDL)
{
  t_enemy         *enemy;
  t_shoot         *enemy_shoot;

  if (SDL->enemy->level == 0)
  {
    return;
  }
  enemy = SDL->enemy;
  enemy_shoot = enemy->shoot;
  while (enemy->next != NULL)
  {
    if (enemy_shoot->is_first == false)
    {
      while (enemy_shoot->next != NULL)
      {
        shoot_enemy_draw(enemy_shoot, enemy, SDL);
        enemy_shoot = enemy_shoot->next;
      }
    }
    enemy = enemy->next;
  }
}*/