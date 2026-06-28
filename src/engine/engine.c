#include <engine/engine.h>

#include "engine_struct.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>


Engine engine_instance = {
    .initialized = false,
    .sdl_window = NULL
};


EngineInitStatus engine_init(void) {
    if (engine_instance.initialized) {
        return ENGINE_INIT_ERROR_ALREADY_INITIALIZED;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return ENGINE_INIT_ERROR_VIDEO_INIT;
    }


    SDL_Window *sdl_window = SDL_CreateWindow("Engine", 1280, 720, SDL_WINDOW_HIGH_PIXEL_DENSITY);

    if (!sdl_window) {
        return ENGINE_INIT_ERROR_WINDOW_CREATION;
    }


    engine_instance.initialized = true;
    return ENGINE_INIT_OK;
}


void engine_deinit(void) {
    if (!engine_instance.initialized) {
        return;
    }


    SDL_DestroyWindow(engine_instance.sdl_window);

    SDL_Quit();
    engine_instance.initialized = false;
}


void engine_run(void (*callback)(double)) {
    bool running = true;

    Uint64 last = SDL_GetPerformanceCounter();

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;


                default:
                    break;
            }
        }


        Uint64 now = SDL_GetPerformanceCounter();
        double delta = (now - last) / (double) SDL_GetPerformanceFrequency();
        last = now;


        if (callback) {
            callback(delta);
        }
    }
}
