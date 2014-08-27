/*
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-08-27 15:04:04
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
  SDL->ship->state = STATE_NORMAL;
  SDL->ship->animation.nb_frames = 12;

  /*Parametres generaux*/
  SDL->ship->life = 100;

  /*Config*/
  SDL->ship->image = IMG_Load("assets/images/dracaufeu.png");

  if (SDL->ship->image == NULL)
  {
    printf("Ship init error: %s\n", IMG_GetError());
    return false;
  }
  return true;
}

void          ship_update_image(t_SDL_objects *SDL, int previous_state)
{
  if (SDL->ship->state != previous_state)
  {
    SDL_FreeSurface(SDL->ship->image);
    if (SDL->ship->state == STATE_CRASH)
      SDL->ship->image = IMG_Load("assets/images/dracaufeu_crash.png");
    else if (SDL->ship->state == STATE_NORMAL)
      SDL->ship->image = IMG_Load("assets/images/dracaufeu.png");
    if (SDL->ship->image == NULL)
    {
      printf("Ship init error: %s\n", IMG_GetError());
      exit(EXIT_FAILURE);
    }
  }
}

void          ship_move(int direction, t_SDL_objects *SDL)
{
  switch (direction)
  {
    case SDLK_DOWN:
      SDL->ship->y += 20;
      break;
    case SDLK_UP:
      if (SDL->ship->y - 20 >= 0) SDL->ship->y -= 20;
      break;
    case SDLK_RIGHT:
      SDL->ship->x += 20;
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
  int         previous_state;

  sourc.x = SDL->ship->width * SDL->ship->num_frame;
  sourc.y = 0;
  sourc.w = SDL->ship->width;
  sourc.h = SDL->ship->height;

  dest.x = SDL->ship->x;
  dest.y = SDL->ship->y;
  dest.w = SDL->ship->width;
  dest.h = SDL->ship->height;

  previous_state = SDL->ship->state;

  ship_is_crash(SDL);
  ship_update_image(SDL, previous_state);

  if (SDL->ship->num_frame < SDL->ship->animation.nb_frames)
    SDL->ship->num_frame++;
  else
    SDL->ship->num_frame = 0;

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

bool           ship_is_crash(t_SDL_objects *SDL)
{
  t_enemy *enemy;
  int     ship_x_max;
  int     ship_y_max;

  enemy = SDL->enemy->next;
  ship_x_max = SDL->ship->x + SDL->ship->width;
  ship_y_max = SDL->ship->y + SDL->ship->height;
  while (enemy != NULL)
  {
    if (enemy->x > SDL->ship->x && enemy->x < ship_x_max)
      if (enemy->y > SDL->ship->y && enemy->y < ship_y_max)
      {
        ship_update_life(SDL, -1);
        SDL->ship->state = STATE_CRASH;
        return true;
      }
    enemy = enemy->next;
  }
  SDL->ship->state = STATE_NORMAL;
  return false;
}

void           ship_update_life(t_SDL_objects *SDL, int number)
{
  SDL->ship->life += number;
} 

bool           ship_is_in_life(t_SDL_objects *SDL)
{
  if (SDL->ship->life > 0)
    return true;
  return false;
} 

void          ship_clear(t_SDL_objects *SDL)
{
  SDL_FreeSurface(SDL->ship->image);
  free(SDL->ship);
}