#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include "color.h"

class Color;

class Canvas {
    public:
    uint32_t height, width;
    uint32_t *buffer;
    Canvas(uint32_t, uint32_t);

    void WritePixel(uint32_t, uint32_t, Color);
};

#endif //CANVAS_H_