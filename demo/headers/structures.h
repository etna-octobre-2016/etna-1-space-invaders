/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-27 16:28:33
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef           struct
  {
    int             nb_frames;

  }                 t_animation;

  typedef           struct
  {
    int             x;
    int             y;
    int             width;
    int             height;
    SDL_Surface     *image;
    t_animation     animation;
    int             num_frame;

  }                 t_ship;

  typedef           struct s_enemy
  {
    int             x;
    int             y;
    int             width;
    int             height;
    int             num_frame;
    SDL_Surface     *image;
    t_animation     animation;
    struct s_enemy  *next;

  }                 t_enemy;

  typedef           struct
  {
    char            *type;
    Uint32          timestamp;
    t_enemy         *enemy;

  }                 t_level_event;

  typedef           struct
  {
    Uint32          timestamp;
    t_level_event   **events;

  }                 t_level;

  typedef           struct
  {
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    t_ship          *ship;
    t_enemy         *enemy;

  }                 t_SDL_objects;

#endif