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

TEST(SphereTest, ComputeNormalOnATranslatedSphere) {
    auto s = std::make_shared<Sphere>();
    s->SetTransform(Translation(0,1,0));

    auto n = s->NormalAt(Point(0, 1.70711, -0.70711));

    CHECK(n == Vector(0, 0.70711, -0.70711));
}

TEST(SphereTest, ComputeNormalOnATransformedSphere) {
    auto s = std::make_shared<Sphere>();
    s->SetTransform(Scaling(1, 0.5, 1) * RotationZ(pi/5));
    
    auto n = s->NormalAt(Point(
        0, 
        (float) sqrt(2) / 2,
        (float) -sqrt(2) / 2));

    CHECK(n == Vector(0, 0.97014, -0.24254));
}

TEST(SphereTest, ASphereHasADefaultMaterial) {
    auto s = std::make_shared<Sphere>();

    auto m = s->material;

    CHECK(m == Material());
}

TEST(SphereTest, ASphereMayBeAssignedAMaterial) {
    auto s = std::make_shared<Sphere>();
    auto m = Material();
    m.ambient = 1;

    s->material = m;
    
    CHECK(s->material == m);
}