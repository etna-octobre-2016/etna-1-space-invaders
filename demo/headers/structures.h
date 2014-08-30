/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-08-30 16:45:55
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef                 struct
  {
    int                   nb_frames;

  }                       t_animation;

  typedef                 struct
  {
    int                   x;                  /* Coordonnées x */
    int                   y;                  /* Coordonnées y */
    int                   width;              /* Longueur */
    int                   height;             /* Hauteur */
    int                   life;               /* Vie */
    int                   state;              /* Etat */
    int                   previous_state;     /* Ancien etat */
    SDL_Surface           *image;             /* Image */
    t_animation           animation;          /* Animation */
    int                   num_frame;          /* Numéro du frame en cours de l'image */

  }                       t_ship;

  typedef                 struct s_enemy
  {
    int                   x;
    int                   y;
    int                   width;
    int                   height;
    int                   num_frame;
    int                   level;
    SDL_Surface           *image;
    t_animation           animation;
    struct s_enemy        *next;

  }                       t_enemy;

  typedef                 struct
  {
    int                   level1;
    int                   level2;
    int                   level3;

  }                       t_level_event_enemies;

  typedef                 struct
  {
    bool                  triggered;
    char                  type;
    Uint32                timestamp;
    t_level_event_enemies enemies;

  }                       t_level_event;


  typedef                 struct
  {
    int                   eventsCount;
    int                   number;
    bool                  completed;
    Uint32                timestamp;
    t_level_event         **events;

  }                       t_level;

  typedef                 struct
  {
    SDL_Window            *window;
    SDL_Renderer          *renderer;
    t_ship                *ship;
    t_enemy               *enemy;
    t_level               *level;

  }                       t_SDL_objects;

#endif