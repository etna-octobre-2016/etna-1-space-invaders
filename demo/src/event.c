/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   Bernar_s
* @Last Modified time: 2014-09-03 15:45:10
*/

#include      "../headers/main.h"

t_events_hash *key_event = NULL;

/**
* retrouve une structure en fonction de la clé entré en paramètre
*/
t_events_hash   *events_find_key(int key)
{
  t_events_hash *h;

  HASH_FIND_INT(key_event, &key, h);
  return h;
}

/**
* Ajoute une structure à la table de hash
*/
void            events_add_key(int key_push, int value)
{
  t_events_hash *h;

  HASH_FIND_INT(key_event, &key_push, h);
  if (h == NULL)
  {
    h = malloc(sizeof(t_events_hash));
    h->key = key_push;
    HASH_ADD_INT(key_event, key, h);
  }
  h->value = value;
}

/**
* Supprime toutes les structures de la table de hash
*/
void            events_clear()
{
  t_events_hash *current_key;
  t_events_hash *tmp;

  HASH_ITER(hh, key_event, current_key, tmp)
  {
    HASH_DEL(key_event, current_key);
    free(current_key);
  }
}

void            events_update(SDL_Event event)
{
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
        events_add_key(event.key.keysym.sym, 1);
        break;
      case SDL_KEYUP:
        events_add_key(event.key.keysym.sym, 0);
        break;
      default:
        break;
    }
  }
}