#include <CppUTest/TestHarness.h>
#include "pointlight.h"
#include "color.h"
#include "tuple.h"

TEST_GROUP(PointLightTest) {};

TEST(PointLightTest, APointLightHasAPositionAndIntensity) {
    auto intensity = Color(1,1,1);
    auto position = Point(0,0,0);

    auto light = PointLight(position, intensity);

    CHECK(light.position == position);
    CHECK(light.intensity == intensity);
} 