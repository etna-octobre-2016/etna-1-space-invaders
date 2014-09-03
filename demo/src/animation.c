/* 
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-03 12:58:27
*/

#include      "../headers/main.h"

bool 			animation_init(t_SDL_objects *SDL)
{
	t_animation *animation1;
    t_animation *animation2;

	SDL->list_animations = malloc(sizeof(t_animation));
	animation1 = malloc(sizeof(animation1));
	animation2 = malloc(sizeof(animation2));
  	if (SDL->list_animations != NULL || animation1 == NULL || animation2 == NULL)
  	{
    	SDL->list_animations 	= NULL;
		animation1->id 			= STATE_NORMAL;
		animation1->nb_frames 	= 12;
		animation1->url_image	= "assets/images/dracaufeu.png";
		animation1->next		= NULL;
    	animation_list_add_end(SDL, animation1);
    	animation2->id 			= STATE_CRASH;
		animation2->nb_frames 	= 12;
		animation2->url_image	= "assets/images/dracaufeu_crash.png";
		animation2->next		= NULL;
		animation_list_add_end(SDL, animation2);
    	return true;
  	}
  else
  	{
    	return false;
  	}
}

/*
* Ajoute une structure en fin de liste
* Params :
* 	- t_SDL_objects *SDL
* 	- t_animation *animation
*/
void 			animation_list_add_end(t_SDL_objects *SDL, t_animation *animation)
{
	t_animation        *current;
	t_animation        *test;

	current = SDL->list_animations;
	test = SDL->list_animations;
	if (current == NULL){
		SDL->list_animations = animation;
		test = SDL->list_animations;

	}
	else
	{
    	while (current->next != NULL)
    	{
    		current = current->next;
    	}
		current->next = animation;
	}
	while (test->next != NULL)
    {
    	test = current->next;
    }

}

/*
* Renvoie l'animation correspondante au statut
* Params :
* 	- t_SDL_objects *SDL
* 	- int state
*/
t_animation 	*animation_get(t_SDL_objects *SDL, int state)
{
	t_animation        *current;

	current = SDL->list_animations;

    while (current != NULL)
    {
    	if (current->id == state)
		{
			return current;
		}
		current = current->next;
    }

	return SDL->list_animations;
}

/*
* Clear tout ce qui est en rapport avec les animations
* Params :
* 	- t_SDL_objects *SDL
*/
void          animation_clear(t_SDL_objects *SDL)
{
	t_animation **temp;

	while (SDL->list_animations != NULL)
	{
		temp = &SDL->list_animations;
		SDL->list_animations = SDL->list_animations->next;
		free(*temp);
	}
}