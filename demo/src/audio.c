/* 
* @Author: BERTEAUX
* @Date:   2014-09-18 19:18:32
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-18 19:24:21
*/

#include          "../headers/main.h"

bool            audio_init(t_SDL_objects *SDL)
{
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   	{
    	printf("%s", Mix_GetError());
    	return false;
   	}

   	SDL->music = Mix_LoadMUS("assets/music/moon.mp3");
   	Mix_PlayMusic(SDL->music, -1);

    return true;
}

void            audio_clear(t_SDL_objects *SDL)
{
	Mix_FreeMusic(SDL->music);
	Mix_CloseAudio();
}