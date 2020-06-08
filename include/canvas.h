#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include <vector>
#include "color.h"

class Color;

class Canvas {
    public:
    uint32_t height, width;
    std::vector<uint32_t> buffer;
    Canvas(uint32_t height_, uint32_t width_):
        height(height_),
        width(width_),
        buffer(height_ * width_, 0xff000000) {}

    void WritePixel(uint32_t, uint32_t, Color);
    uint32_t PixelAt(uint32_t, uint32_t);
};

#endif //CANVAS_H_