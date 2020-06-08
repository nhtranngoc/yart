#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>
#include <cmath>
#include <math.h>
#include "matrix.h"
#include "ray.h"
#include "canvas.h"
#include "world.h"

class Ray;
class Canvas;
class World;

class Camera {
    public:
    uint32_t hsize, vsize;
    float field_of_view, pixel_size;
    float half_width, half_height;
    Matrix<4,4> transform;  

    Camera(uint32_t hsize_, uint32_t vsize_, float field_of_view_);

    Ray RayForPixel(uint32_t const, uint32_t const);
    Canvas Render(World &w);
};

#endif //CAMERA_H_