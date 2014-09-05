/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-05 15:48:12
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef                 struct
  {
    int                   nb_frames;

  }                       t_animation;

  typedef                 struct
  {
    int                   x;
    int                   y;
    int                   width;
    int                   height;
    int                   life;
    SDL_Surface           *image;
    SDL_Surface           *progress_bar;
    t_animation           animation;
    int                   num_frame;

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
    TTF_Font              *scores;
  }                       t_status_bar;

  typedef                 struct
  {
    SDL_Window            *window;
    SDL_Renderer          *renderer;
    t_ship                *ship;
    t_enemy               *enemy;
    t_level               *level;
    t_status_bar          *status_bar;
  }                       t_SDL_objects;

#endif