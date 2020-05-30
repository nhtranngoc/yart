#include "clock.h"
#include "console.h"
#include "lcd-spi.h"
#include "sdram.h"
#include "lcd-dma.h"

#include "tuple.h"
#include "color.h"
#include "canvas.h"

layer1_pixel *const raytracer_canvas = (uint32_t *)SDRAM_BASE_ADDRESS;

int main(int argc, char **argv) {
	/* init timers. */
	clock_setup();

	/* set up USART 1. */
	console_setup(115200);
	console_stdio_setup();

	/* set up SDRAM. */
	sdram_init();

	printf("Preloading frame buffers\n");

	printf("Initializing LCD\n");

	lcd_dma_init(raytracer_canvas);
	lcd_spi_init();

	printf("Initialized. Test\n");
	
	clear_canvas(raytracer_canvas);

	write_pixel(raytracer_canvas, 50, 50, Color(1,0,0).toHex());

	while (1) {
		continue;
	}
}
