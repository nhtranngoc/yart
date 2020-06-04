#include "clock.h"
#include "console.h"
#include "lcd-spi.h"
#include "sdram.h"
#include "lcd-dma.h"

#include "tuple.h"
#include "matrix.h"
#include "color.h"
#include "canvas.h"
#include "transformation.h"

layer1_pixel *const raytracer_canvas = (uint32_t *)SDRAM_BASE_ADDRESS;

struct Projectile {
	Tuple pos;
	Tuple velocity;
	// Using member initializer list
	Projectile(Tuple const &pos_, Tuple const &velocity_):
		pos(pos_),
		velocity(velocity_) {}
};

struct Environment {
	Tuple gravity;
	Tuple wind;

	Environment(Tuple const &gravity_, Tuple const &wind_):
		gravity(gravity_),
		wind(wind_) {}
};

static void tick(Environment const &e, Projectile &p) {
	p.pos = p.pos + p.velocity;
	p.velocity = p.velocity + e.gravity + e.wind;
}

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
	clear_canvas(raytracer_canvas);
	printf("Initialized.\n");
	
	// Draw origin point
	Tuple origin = Point(LCD_HEIGHT/2,0,LCD_WIDTH/2);
	write_pixel(raytracer_canvas, (uint32_t) origin.x, (uint32_t) origin.z, Color(0,0,1).toHex());
	// Initial point on the "circle"
	Tuple twelve = Point(0,0,1);
	float radius = (float) LCD_WIDTH * 3 / 8; // 90 pixel

	const int points = 12;

	for(int i = 0; i < points; i++) {
		Matrix<4,4> r = RotationY(i * pi*2/points);
		// Hours
		Tuple hour = r * twelve;
		// Multiply by radius and add offset
		hour.x = ((float)hour.x * radius) + origin.x;
		hour.z = ((float)hour.z * radius) + origin.z;

		write_pixel(raytracer_canvas, (uint32_t) hour.x, (uint32_t) hour.z, Color(1,0,0).toHex());
	}


	while (1) {
		continue;
	}
}
