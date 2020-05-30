#include "canvas.h"

void clear_canvas(uint32_t *canvas) {
    for(int i = 0; i < LCD_PIXELS; i++) {
        canvas[i] = 0xff000000;
    }
}

void write_pixel(uint32_t *canvas, int x, int y, uint32_t c) {
    // Due to how the on-board LCD is mapped, we want to flip the coordinates   
    int pixel = x * LCD_WIDTH + y;

    canvas[pixel] = c;
}