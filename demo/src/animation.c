/* 
* @Author: BERTEAUX
* @Date:   2014-08-30 17:09:50
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-08-30 20:16:28
*/

#include      "../headers/main.h"

bool 			animation_init(t_SDL_objects *SDL)
{
	t_animation *animation1;
	t_animation *animation2;

	SDL->list_animations = malloc(sizeof(t_animation));
	animation1 = malloc(sizeof(animation1));
	animation1->id 			= STATE_NORMAL;
	animation1->nb_frames 	= 12;
	animation1->url_image	= "assets/images/dracaufeu.png";
	animation1->next		= NULL;
	SDL->list_animations	= animation1;

	animation2 = malloc(sizeof(animation2));
	animation2->id 			= STATE_CRASH;
	animation2->nb_frames 	= 12;
	animation2->url_image	= "assets/images/dracaufeu_crash.png";
	animation2->next		= NULL;
	/*animation_list_add_end(SDL, animation2);*/

	animation1->next = animation2;

	return true;
}

void 			animation_list_add_end(t_SDL_objects *SDL, t_animation *animation)
{
	struct s_animation *temp;

	if (SDL->list_animations == NULL)
	{
		SDL->list_animations = animation;
	}
	else 
	{
		temp = animation;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = animation;
	}
	printf("ok");
}

t_animation 	*animation_get(t_SDL_objects *SDL, int state)
{
	t_animation *temp;

	temp = SDL->list_animations;
	while (temp != NULL)
		{
			if (temp->id == state)
			{
				return temp;
			}
			temp = temp->next;
		}
	return SDL->list_animations;
}

void          animation_clear(t_SDL_objects *SDL)
{
  t_animation *temp;

	while (SDL->list_animations != NULL)
		{
			temp = SDL->list_animations;
			SDL->list_animations = SDL->list_animations->next;
			free(temp);
		}
}