/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   Bernar_s
* @Last Modified time: 2014-09-03 15:45:10
*/

#include            "../headers/main.h"


void UpdateEvents(Input* in)
{
   SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			in->tab.key = event.key.keysym.sym;
			in->tab.value = 1;
			break;
		case SDL_KEYUP:
			in->tab.key = event.key.keysym.sym;
			in->tab.value = 0 ;
			break;
		default:
			break;
		}
	}
}