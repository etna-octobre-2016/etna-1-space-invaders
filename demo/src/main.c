#include            "../headers/main.h"
#include            "../headers/window.h"

int                 main()
{
  t_SDL_objects     SDL;

  if (!(SDL_Init(SDL_INIT_VIDEO) < 0))
  {
    window_init(&SDL, &init_success);
    clear(&SDL);
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("SDL init error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
}

void                init_success(t_SDL_objects *SDL)
{
  /*Test de chargement d'une image*/
  SDL_Surface *hero = NULL;

  hero = IMG_Load("assets/images/dracaufeu.png");
  if(!hero) {
    printf("Image non chargée");
    exit(EXIT_FAILURE);
  }

  if (SDL_BlitSurface(hero, NULL, SDL->surface, NULL) < 0){
    printf("echec %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_UpdateWindowSurface(SDL->window);
  /*Fin*/
  
  printf("voici mon code une fois que tout est bon\n");
  printf("title = %s\n", SDL_GetWindowTitle(SDL->window));
}

void                clear(t_SDL_objects *SDL)
{
  if (SDL->surface != NULL)
  {
    SDL_FreeSurface(SDL->surface);
  }
  if (SDL->window != NULL)
  {
    SDL_DestroyWindow(SDL->window);
  }
  SDL_Quit();
}