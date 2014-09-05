/*
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-05 15:19:39
*/

#include      "../headers/main.h"

bool          ship_init(t_SDL_objects *SDL)
{
  SDL->ship = malloc(sizeof(t_ship));

  /*Position de base*/
  SDL->ship->x = 0;
  SDL->ship->y = 0;
  SDL->ship->num_frame = 0;

  /*Taille d'un déplacement*/
  SDL->ship->width  = 150;
  SDL->ship->height = 121;

  /*Animation*/
  SDL->ship->animation.nb_frames = 12;

  /*Config*/
  SDL->ship->life         = MAX_LIFE;
  SDL->ship->image        = IMG_Load("assets/images/dracaufeu.png");
  SDL->ship->progress_bar = IMG_Load("assets/images/barre.png");

  if (SDL->ship->image == NULL || SDL->ship->progress_bar == NULL)
  {
    printf("Ship init error: %s\n", IMG_GetError());
    return false;
  }

  return true;
}

void          ship_move(int direction, t_SDL_objects *SDL)
{
  SDL_DisplayMode screen;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);

  switch (direction)
  {
    case SDLK_DOWN:
      if (SDL->ship->y + 20 < screen.h - 140) SDL->ship->y += 20;
      break;
    case SDLK_UP:
      if (SDL->ship->y - 20 >= 0) SDL->ship->y -= 20;
      break;
    case SDLK_RIGHT:
      if (SDL->ship->x + 20 < screen.w - 140)SDL->ship->x += 20;
      break;
    case SDLK_LEFT:
      if (SDL->ship->x - 20 >= 0) SDL->ship->x -= 20;
      break;
  }
}

void          ship_draw(t_SDL_objects *SDL)
{
  SDL_Rect    sourc;
  SDL_Rect    dest;
  SDL_Texture *texture;

  sourc.x = SDL->ship->width * SDL->ship->num_frame;
  sourc.y = 0;
  sourc.w = SDL->ship->width;
  sourc.h = SDL->ship->height;

  dest.x = SDL->ship->x;
  dest.y = SDL->ship->y;
  dest.w = SDL->ship->width;
  dest.h = SDL->ship->height;

  if (SDL->ship->num_frame < SDL->ship->animation.nb_frames)
  {
    SDL->ship->num_frame++;
  }
  else
  {
    SDL->ship->num_frame = 0;
  }

  texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->ship->image);

  if (texture < 0)
  {
    printf("Ship draw error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
  {
    printf("Ship draw error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void          ship_clear(t_SDL_objects *SDL)
{
  SDL_FreeSurface(SDL->ship->image);
  SDL_FreeSurface(SDL->ship->progress_bar);
  free(SDL->ship);
}