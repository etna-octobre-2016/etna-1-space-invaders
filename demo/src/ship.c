/* 
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-07-16 16:01:11
*/

#include        "../headers/main.h"
#include        "../headers/ship.h"

void	init_ship(t_SDL_objects *SDL) {
	/*Position de base*/
	SDL->ship->x = 0;
  	SDL->ship->y = 0;

  	/*Taille d'un déplacement*/
  	SDL->ship->width	= 150;
  	SDL->ship->height	= 121;
}