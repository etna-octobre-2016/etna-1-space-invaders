/* 
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-07-17 21:12:10
*/

#include        "../headers/ship.h"

void	init_ship(t_SDL_objects *SDL) {
	/*Position de base*/
	SDL->ship->x = 0;
  SDL->ship->y = 0;
  SDL->ship->num_frame = 0;

  /*Taille d'un déplacement*/
  SDL->ship->width	= 150;
  SDL->ship->height	= 121;

  /*Config*/
  SDL->ship->image = IMG_Load("assets/images/dracaufeu.png");
  if(!SDL->ship->image) 
  {
    printf("Image non chargée");
    exit(EXIT_FAILURE);
  }

  /*Animation*/
  SDL->ship->animation.nb_frames = 12;
}

void	move_ship(int direction, t_SDL_objects *SDL){
	switch (direction) {
    case SDLK_DOWN:
    SDL->ship->y += SDL->ship->height;
    break;
    case SDLK_UP:
    SDL->ship->y -= SDL->ship->height;
    break;
    case SDLK_RIGHT:
    SDL->ship->x += SDL->ship->width;
    break;
    case SDLK_LEFT:
    SDL->ship->x -= SDL->ship->width;
    break;
  }
}

void  print_ship(t_SDL_objects *SDL){
  SDL_Rect sourc, dest;
  SDL_Texture *texture;

  sourc.x = SDL->ship->width * SDL->ship->num_frame;
  sourc.y = 0;
  sourc.w = SDL->ship->width;
  sourc.h = SDL->ship->height;

  dest.x = SDL->ship->x;
  dest.y = SDL->ship->y;
  dest.w = SDL->ship->width;
  dest.h = SDL->ship->height;

  if (SDL->ship->num_frame < SDL->ship->animation.nb_frames)
  {
    SDL->ship->num_frame++;
  }
  else
  {
    SDL->ship->num_frame = 0;
  }

  SDL_RenderClear(SDL->renderer);

  texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->ship->image);
  if (texture < 0)
  {
    printf("Texture non chargée dans print_ship");
    exit(EXIT_FAILURE);
  }
  if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
  {
    printf("RenderCopy non chargée dans print_ship");
    exit(EXIT_FAILURE);
  }

  SDL_RenderPresent(SDL->renderer);
}