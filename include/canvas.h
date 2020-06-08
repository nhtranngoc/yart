#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include "color.h"

class Color;

class Canvas {
    public:
    uint32_t height, width;
    Canvas(uint32_t height_, uint32_t width_):
        height(height_),
        width(width_) {}

    void Init(uint32_t *);
    void WritePixel(uint32_t *, uint32_t, uint32_t, Color);
    uint32_t PixelAt(uint32_t *, uint32_t, uint32_t);
};

#endif //CANVAS_H_