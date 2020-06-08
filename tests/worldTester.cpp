#include <CppUTest/TestHarness.h>
#include "world.h"
#include "ray.h"
#include "intersection.h"

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

TEST(WorldTest, IntersectAWorldWithARay) {
    auto w = World::Default();
    auto r = Ray(Point(0,0,-5), Vector(0,0,1));

    auto xs = w.Intersect(r);

    LONGS_EQUAL(4, xs.size());
    DOUBLES_EQUAL(4, xs[0].t, EPSILON);
    DOUBLES_EQUAL(4.5, xs[1].t, EPSILON);
    DOUBLES_EQUAL(5.5, xs[2].t, EPSILON);
    DOUBLES_EQUAL(6, xs[3].t, EPSILON);
}

TEST(WorldTest, ShadingAnIntersection) {
    auto w = World::Default();
    auto r = Ray(Point(0,0,-5), Vector(0,0,1));
    auto shape = w.objects[0];
    auto i = Intersection(4, shape);

    auto comps = r.Precomp(i);
    auto c = w.ShadeHit(comps);

    CHECK(c == Color(0.38066, 0.47583, 0.2855));
}

TEST(WorldTest, ShadingAnIntersectionFromTheInside) {
    auto w = World::Default();
    w.lights[0] = PointLight(Point(0,0.25,0), Color(1,1,1));
    auto r = Ray(Point(0,0,0), Vector(0,0,1));
    auto shape = w.objects[1];
    auto i = Intersection(0.5, shape);

    auto comps = r.Precomp(i);
    auto c = w.ShadeHit(comps);

    CHECK(c == Color(0.90498, 0.90498, 0.90498));
}

TEST(WorldTest, TheColorWhenARayMisses) {
    auto w = World::Default();
    auto r = Ray(Point(0,0,-5), Vector(0,1,0));

    auto c = w.ColorAt(r);

    CHECK(c == Color(0,0,0));
}

TEST(WorldTest, TheColorWhenARayHits) {
    auto w = World::Default();
    auto r = Ray(Point(0,0,-5), Vector(0,0,1));

    auto c = w.ColorAt(r);

    CHECK(c == Color(0.38066, 0.47583, 0.2855));
}

TEST(WorldTest, TheColorWithIntersectionBehindTheRay) {
    auto w = World::Default();
    auto outer = w.objects[0];
    auto inner = w.objects[1];
    outer->material.ambient = 1;
    inner->material.ambient = 1;
    auto r = Ray(Point(0,0,0.75), Vector (0,0,-1));

    auto c = w.ColorAt(r);

    CHECK(c == inner->material.color);

}