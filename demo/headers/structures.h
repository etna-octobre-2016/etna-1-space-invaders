/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-20 17:55:07
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef           struct
  {
    int             nb_frames;

  }                 t_animation;

  typedef           struct
  {
    int 		        x;
    int 		        y;
    int 		        width;
    int 		        height;
    SDL_Surface     *image;
    t_animation     animation;
    int             num_frame;

  }                 t_ship;

  typedef           struct
  {
    int             x;
    int             y;
    int             width;
    int             height;
    SDL_Surface     *image;

  }                 t_enemy;

  typedef           struct
  {
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    t_ship	  	    *ship;
    t_enemy         *enemy;

  }                 t_SDL_objects;

#endif