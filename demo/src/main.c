#include            "../headers/main.h"
#include            "../headers/window.h"

int                 main()
{
  t_SDL_objects     SDL;

  init_ship(&SDL);

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
  SDL_Surface *ship;
  SDL_Rect pos;
  SDL_Texture *text;

  pos.x = SDL->ship->x;
  pos.y = SDL->ship->y;
  pos.w = SDL->ship->width;
  pos.h = SDL->ship->height;

  SDL_RenderClear(SDL->renderer);

  ship = IMG_Load("assets/images/dracaufeu.png");
  if(!ship) {
    printf("Image non chargée");
    exit(EXIT_FAILURE);
  }

  text = SDL_CreateTextureFromSurface(SDL->renderer,ship);
  if (text < 0){
    printf("Texture non chargée");
    exit(EXIT_FAILURE);
  }
  if (SDL_RenderCopy(SDL->renderer, text, NULL, &pos) < 0){
    printf("RenderCopy non chargée");
    exit(EXIT_FAILURE);
  }


  SDL_Event     event;
  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
  {
    switch (event.key.keysym.sym) {
      case SDLK_DOWN:
        SDL->ship->y += SDL->ship->height;
        break;
      case SDLK_UP:
        SDL->ship->y -= SDL->ship->height;
        break;
      case SDLK_RIGHT:
        SDL->ship->x += SDL->ship->width;
        break;
      case SDLK_LEFT:
        SDL->ship->x -= SDL->ship->width;
        break;
    }
  }

  SDL_RenderPresent(SDL->renderer);
  SDL_FreeSurface(ship);
  /*Fin*/

  
  /*printf("voici mon code une fois que tout est bon\n");
  printf("title = %s\n", SDL_GetWindowTitle(SDL->window));*/
}

void                clear(t_SDL_objects *SDL)
{
  if (SDL->renderer != NULL)
  {
    SDL_DestroyRenderer(SDL->renderer);
  }
  if (SDL->window != NULL)
  {
    SDL_DestroyWindow(SDL->window);
  }
  SDL_Quit();
}