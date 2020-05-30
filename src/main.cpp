#include "clock.h"
#include "console.h"
#include "lcd-spi.h"
#include "sdram.h"
#include "lcd-dma.h"

#include "tuple.h"
#include "color.h"
#include "canvas.h"

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
	
	printf("Initializing environment and projectile.\n");
	Projectile p(Point(0,1,0), Vector(3,3,0));
	Environment e(Vector(0,-0.1,0), Vector(-0.01,0,0));
	printf("Initialized.\n");

	printf("Drawing...\n");
	while(p.pos.y > 0) {
		write_pixel(raytracer_canvas, (int) p.pos.x, (int) p.pos.y, Color(1,0,0).toHex());
		tick(e, p);
		milli_sleep(50);
	}
	printf("Finished drawing!\n");

	while (1) {
		continue;
	}
}
