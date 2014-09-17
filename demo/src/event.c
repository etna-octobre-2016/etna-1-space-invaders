/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   Bernar_s
* @Last Modified time: 2014-09-03 15:45:10
*/

#include            "../headers/main.h"


hash 	*key_event = NULL;

/**
*retrouve une structure en fonction de la clé entré en paramètre 
*/
hash 		*find_key(int key) 
{
    hash 	*h;

    HASH_FIND_INT( key_event, &key, h ); 
    return h;
}

/**
*Ajoute une structure à la table de hash
*/
void 		add_key(int key_push, int value) 
{
    hash 	*h;

	HASH_FIND_INT(key_event, &key_push, h); 
    if (h==NULL) 
    {
    	h = malloc(sizeof(hash));
    	h->key = key_push;  
    	HASH_ADD_INT( key_event, key, h);   
    } 
    h->value = value;
}

/**
*Supprime toutes les structures de la table de hash
*/
void		delete_all() 
{
  	hash 	*current_key 
  	hash 	*tmp;

  HASH_ITER(hh, key_event, current_key, tmp) 
  {
    HASH_DEL(key_event,current_key);  
    free(current_key);            
  }
}

void	UpdateEvents(SDL_Event event)
{
   	/*SDL_Event event;*/
	

	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			add_key(event.key.keysym.sym, 1);
			break;
		case SDL_KEYUP:
			add_key(event.key.keysym.sym, 0);
			break;
		default:
			break;
		}
	}
}