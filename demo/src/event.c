/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   Bernar_s
* @Last Modified time: 2014-09-03 15:45:10
*/

#include            "../headers/main.h"


hash *key_event = NULL;

hash *find_key(int key) {
    hash *h;

    HASH_FIND_INT( key_event, &key, h ); 
    return h;
}

void add_key(int key_push, int value) {
    hash *h;

HASH_FIND_INT(key_event, &key_push, h); 
    if (h==NULL) {
    	h = malloc(sizeof(hash));
    	h->key = key_push;  
    	HASH_ADD_INT( key_event, key, h);   
    } 
    h->value = value;
}


void UpdateEvents(SDL_Event event)
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