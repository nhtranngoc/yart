#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include "color.h"

// Yes, this is duplicate of lcd-dma.h, but it'll work for now.
// Famous Last Words - nhtranngoc
#define LCD_WIDTH  240
#define LCD_HEIGHT 320

#define LCD_PIXEL_SIZE (sizeof(uint32_t))
#define LCD_PIXELS (LCD_WIDTH * LCD_HEIGHT)
#define LCD_BYTES  (LCD_PIXELS * LCD_PIXEL_SIZE)


void clear_canvas(uint32_t *canvas);
void write_pixel(uint32_t *canvas, int x, int y, uint32_t c);

#endif //CANVAS_H_