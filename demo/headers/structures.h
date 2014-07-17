/* 
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-07-17 21:11:47
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H
  #include        "includes.h"

  typedef         struct
  {
    int           nb_frames;

  }               t_animation;

  typedef		struct
  {
    int 		      x;
    int 		      y;
    int 		      width;
    int 		      height;
    SDL_Surface   *image;
    t_animation   animation;
    int           num_frame;

  } 			       t_ship;

  typedef         struct
  {
    SDL_Window    *window;
    SDL_Renderer  *renderer;
    t_ship	  	  *ship;

  }               t_SDL_objects;

#endif