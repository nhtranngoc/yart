#include "clock.h"
#include "console.h"
#include "lcd-spi.h"
#include "sdram.h"
#include "lcd-dma.h"

#include "tuple.h"
#include "matrix.h"
#include "color.h"
#include "canvas.h"
#include "sphere.h"
#include "intersection.h"
#include "transformation.h"

#define CANVAS_ORIGINX (LCD_HEIGHT/2)
#define CANVAS_ORIGINY (LCD_WIDTH/2)

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
	Tuple origin = Point(CANVAS_ORIGINX,0,CANVAS_ORIGINY);
	write_pixel(raytracer_canvas, origin.x, origin.z, Color(0,0,1).toHex());
	// Tuple ray_origin = Point(CANVAS_ORIGINY, 0, CANVAS_ORIGINY-5);
	Tuple ray_origin = Point(0,0,-5);
	// write_pixel(raytracer_canvas, ray_origin.x, ray_origin.z, Color(0,1,0).toHex());


	float wall_z = 10;
	float wall_size = 7;

	float canvas_pixels = 240;
	float pixel_size = wall_size / canvas_pixels;
	float half = wall_size / 2;

	auto color = Color(1,0,0);
	auto shape = std::make_shared<Sphere>();
	shape->SetTransform(Shearing(1,0,0,0,0,0) * Scaling(0.5,1,1));

	for(int y = 0; y < canvas_pixels; y++) {
		float world_y = half - pixel_size * y;
		for(int x = 0; x < canvas_pixels; x++) {
			float world_x = -half + pixel_size * x;

			auto position = Point(world_x, world_y, wall_z);

			auto r = Ray(ray_origin, (position - ray_origin).Normalize());
			auto xs = shape->Intersect(r);

			if(!equal(Hit(xs).t, 0)) {
				// printf("Hit! At x: %d, y: %d\n", x, y);
				write_pixel(raytracer_canvas, x, y, color.toHex());
			}
			//  else {
			// 	printf("Missed!\n");
			// }
		}
	}

	while (1) {
		continue;
	}
}
