#include "canvas.h"

Canvas::Canvas(uint32_t height_, uint32_t width_) {
    this->height = height_;
    this->width = width_;

    uint32_t pixels = height_ * width_;
    
    this->buffer = (uint32_t *) malloc(pixels * sizeof(uint32_t));

    for(auto i = 0; i < pixels; i++) {
        this->buffer[i] = 0xff000000;
    }
}

void Canvas::WritePixel(uint32_t x, uint32_t y, Color c) {
    // Due to how the on-board LCD is mapped, we want to flip the coordinates   
    int pixel = x * this->width + y;

    this->buffer[pixel] = c.toHex();
}