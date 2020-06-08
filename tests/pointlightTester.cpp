#include <CppUTest/TestHarness.h>
#include "pointlight.h"
#include "color.h"
#include "tuple.h"
#include "material.h"

Material m;
Tuple position;

TEST_GROUP(PointLightTest) {
    void setup() {
        m = Material();
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
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));

    auto result = Lighting(m, light, position, eyev, normalv);

    CHECK(result == Color(1.9, 1.9, 1.9));
}

TEST(PointLightTest, LightingWithEyeBetweenLightAndSurfaceOffset45) {
    auto eyev = Vector(
        0,
        (float) sqrt(2) / 2,
        (float) -sqrt(2) / 2);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));

    auto result = Lighting(m, light, position, eyev, normalv);

    CHECK(result == Color(1,1,1));

}

TEST(PointLightTest, LightingWithEyeOppositeSurfaceLightOffset45) {
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,10,-10), Color(1,1,1));

    auto result = Lighting(m, light, position, eyev, normalv);

    CHECK(result == Color(0.7364, 0.7364, 0.7364));
}

TEST(PointLightTest, LightingWithEyeInPathOfReflectionVector) {
    auto eyev = Vector(
        0,
        (float) -sqrt(2) / 2,
        (float) -sqrt(2) / 2);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,10,-10), Color(1,1,1));

    auto result = Lighting(m, light, position, eyev, normalv);

    CHECK(result == Color(1.6364, 1.6364, 1.6364));
}

TEST(PointLightTest, LightingWithLightBehindSurface) {
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,10), Color(1,1,1));

    auto result = Lighting(m, light, position, eyev, normalv);

    CHECK(result == Color(0.1, 0.1, 0.1));
}

TEST(PointLightTest, LightingWithTheSurfaceInShadow) {
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color(1,1,1));
    auto in_shadow = true;

    auto result = Lighting(m, light, position, eyev, normalv, in_shadow);

    CHECK(result == Color(0.1, 0.1, 0.1));
}