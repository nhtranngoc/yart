#include <CppUTest/TestHarness.h>
#include "world.h"

#include <algorithm>

TEST_GROUP(WorldTest) {};

TEST(WorldTest, CreatingAWorld) {
    auto w = World();

    LONGS_EQUAL(0, w.objects.size());
    LONGS_EQUAL(0, w.lights.size());
}

TEST(WorldTest, TheDefaultWorld) {
    auto light = PointLight(Point(-10,10,-10), Color(1,1,1));
    auto s1 = std::make_shared<Sphere>();
    s1->material.color = Color(0.8, 1.0, 0.6);
    s1->material.diffuse = 0.7;
    s1->material.specular = 0.2;

    auto s2 = std::make_shared<Sphere>();
    s2->SetTransform(Scaling(0.5, 0.5, 0.5));

    auto w = World::Default();

    CHECK(w.lights[0] == light);
    // Checking smart pointer equality
    // That's neat!
    CHECK(w.objects[0]->operator==(*s1.get()));
    CHECK(w.objects[1]->operator==(*s2.get()));
}