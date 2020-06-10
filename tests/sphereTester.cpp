#include <CppUTest/TestHarness.h>
#include "sphere.h"
#include "material.h"

TEST_GROUP(SphereTest) {};

TEST(SphereTest, NormalOnAsphereAtAPointOnTheXAxis) {
    auto s = std::make_shared<Sphere>();

    auto n = s->NormalAt(Point(1,0,0));

    CHECK(n == Vector(1,0,0));
}

TEST(SphereTest, NormalOnASphereAtAPointOnTheYAxis) {
    auto s = std::make_shared<Sphere>();

    auto n = s->NormalAt(Point(0,1,0));

    CHECK(n == Vector(0,1,0));
}

TEST(SphereTest, NormalOnASphereAtAPointOnTheZAxis) {
    auto s = std::make_shared<Sphere>();

    auto n = s->NormalAt(Point(0,0,1));

    CHECK(n == Vector(0,0,1));
}

TEST(SphereTest, NormalOnASphereAtANonaxialPoint) {
    auto s = std::make_shared<Sphere>();

    auto n = s->NormalAt(Point(
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3
    ));

    CHECK(n == Vector(
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3
    ));
}

TEST(SphereTest, NormalIsANormalizedVector) {
    auto s = std::make_shared<Sphere>();

    auto n = s->NormalAt(Point(
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3,
        (float) sqrt(3) / 3
    ));

    CHECK(n == n.Normalize());
}