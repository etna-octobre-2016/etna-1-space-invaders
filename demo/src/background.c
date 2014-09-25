/* 
* @Author: BERTEAUX
* @Date:   2014-09-18 18:24:25
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-18 19:08:48
*/

#include          "../headers/main.h"

bool            background_init(t_SDL_objects *SDL)
{
	SDL->background = malloc(sizeof(t_background));

	/* Taille de límage */
  	SDL->background->width  	= 1415;
  	SDL->background->height 	= 254;

  	SDL->background->x 			= 0;

  	/*Config*/
    SDL->background->image = IMG_Load("assets/images/space.png");

    if (SDL->background->image == NULL)
    {
        printf("Background init error: %s\n", IMG_GetError());
        return false;
    }
    return true;
}

void            background_draw(t_SDL_objects *SDL)
{

    background_draw_left(SDL);
    background_draw_right(SDL);

    SDL->background->x += 5;
    if (SDL->background->x > SDL->background->width)
    {
        SDL->background->x = 0;
    }
}

void            background_draw_left(t_SDL_objects *SDL)
{
    SDL_Rect        sourc;
    SDL_Rect        dest;
    SDL_Texture     *texture;
    SDL_DisplayMode screen;

    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
    sourc.x = SDL->background->x;
    sourc.y = 0;
    sourc.w = SDL->background->width - SDL->background->x;
    sourc.h = SDL->background->height;

    dest.x = 0;
    dest.w = SDL->background->width - SDL->background->x;
    dest.h = SDL->background->height;

    for (dest.y = 0; dest.y < screen.h; dest.y += SDL->background->height)
    {
        texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->background->image);
        if (texture < 0)
        {
            printf("Background draw error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
        {
            printf("Background draw error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }

}

void            background_draw_right(t_SDL_objects *SDL)
{
    SDL_Rect        sourc;
    SDL_Rect        dest;
    SDL_Texture     *texture;
    SDL_DisplayMode screen;

    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
    sourc.x = 0;
    sourc.y = 0;
    sourc.w = SDL->background->x;
    sourc.h = SDL->background->height;

    dest.x = SDL->background->width - SDL->background->x;
    dest.w = SDL->background->x;
    dest.h = SDL->background->height;

    for (dest.y = 0; dest.y < screen.h; dest.y += SDL->background->height)
    {
        texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->background->image);
        if (texture < 0)
        {
            printf("Background draw error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
        {
            printf("Background draw error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}

void            background_clear(t_SDL_objects *SDL)
{
	SDL_FreeSurface(SDL->background->image);
	free(SDL->background);
}
