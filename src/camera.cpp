#include "camera.h"

Camera::Camera(uint32_t hsize_, uint32_t vsize_, float field_of_view_) {
    this->hsize = hsize_;
    this->vsize = vsize_;
    this->field_of_view = field_of_view_;
    this->transform = Matrix<4,4>::Identity();

    float half_view = std::tan(field_of_view_ / 2);
    float aspect = (float) this->hsize / this->vsize;

    if(aspect >= 1.0) {
        this->half_width = half_view;
        this->half_height = half_view / aspect;
    } else {
        this->half_width = half_view * aspect;
        this->half_height = half_view;
    }
    
    this->pixel_size = (this->half_width * 2) / this->hsize;
}

Ray Camera::RayForPixel(uint32_t const px, uint32_t const py) {
    // Offset from the edge of the map to pixel's center
    float xoffset = (px + 0.5) * this->pixel_size;
    float yoffset = (py + 0.5) * this->pixel_size;

    // Untransformed coordinates of the pixel in world space
    // Camera looks toward -z, so +x is to the left
    float world_x = this->half_width - xoffset;
    float world_y = this->half_height - yoffset;

    // Using the camera matrix, transform the canvas point and origin,
    // Then compute the ray's direction vector
    // Canvas is at z = -1
    auto pixel = this->transform.Inverse() * Point(world_x, world_y, -1);
    auto origin = this->transform.Inverse() * Point(0,0,0);
    auto direction = (pixel - origin).Normalize();

    return Ray(origin, direction);
}

Canvas Camera::Render(uint32_t *canvas, World &w) {
    auto image = Canvas(this->hsize, this->vsize);

    for(auto y = 0; y < this->vsize; y++) {
        for(auto x = 0; x < this->hsize; x++) {
            auto ray = this->RayForPixel(x, y);
            auto color = w.ColorAt(ray);

            image.WritePixel(canvas, x, y, color);
        }
    }

    return image;
}