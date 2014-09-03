/* 
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-03 15:36:09
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
    	printf("On initialise la première animation id : %d\n", SDL->list_animations->id);
    	animation2->id 			= STATE_CRASH;
		animation2->nb_frames 	= 12;
		animation2->url_image	= "assets/images/dracaufeu_crash.png";
		animation2->next		= NULL;
		animation_list_add_end(SDL, animation2);
		printf("On initialise la deuxième animation id : %d\n", SDL->list_animations->next->id);
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

	current = SDL->list_animations;
	if (current == NULL){
		SDL->list_animations = animation;
		SDL->list_animations->next = NULL;
	}
	else 
	{
		animation_list_add_end_recurs(SDL->list_animations, animation);
	}
}

t_animation 	*animation_list_add_end_recurs(t_animation *animation, t_animation *animation_to_add)
{
	if (animation->next != NULL)
	{
		animation_list_add_end_recurs(animation->next, animation_to_add);
	}
	animation->next 		= animation_to_add;
	animation->next->next 	= NULL;
	return NULL;
}

/*
* Renvoie l'animation correspondante au statut
* Params :
* 	- t_SDL_objects *SDL
* 	- int state
*/
t_animation 	*animation_get(t_SDL_objects *SDL, int state)
{
	return animation_get_recurs(SDL->list_animations, state);
}

t_animation 	*animation_get_recurs(t_animation *animation, int state)
{
	if (animation->id == state)
	{
		return animation;
	}
	if (animation->next == NULL)
	{
		return NULL;
	}
	return animation_get_recurs(animation->next, state);
}

/*
* Clear tout ce qui est en rapport avec les animations
* Params :
* 	- t_SDL_objects *SDL
*/
void         	animation_clear(t_SDL_objects *SDL)
{
    animation_clear_recurs(SDL->list_animations);
}

void 			animation_clear_recurs(t_animation *animation)
{
	if (animation->next != NULL)
	{
		animation_clear_recurs(animation->next);
	}
	printf("on a free %d\n", animation->id);
	free(animation->next);
}