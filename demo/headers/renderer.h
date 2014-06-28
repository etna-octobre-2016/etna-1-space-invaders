#ifndef RENDERER_H
#define RENDERER_H
    #include    <stdio.h>
    #include    <stdbool.h>
    #include    <SDL2.framework/Headers/SDL.h>

    #define     RENDERER_FLAGS 0

    void        renderer_init(SDL_Window *, void (*)());
#endif