#include <CppUTest/TestHarness.h>
#include "ray.cpp"
#include "sphere.cpp"
// #include "transformation.cpp"

#define EPSILON 0.0001

TEST_GROUP(RayTest){};

TEST(RayTest, CreateAndQueryARay) {
    Tuple origin = Point(1,2,3);
    Tuple direction = Vector(4,5,6);

    Ray r = Ray(origin, direction);

    CHECK(r.origin == origin);
    CHECK(r.direction == direction);
}

TEST(RayTest, ComputeAPointFromADistance) {
    Ray r = Ray(Point(2,3,4), Vector(1,0,0));

    CHECK(r.Position(0) == Point(2,3,4));
    CHECK(r.Position(1) == Point(3,3,4));
    CHECK(r.Position(-1) == Point(1,3,4));
    CHECK(r.Position(2.5) == Point(4.5,3,4));
}

TEST(RayTest, RayIntersectsASphereAtTwoPoints) {
    Ray r = Ray(Point(0,0,-5), Vector(0,0,1));

    // Smart pointer
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(xs[0].t, 4, EPSILON);
    DOUBLES_EQUAL(xs[1].t, 6, EPSILON);
}

TEST(RayTest, RayIntersectsASphereAtATangent) {
    Ray r = Ray(Point(0,1,-5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(xs[0].t, 5, EPSILON);
    DOUBLES_EQUAL(xs[1].t, 5, EPSILON);
}

TEST(RayTest, RayMissesASphere) {
    Ray r = Ray(Point(0,2,-5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(0, xs.size());
}

TEST(RayTest, RayOriginatesInsideASphere) {
    Ray r = Ray(Point(0,0,0), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(xs[0].t, -1, EPSILON);
    DOUBLES_EQUAL(xs[1].t, 1, EPSILON);
}

TEST(RayTest, SphereBehindARay) {
    Ray r = Ray(Point(0,0,5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    DOUBLES_EQUAL(xs[0].t, -6, EPSILON);
    DOUBLES_EQUAL(xs[1].t, -4, EPSILON);
}

TEST(RayTest, IntersectSetsTheObjectOnTheIntersection) {
    Ray r = Ray(Point(0,0,-5), Vector(0,0,1));
    auto s = std::make_shared<Sphere>();

    auto xs = s->Intersect(r);

    LONGS_EQUAL(2, xs.size());
    CHECK(xs[0].object == s);
    CHECK(xs[1].object == s);
}

TEST(RayTest, TranslatingARay) {
    auto r = Ray(Point(1,2,3), Vector(0,1,0));
    auto m = Translation(3,4,5);

    auto r2 = r.Transform(m);

    CHECK(r2.origin == Point(4,6,8));
    CHECK(r2.direction == Vector(0,1,0));

}

TEST(RayTest, ScalingARay) {
    auto r = Ray(Point(1,2,3), Vector(0,1,0));
    auto m = Scaling(2,3,4);

    auto r2 = r.Transform(m);

    CHECK(r2.origin == Point(2,6,12));
    CHECK(r2.direction == Vector(0,3,0));
}

TEST(RayTest, ASpheresDefaultTransformation) {
    auto s = std::make_shared<Sphere>();
    auto identity = Matrix<4,4>::Identity();
    CHECK(s->transform == identity);
}

TEST(RayTest, ChangingASpheresDefaultTransformation) {
    auto s = std::make_shared<Sphere>();

    Matrix<4,4> t = Translation(2,3,4);

    s->SetTransform(t);

    CHECK(s->transform == t);
}