/*
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-25 21:48:47
*/
#include          "../headers/main.h"

bool              ship_init(t_SDL_objects *SDL)
{
  SDL->ship = malloc(sizeof(t_ship));
  SDL->ship->animation = malloc(sizeof(t_animation));

  if (SDL->ship == NULL || SDL->ship->animation == NULL)
  {
    return false;
  }

  /*Position de base*/
  SDL->ship->x = 0;
  SDL->ship->y = 0;
  SDL->ship->num_frame = 0;

  /*Taille d'un déplacement*/
  SDL->ship->width = 150;
  SDL->ship->height = 121;

  /*Animation*/
  SDL->ship->previous_animation = 0;
  SDL->ship->animation = animation_get(SHIP_STATE_NORMAL, SDL);
  if (SDL->ship->animation == NULL)
  {
    return false;
  }

  /*Parametres generaux*/
  SDL->ship->life = SHIP_MAX_LIFE;
  SDL->ship->image = IMG_Load(SDL->ship->animation->url_image);
  SDL->ship->life_bar = IMG_Load("assets/images/barre.png");

  if (SDL->ship->image == NULL || SDL->ship->life_bar == NULL)
  {
    printf("Ship init error: %s\n", IMG_GetError());
    return false;
  }
  return true;
}

/**
 * Mets à jour l'image du vaisseau
 * Params :
 *   - t_SDL_objects *SDL
 */
void              ship_update_image(t_SDL_objects *SDL)
{
  if (SDL->ship->animation->id != SDL->ship->previous_animation)
  {
    SDL_FreeSurface(SDL->ship->image);
    SDL->ship->image = IMG_Load(SDL->ship->animation->url_image);

    if (SDL->ship->image == NULL)
    {
      printf("Ship image update error: %s\n", IMG_GetError());
      exit(EXIT_FAILURE);
    }
  }
}

void              ship_move(t_SDL_objects *SDL)
{
  SDL_DisplayMode screen;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);

  if (events_find_key(SDLK_DOWN) != NULL && events_find_key(SDLK_DOWN)->value == 1)
  {
    if ((SDL->ship->y + 13) < (screen.h - 140))
    {
      SDL->ship->y += 13;
    }
  }
  if (events_find_key(SDLK_UP) != NULL && events_find_key(SDLK_UP)->value == 1)
  {
    if ((SDL->ship->y - 13) >= 0)
    {
      SDL->ship->y -= 13;
    }
  }
  if (events_find_key(SDLK_RIGHT) != NULL && events_find_key(SDLK_RIGHT)->value == 1)
  {
    if ((SDL->ship->x + 13) < (screen.w - 140))
    {
      SDL->ship->x += 13;
    }
  }
  if (events_find_key(SDLK_LEFT) != NULL && events_find_key(SDLK_LEFT)->value == 1)
  {
    if ((SDL->ship->x - 13) >= 0)
    {
      SDL->ship->x -= 13;
    }
  }
}

/**
 * Imprime le vaisseau sur l'écran
 * Params :
 *   - t_SDL_objects *SDL
 */
void              ship_draw(t_SDL_objects *SDL)
{
  SDL_Rect        sourc;
  SDL_Rect        dest;
  SDL_Texture     *texture;

  sourc.x = SDL->ship->width * SDL->ship->num_frame;
  sourc.y = 0;
  sourc.w = SDL->ship->width;
  sourc.h = SDL->ship->height;

  dest.x = SDL->ship->x;
  dest.y = SDL->ship->y;
  dest.w = SDL->ship->width;
  dest.h = SDL->ship->height;

  ship_update_image(SDL);

  if (SDL->ship->num_frame < SDL->ship->animation->nb_frames)
  {
    SDL->ship->num_frame++;
  }
  else
  {
    SDL->ship->num_frame = 0;
  }

  texture = SDL_CreateTextureFromSurface(SDL->renderer, SDL->ship->image);

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

/**
 * Indique si le vaisseau est en collision avec un ennemi
 * Met à jour le statut du vaisseau
 * Params :
 *   - t_SDL_objects *SDL
 *
 * Return bool
 */
bool              ship_is_crashed(t_SDL_objects *SDL)
{
  t_enemy         *enemy;
  int             ship_x_max;
  int             ship_y_max;

  if (SDL->enemy->level == 0)
  {
    return false;
  }
  enemy = SDL->enemy;
  ship_x_max = SDL->ship->x + SDL->ship->width;
  ship_y_max = SDL->ship->y + SDL->ship->height;
  while (enemy->next != NULL)
  {
    if (enemy->x > SDL->ship->x && enemy->x < ship_x_max)
    {
      if (enemy->y > SDL->ship->y && enemy->y < ship_y_max)
      {
        ship_update_life(SDL, -1); /* @todo: remplacer -1 par une constante */
        SDL->ship->previous_animation = SDL->ship->animation->id;
        SDL->ship->animation = animation_get(SHIP_STATE_CRASH, SDL);
        SDL->level->score += enemy->max_life;
        return true;
      }
    }
    enemy = enemy->next;
  }
  SDL->ship->previous_animation = SDL->ship->animation->id;
  SDL->ship->animation = animation_get(SHIP_STATE_NORMAL, SDL);
  return false;
}

/**
 * Mets à jour la vie du vaisseau
 * Params :
 *   - t_SDL_objects *SDL
 *   - int number Quantité de vie à ajouter (Mettre un nombre négatif si l'on veut faire baisser la vie)
 */
void              ship_update_life(t_SDL_objects *SDL, int number)
{
  SDL->ship->life += number;
}

/**
 * Indique si le vaisseau est en vie
 * Params :
 *   - t_SDL_objects *SDL
 *
 * Return bool
 */
bool              ship_is_alive(t_SDL_objects *SDL)
{
  if (SDL->ship->life > 0)
  {
    return true;
  }
  return false;
}

/**
 * Supprime le vaisseau de l'écran
 * Params :
 *   - t_SDL_objects *SDL
 */
void              ship_clear(t_SDL_objects *SDL)
{
  SDL_FreeSurface(SDL->ship->image);
  SDL_FreeSurface(SDL->ship->life_bar);
  free(SDL->ship);
}