#include "canvas.h"

void clear_canvas(uint32_t *canvas) {
    for(int i = 0; i < LCD_PIXELS; i++) {
        canvas[i] = 0xff000000;
    }
}

void write_pixel(uint32_t *canvas, int x, int y, uint32_t c) {
    int pixel = y * LCD_WIDTH + x;

    canvas[pixel] = c;
}