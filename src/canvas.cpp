#include "canvas.h"

void Canvas::Init(uint32_t *buffer) {
    for(uint32_t pix = 0; pix < (this->width * this->height); pix++) {
        buffer[pix] = 0xff000000;   
    }
}

void Canvas::WritePixel(uint32_t *buffer, uint32_t x, uint32_t y, Color c) {
    // Due to how the on-board LCD is mapped, we want to flip the coordinates   
    auto pixel = x * this->width + y;

    buffer[pixel] = c.toHex();
}

uint32_t Canvas::PixelAt(uint32_t *buffer, uint32_t x, uint32_t y) {
    auto pixel = x * this->width + y;
    return buffer[pixel];
}