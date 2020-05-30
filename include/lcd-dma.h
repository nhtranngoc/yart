#ifndef LCD_DMA_H
#define LCD_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/ltdc.h>

#include "clock.h"
#include "console.h"
#include "lcd-spi.h"
#include "sdram.h"

#define LCD_WIDTH  240
#define LCD_HEIGHT 320
#define REFRESH_RATE 60 /* Hz */

#define HSYNC       10
#define HBP         20
#define HFP         10

#define VSYNC        2
#define VBP          2
#define VFP          4

/* Layer 1 (bottom layer) is ARGB8888 format, full screen. */

typedef uint32_t layer1_pixel;
#define LCD_LAYER1_PIXFORMAT LTDC_LxPFCR_ARGB8888

layer1_pixel *const lcd_layer1_frame_buffer = (uint32_t *)SDRAM_BASE_ADDRESS;
#define LCD_LAYER1_PIXEL_SIZE (sizeof(layer1_pixel))
#define LCD_LAYER1_WIDTH  LCD_WIDTH
#define LCD_LAYER1_HEIGHT LCD_HEIGHT
#define LCD_LAYER1_PIXELS (LCD_LAYER1_WIDTH * LCD_LAYER1_HEIGHT)
#define LCD_LAYER1_BYTES  (LCD_LAYER1_PIXELS * LCD_LAYER1_PIXEL_SIZE)

extern void lcd_dma_init(void);
void clear(void);

#ifdef __cplusplus
}
#endif

#endif // LCD_DMA_H_