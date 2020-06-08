#include <CppUTest/TestHarness.h>
#include "camera.h"
#include "ray.h"
#include "transformation.h"
#include "world.h"
#include "canvas.h"

TEST_GROUP(CameraTest) {};

TEST(CameraTest, ConstructingACamera) {
    auto hsize = 160;
    auto vsize = 120;
    auto field_of_view = pi/2;

    auto c = Camera(hsize, vsize, field_of_view);

    LONGS_EQUAL(160, c.hsize);
    LONGS_EQUAL(120, c.vsize);
    DOUBLES_EQUAL(pi/2, c.field_of_view, EPSILON);
    auto m = Matrix<4,4>::Identity();
    CHECK(c.transform == m);
}

TEST(CameraTest, PixelSizeForHorizontalCanvas) {
    auto c = Camera(200, 125, pi/2);

    DOUBLES_EQUAL(0.01, c.pixel_size, EPSILON);
}

TEST(CameraTest, PixelSizeForVerticalCanvas) {
    auto c = Camera(125, 200, pi/2);

    DOUBLES_EQUAL(0.01, c.pixel_size, EPSILON);
}

TEST(CameraTest, ConstructingARayThroughCenterOfCanvas) {
    auto c = Camera(201, 101, pi/2);
    auto r = c.RayForPixel(100, 50);

    CHECK(r.origin == Point(0,0,0));
    CHECK(r.direction == Vector(0,0,-1));
}

TEST(CameraTest, ConstructingARayThroughCornerOfCanvas) {
    auto c = Camera(201, 101, pi/2);
    auto r = c.RayForPixel(0, 0);

    CHECK(r.origin == Point(0,0,0));
    CHECK(r.direction == Vector(0.66519, 0.33259, -0.66851));
}

TEST(CameraTest, ConstructingARayWhenCameraIsTransformed) {
    auto c = Camera(201, 101, pi/2);
    c.transform = RotationY(pi/4) * Translation(0, -2, 5);
    auto r = c.RayForPixel(100, 50);

    CHECK(r.origin == Point(0, 2, -5));
    CHECK(r.direction == Vector(sqrt(2)/2, 0, -sqrt(2)/2));
}

TEST(CameraTest, RenderingAworldWithACamera) {
    auto w = World::Default();
    auto c = Camera(11,11,pi/2);
    auto from = Point(0,0,-5);
    auto to = Point(0,0,0);
    auto up = Vector(0,1,0);

    c.transform = View(from, to, up);
    auto image = c.Render(w);

    CHECK(image.PixelAt(5,5) == Color(0.38066, 0.47583, 0.2855));    
}