/*
* @Author: ahemt_s
* @Date:   2014-07-27 21:35:00
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-28 21:12:43
*/
#ifndef LEVEL_H
#define LEVEL_H
    bool  level_init(int, t_SDL_objects *);
    bool  level_events_init(t_SDL_objects *);
    bool  level_1_events_init(t_SDL_objects *);
    void  level_clear(t_SDL_objects *);
#endif
