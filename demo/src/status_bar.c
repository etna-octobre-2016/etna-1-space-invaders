/*
* @Author: BERTEAUX
* @Date:   2014-09-05 15:19:23
* @Last Modified by:   BERTEAUX
* @Last Modified time: 2014-09-25 21:18:43
*/

#include          "../headers/main.h"

/**
 * Initialise tout ce qui concerne les scores
 * Params :
 *   - t_SDL_objects *SDL
 */
bool              status_bar_init(t_SDL_objects *SDL)
{
  SDL->status_bar = malloc(sizeof(t_status_bar));
  if (SDL->status_bar == NULL)
  {
    return false;
  }
  SDL->status_bar->scores = TTF_OpenFont("assets/font/truelies.ttf", 15);
  if (SDL->status_bar->scores == NULL)
  {
    return false;
  }
  return true;
}

/**
 * Met à jour la barre de vie
 * Params :
 *   - t_SDL_objects *SDL
 */
void              status_bar_update_life(t_SDL_objects *SDL)
{
  SDL_Rect        sourc;
  SDL_Rect        dest;
  SDL_Texture     *texture;
  SDL_DisplayMode screen;
  int             percent;

  SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen);

  percent = 100 - (SDL->ship->life * 100) / SHIP_MAX_LIFE;

  if (percent < 15)
  {
    sourc.y = 0;
  }
  else if (percent < 30)
  {
    sourc.y = 26;
  }
  else if (percent < 45)
  {
    sourc.y = 52;
  }
  else if (percent < 60)
  {
    sourc.y = 78;
  }
  else if (percent < 75)
  {
    sourc.y = 104;
  }
  else if (percent < 90)
  {
    sourc.y = 130;
  }
  else
  {
    sourc.y = 156;
  }

  sourc.x = 0;
  sourc.w = 310;
  sourc.h = 26;
  dest.x = 0;
  dest.y = screen.h - 31;
  dest.w = 310;
  dest.h = 26;

  texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->ship->life_bar);

  if (texture < 0)
  {
    printf("life_bar draw error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
  {
    printf("life_bar draw error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

/**
 * Met à jour le score
 * Params :
 *   - t_SDL_objects *SDL
 */
void              status_bar_update_scores(t_SDL_objects *SDL)
{
  SDL_Surface     *text;
  SDL_Color       color_text;
  SDL_Rect        sourc;
  SDL_Rect        dest;
  SDL_Texture     *texture;
  SDL_DisplayMode screen;
  char            *text_to_print;

  text = NULL;
  text_to_print = malloc(sizeof(char *));

  if (text_to_print != NULL)
  {
    snprintf(text_to_print, 100, "Scores : %d", SDL->level->score);

    color_text.r = 255;
    color_text.g = 255;
    color_text.b = 255;

    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(SDL->window) , &screen); /* @todo: utiliser une variable "globale" à la place */

    text = TTF_RenderText_Blended(SDL->status_bar->scores, text_to_print, color_text);
    texture = SDL_CreateTextureFromSurface(SDL->renderer, text);
    sourc.x = 0;
    sourc.y = 0;
    dest.x = 320;
    dest.y = screen.h - 26;
    dest.w = text->w;
    dest.h = text->h;

    if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
    {
      printf("text error: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    free(text_to_print);
  }
}

/**
 * Clear tout ce qui concerne les scores
 * Params :
 *   - t_SDL_objects *SDL
 */
void              status_bar_clear_scores(t_SDL_objects *SDL)
{
  TTF_CloseFont(SDL->status_bar->scores);
}