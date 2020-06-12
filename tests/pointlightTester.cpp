#include <CppUTest/TestHarness.h>
#include "pointlight.h"
#include "color.h"
#include "tuple.h"
#include "material.h"
#include "sphere.h"

Tuple position;

TEST_GROUP(PointLightTest) {
    void setup() {
        position = Point(0,0,0);
    }
};

TEST(PointLightTest, APointLightHasAPositionAndIntensity) {
    auto intensity = Color(1,1,1);

    auto light = PointLight(position, intensity);

    CHECK(light.position == position);
    CHECK(light.intensity == intensity);
}

TEST(PointLightTest, LightingWithEyeBetweenLightAndSurface) {
    auto m = Material();
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();

    auto result = Lighting(m, object, light, position, eyev, normalv);

    CHECK(result == Color(1.9, 1.9, 1.9));
}

TEST(PointLightTest, LightingWithEyeBetweenLightAndSurfaceOffset45) {
    auto m = Material();
    auto eyev = Vector(
        0,
        (float) sqrt(2) / 2,
        (float) -sqrt(2) / 2);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();

    auto result = Lighting(m, object, light, position, eyev, normalv);

    CHECK(result == Color(1,1,1));

}

TEST(PointLightTest, LightingWithEyeOppositeSurfaceLightOffset45) {
    auto m = Material();
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,10,-10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();

    auto result = Lighting(m, object, light, position, eyev, normalv);

    CHECK(result == Color(0.7364, 0.7364, 0.7364));
}

TEST(PointLightTest, LightingWithEyeInPathOfReflectionVector) {
    auto m = Material();
    auto eyev = Vector(
        0,
        (float) -sqrt(2) / 2,
        (float) -sqrt(2) / 2);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,10,-10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();

    auto result = Lighting(m, object, light, position, eyev, normalv);

    CHECK(result == Color(1.6364, 1.6364, 1.6364));
}

TEST(PointLightTest, LightingWithLightBehindSurface) {
    auto m = Material();
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();

    auto result = Lighting(m, object, light, position, eyev, normalv);

    CHECK(result == Color(0.1, 0.1, 0.1));
}

TEST(PointLightTest, LightingWithTheSurfaceInShadow) {
    auto m = Material();
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));
    auto object = std::make_shared<Sphere>();
    auto in_shadow = true;

    auto result = Lighting(m, object, light, position, eyev, normalv, in_shadow);

    CHECK(result == Color(0.1, 0.1, 0.1));
}