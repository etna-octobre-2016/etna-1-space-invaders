/* 
* @Author: pakpak
* @Date:   2014-07-26 22:04:29
* @Last Modified by:   pakpak
* @Last Modified time: 2014-09-06 15:10:45
*/

#include          "../headers/main.h"

bool              rocket_init(t_SDL_objects *SDL)
{
  SDL->rocket = malloc(sizeof(t_rocket));
  if (SDL->rocket != NULL)
  {
    SDL->rocket->next = NULL;
    return true;
  }
  else
  {
    return false;
  }
}

bool          rocket_manager(int event, t_SDL_objects *SDL)
{
  if (rocket_add(event, SDL) == true)
  {
    return true;
  }
  return false;
}

void          rocket_move(t_SDL_objects *SDL)
{
  SDL_Rect    src;
  SDL_Rect    dest;
  SDL_Texture *texture;

  src.x = SDL->rocket->x;
  src.y = SDL->rocket->y;
  src.w = SDL->rocket->width;
  src.h = SDL->rocket->height;

  dest.x = SDL->rocket->x;
  dest.y = SDL->rocket->y;
  dest.w = SDL->rocket->width;
  dest.h = SDL->rocket->height;

  texture = SDL_CreateTextureFromSurface(SDL->renderer, SDL->rocket->image);

  if (texture == 0)
  {
    printf("rocket_move error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if (SDL_RenderCopy(SDL->renderer, texture, &src, &dest) < 0)
  {
    printf("rocket_move error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }  
  SDL->rocket->x += 30;
}

bool              rocket_add(int count, t_SDL_objects *SDL)
{
	int              i;
  	t_rocket         *current;
  	t_rocket         *rocket;
  	SDL_DisplayMode  screen;

  current = SDL->rocket;
  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);
  for (i = 0; i < count; i++)
  {
    rocket_move(SDL);
    rocket = malloc(sizeof(t_rocket));
    if (rocket != NULL)
    {
      rocket->next = NULL;
      rocket->id +=1;
      rocket->width = 49;
      rocket->height = 49;
      rocket->x = screen.w + RAND_RANGE(0, 400);
      rocket->y = RAND_RANGE(0, screen.h);
      rocket->image = IMG_Load("assets/images/flame.png");
      if (rocket->image == NULL)
      {
        printf("rocket init error: %s\n", IMG_GetError());
        return false;
      }
      while (current->next != NULL)
      {
        current = current->next;
      }
      current->next = rocket;
    }
  }
  return true;
}

void              rocket_clear(t_SDL_objects *SDL)
{
  t_rocket         *rocket;
  t_rocket         *tmp;

  rocket = SDL->rocket;
  while (rocket->next != NULL)
  {
    tmp = rocket;
    rocket = rocket->next;
    SDL_FreeSurface(tmp->image);
    free(tmp);
  }
}