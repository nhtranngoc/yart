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
#include "material.h"
#include "pointlight.h"
#include "world.h"
#include "camera.h"

#define CANVAS_ORIGINX (LCD_HEIGHT/2)
#define CANVAS_ORIGINY (LCD_WIDTH/2)

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
	auto image = Canvas(LCD_HEIGHT, LCD_WIDTH);
	lcd_dma_init(raytracer_canvas);
	lcd_spi_init();
	image.Init(raytracer_canvas);
	printf("Initialized.\n");
	
	// Draw origin point - this is mostly for testing purposes
	Tuple origin = Point(CANVAS_ORIGINX,0,CANVAS_ORIGINY);
	image.WritePixel(raytracer_canvas, (uint32_t) origin.x, (uint32_t) origin.z, Color::Blue());
	
	// The floor is an extremely flattened sphere with a matte texture
	auto floor = std::make_shared<Sphere>();
	floor->SetTransform(Scaling(10,0.01,10));
	floor->material = Material();
	floor->material.color = Color(1,0.9,0.9);
	floor->material.specular = 0.f;

	// The wall on the left has the same scale and color as 
	// the floor, but rotated and translated to place
	auto left_wall = std::make_shared<Sphere>();
	left_wall->SetTransform(
		Translation(0,0,5) * 
		RotationY(-pi/4) * 
		RotationX(pi/2) *
		Scaling(10, 0.01, 10));
	left_wall->material = Material();
	left_wall->material.color = Color(1,0.9,0.9);
	left_wall->material.specular = 0.f;

	// The wall on the right is idential to left wall, but 
	// is rotated the opposite direction in y.
	auto right_wall = std::make_shared<Sphere>();
	right_wall->SetTransform(
		Translation(0,0,5) * 
		RotationY(pi/4) * 
		RotationX(pi/2) *
		Scaling(10, 0.01, 10));
	right_wall->material = Material();
	right_wall->material.color = Color(1,0.9,0.9);
	right_wall->material.specular = 0.f;

	// The large sphere in the middle is a unit sphere
	// translated upward slightly and colored green
	auto middle = std::make_shared<Sphere>();
	middle->SetTransform(Translation(-0.5,1,0.5));
	middle->material = Material();
	middle->material.color = Color(0.1,1,0.5);
	middle->material.diffuse = 0.7f;
	middle->material.specular = 0.3f;

	// The smaller green sphere on the right is scaled in half
	auto right = std::make_shared<Sphere>();
	right->SetTransform(Translation(1.5,0.5,-0.5) * Scaling(0.5,0.5,0.5));
	right->material = Material();
	right->material.color = Color(0.5,1,0.1);
	right->material.diffuse = 0.7f;
	right->material.specular = 0.3f;

	// The smallest sphere is scaled by a third, before being translated
	auto left = std::make_shared<Sphere>();
	left->SetTransform(Translation(-1.5,0.33,-0.75) * Scaling(0.33,0.33,0.33));
	left->material = Material();
	left->material.color = Color(1,0.1,0.1);
	left->material.diffuse = 0.7f;
	left->material.specular = 0.3f;

	// The light source is white, shining from above and to the left
	auto w = World();
	w.lights.push_back(PointLight(Point(-10,10,-10), Color::White()));
	w.objects.insert(w.objects.end(), {floor, left_wall, right_wall, middle, right, left});

	auto camera = Camera(LCD_HEIGHT, LCD_WIDTH, pi/3);
	camera.transform = View(
		Point(0,1.5,-5),
		Point(0,1,0),
		Vector(0,1,0)
	);
	
	auto canvas = camera.Render(raytracer_canvas, w);

	while (1) {
		continue;
	}
}
