#include      "../headers/main.h"

void          enemy_init(t_SDL_objects *SDL)
{
  SDL->enemy = malloc(sizeof(t_enemy));
  SDL->enemy->x = 0;
  SDL->enemy->y = 0;
  SDL->enemy->width = 32;
  SDL->enemy->height = 32;
  SDL->enemy->image = IMG_Load("assets/images/enemy_1.png");
  if (SDL->enemy->image == NULL)
  {
    printf("Enemy init error: %s\n", IMG_GetError());
    exit(EXIT_FAILURE);
  }
}

void          enemy_draw(t_SDL_objects *SDL)
{
  SDL_Rect    src;
  SDL_Rect    dest;
  SDL_Texture *texture;

  src.x = SDL->enemy->x;
  src.y = SDL->enemy->y;
  src.w = SDL->enemy->width;
  src.h = SDL->enemy->height;

  dest.x = SDL->enemy->x;
  dest.y = SDL->enemy->y;
  dest.w = SDL->enemy->width;
  dest.h = SDL->enemy->height;

  texture = SDL_CreateTextureFromSurface(SDL->renderer, SDL->enemy->image);

  if (texture == 0)
  {
    printf("Enemy error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (SDL_RenderCopy(SDL->renderer, texture, &src, &dest) < 0)
  {
    printf("Enemy error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}