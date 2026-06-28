#include <engine/engine.h>

#include <stdio.h>


void run(double delta) {
    printf("Engine running, delta: %f\n", delta);
}


int main() {
    engine_init();
    engine_run(run);
    engine_deinit();
}
