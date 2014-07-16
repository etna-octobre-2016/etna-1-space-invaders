/* 
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-07-16 17:51:42
*/

#include        "../headers/ship.h"

void	init_ship(t_SDL_objects *SDL) {
	/*Position de base*/
	SDL->ship->x = 0;
 SDL->ship->y = 0;

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
}

void	move(int direction, t_SDL_objects *SDL){
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