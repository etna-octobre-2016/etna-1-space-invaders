/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-25 21:43:03
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef struct s_animation t_animation;
  struct                  s_animation
  {
    int                   id;                  /* Identifiant de l'animation */
    int                   nb_frames;           /* Numéro de frames de l'animation */
    char                  *url_image;
    t_animation           *next;               /* Suite de la liste chainée */
  };

  typedef                 struct s_shoot
  {
    bool                  is_first;
    int                   x;
    int                   y;
    int                   height;
    int                   width;
    SDL_Surface           *image;
    struct s_shoot        *next;

  }                       t_shoot;

  typedef                 struct
  {
    int                   x;                  /* Coordonnées x */
    int                   y;                  /* Coordonnées y */
    int                   width;              /* Longueur */
    int                   height;             /* Hauteur */
    int                   life;               /* Vie */
    bool                  can_move;           /* Indique si le vaisseau peut bouger */
    bool                  can_shoot;          /* Indiaue si le vaisseau peut tirer */
    t_animation           *animation;         /* Animation */
    int                   previous_animation; /* ID de l'ancienne animation */
    SDL_Surface           *image;             /* Image */
    SDL_Surface           *life_bar;
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
    int                   max_life;
    SDL_Surface           *image;
    t_animation           animation;
    t_shoot               *shoot;
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
    int                   score;
    bool                  completed;
    Uint32                timestamp;
    t_level_event         **events;

  }                       t_level;

  typedef                 struct
  {
    TTF_Font              *scores;

  }                       t_status_bar;

  typedef                 struct
  {
    SDL_Surface           *image;
    int                   width;
    int                   height;
    int                   x;
    
  }                       t_background;

  typedef                 struct
  {
    SDL_Window            *window;
    SDL_Renderer          *renderer;
    t_ship                *ship;
    t_enemy               *enemy;
    t_level               *level;
    t_status_bar          *status_bar;
    t_animation           *animation;       /* Liste chainée des animations */
    t_background          *background;
    Mix_Music             *music;
    bool                  isOpened;

  }                       t_SDL_objects;

#endif