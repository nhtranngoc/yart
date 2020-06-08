#include "canvas.h"

void Canvas::WritePixel(uint32_t x, uint32_t y, Color c) {
    // Due to how the on-board LCD is mapped, we want to flip the coordinates   
    auto pixel = x * this->width + y;

    this->buffer[pixel] = c.toHex();
}

uint32_t Canvas::PixelAt(uint32_t x, uint32_t y) {
    auto pixel = x * this->width + y;
    return this->buffer[pixel];
}