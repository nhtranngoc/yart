#include <CppUTest/TestHarness.h>
#include "intersection.cpp"

#define EPSILON 0.0001

TEST_GROUP(IntersectionTest){};

TEST(IntersectionTest, AnIntersectionEncapsulateTAndObject) {
    auto s = std::make_shared<Sphere>();
    auto i = Intersection(3.5, s);

    DOUBLES_EQUAL(i.t, 3.5, EPSILON);
    CHECK(i.object == s);
}

TEST(IntersectionTest, AggregatingIntersections) {
    auto s = std::make_shared<Sphere>();
    auto i1 = Intersection(1, s);
    auto i2 = Intersection(2, s);

    auto xs = Intersections(i1, i2);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(xs[0].t, 1, EPSILON);
    DOUBLES_EQUAL(xs[1].t, 2, EPSILON);
}