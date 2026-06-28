#ifndef ENGINE_H
#define ENGINE_H

typedef enum EngineInitStatus {
    ENGINE_INIT_OK = 0,
    ENGINE_INIT_ERROR_ALREADY_INITIALIZED,
    ENGINE_INIT_ERROR_VIDEO_INIT,
    ENGINE_INIT_ERROR_WINDOW_CREATION
} EngineInitStatus;

EngineInitStatus engine_init(void);
void engine_deinit(void);
void engine_run(void (*callback)(double delta));

#endif // ENGINE_H
