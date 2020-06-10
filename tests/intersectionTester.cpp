#include <CppUTest/TestHarness.h>
#include "intersection.h"
#include "sphere.h"

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

TEST(IntersectionTest, HitAllIntersectionsHavePositiveT) {
    auto s = std::make_shared<Sphere>();
    auto i1 = Intersection(1,s);
    auto i2 = Intersection(2, s);
    auto xs = Intersections(i2, i1);

    auto i = Hit(xs);

    CHECK(i == i1);
}

TEST(IntersectionTest, HitSomeIntersectionsHaveNegativeT) {
    auto s = std::make_shared<Sphere>();
    auto i1 = Intersection(-1, s);
    auto i2 = Intersection(1, s);
    auto xs = Intersections(i2, i1);

    auto i = Hit(xs);

    CHECK(i == i2);
}

TEST(IntersectionTest, HitAllIntersectionsHaveNegativeT) {
    auto s = std::make_shared<Sphere>();
    auto i1 = Intersection(-2, s);
    auto i2 = Intersection(-1, s);
    auto xs = Intersections(i2, i1);

    auto i = Hit(xs);

    CHECK(i.t == 0);
    CHECK(i.object == nullptr);
}

TEST(IntersectionTest, HitIsAlwaysLowestNonnegativeIntersection) {
    auto s = std::make_shared<Sphere>();
    auto i1 = Intersection(5, s);
    auto i2 = Intersection(7, s);
    auto i3 = Intersection(-3, s);
    auto i4 = Intersection(2, s);
    auto xs = Intersections(i1, i2, i3, i4);

    auto i = Hit(xs);

    CHECK(i == i4);
}

TEST(IntersectionTest, IntersectingAScaledSphereWithARay) {
    auto r = Ray(Point(0,0,-5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    s->SetTransform(Scaling(2,2,2));
    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(3, xs[0].t, EPSILON);
    DOUBLES_EQUAL(7, xs[1].t, EPSILON);
}

TEST(IntersectionTest, IntersectingATranslatedSphereWithARay) {
    auto r = Ray(Point(0,0,-5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    s->SetTransform(Translation(5,0,0));
    auto xs = s->Intersect(r);

    LONGS_EQUAL(0, xs.size());
}