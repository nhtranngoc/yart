#include <CppUTest/TestHarness.h>
#include "plane.h"

TEST_GROUP(PlaneTest) {};

TEST(PlaneTest, TheNormalOfAPlaneIsConstantEverywhere) {
    auto p = std::make_shared<Plane>();

    auto n1 = p->LocalNormalAt(Point(0,0,0));
    auto n2 = p->LocalNormalAt(Point(10,0,-10));
    auto n3 = p->LocalNormalAt(Point(-5,0,150));

    CHECK(n1 == Vector(0,1,0));
    CHECK(n2 == Vector(0,1,0));
    CHECK(n3 == Vector(0,1,0));
}

TEST(PlaneTest, IntersectWithARayParallelToThePlane) {
    auto p = std::make_shared<Plane>();
    auto r = Ray(Point(0,10,0), Vector(0,0,1));

    auto xs = p->Intersect(r);

    LONGS_EQUAL(0, xs.size());
}

TEST(PlaneTest, IntersectWithACoplanarRay) {
    auto p = std::make_shared<Plane>();
    auto r = Ray(Point(0,0,0), Vector(0,0,1));

    auto xs = p->Intersect(r);

    LONGS_EQUAL(0, xs.size());
}

TEST(PlaneTest, ARayIntersectingAPlaneFromAbove) {
    auto p = std::make_shared<Plane>();
    auto r = Ray(Point(0,1,0), Vector(0,-1,0));

    auto xs = p->Intersect(r);

    LONGS_EQUAL(1, xs.size());
    DOUBLES_EQUAL(1, xs[0].t, EPSILON);
    CHECK(xs[0].object->operator==(*p.get()));
}

TEST(PlaneTest, ARayIntersectingAPlaneFromBelow) {
    auto p = std::make_shared<Plane>();
    auto r = Ray(Point(0,-1,0), Vector(0,1,0));

    auto xs = p->Intersect(r);

    LONGS_EQUAL(1, xs.size());
    DOUBLES_EQUAL(1, xs[0].t, EPSILON);
    CHECK(xs[0].object->operator==(*p.get()));
}