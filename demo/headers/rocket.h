/* 
* @Author: pakpak
* @Date:   2014-07-26 22:04:47
* @Last Modified by:   pakpak
* @Last Modified time: 2014-09-06 11:23:39
*/
#ifndef ROCKET_H
#define ROCKET_H
	bool 	  	rocket_init(t_SDL_objects *);
	bool        rocket_manager(int, t_SDL_objects *SDL);
	bool        rocket_add(int, t_SDL_objects *SDL);
	void 		rocket_move(t_SDL_objects *SDL);
	void        rocket_clear(t_SDL_objects *SDL);
#endif