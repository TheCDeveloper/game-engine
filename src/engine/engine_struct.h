#ifndef ENGINE_STRUCT_H
#define ENGINE_STRUCT_H

#include <stdbool.h>

typedef struct SDL_Window SDL_Window;

typedef struct Engine {
    bool initialized;
    SDL_Window *sdl_window;
} Engine;

extern Engine engine_instance;

#endif // ENGINE_STRUCT_H
