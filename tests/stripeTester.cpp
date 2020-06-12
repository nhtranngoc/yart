#include <CppUTest/TestHarness.h>
#include "stripe.h"
#include "material.h"
#include "pointlight.h"
#include "sphere.h"

TEST_GROUP(StripeTest) {};

TEST(StripeTest, CreateAStripePattern) {
    auto pattern = std::make_shared<StripePattern>(Color::White(), Color::Black());

    CHECK(pattern->a == Color::White());
    CHECK(pattern->b == Color::Black());
}

TEST(StripeTest, AStripePatternIsConstantInY) {
    auto pattern = std::make_shared<StripePattern>(Color::White(), Color::Black());

    CHECK(pattern->PatternAtPoint(Point(0,0,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(0,1,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(0,2,0)) == Color::White());
}

TEST(StripeTest, AStripePatternIsConstantInZ) {
    auto pattern = std::make_shared<StripePattern>(Color::White(), Color::Black());

    CHECK(pattern->PatternAtPoint(Point(0,0,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(0,1,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(0,2,0)) == Color::White());
}

TEST(StripeTest, AStripePatternAlternatesInX) {
    auto pattern = std::make_shared<StripePattern>(Color::White(), Color::Black());

    CHECK(pattern->PatternAtPoint(Point(0,0,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(0.9,0,0)) == Color::White());
    CHECK(pattern->PatternAtPoint(Point(1,0,0)) == Color::Black());
    CHECK(pattern->PatternAtPoint(Point(-0.1,0,0)) == Color::Black());
    CHECK(pattern->PatternAtPoint(Point(-1,0,0)) == Color::Black());
    CHECK(pattern->PatternAtPoint(Point(-1.1,0,0)) == Color::White());
}

TEST(StripeTest, LightingWithAPatternApplied) {
    auto m = Material();
    m.pattern = std::make_shared<StripePattern>(Color::White(), Color::Black());
    m.ambient = 1;
    m.diffuse = 0;
    m.specular = 0;
    auto eyev = Vector(0,0,-1);
    auto normalv = Vector(0,0,-1);
    auto light = PointLight(Point(0,0,-10), Color::White());
    auto object = std::make_shared<Sphere>();
    
    auto p1 = Point(0.9,0,0);
    auto p2 = Point(1.1,0,0);

    auto c1 = Lighting(m, object,  light, p1, eyev, normalv, false);
    auto c2 = Lighting(m, object, light, p2, eyev, normalv, false);

    CHECK(c1 == Color::White());
    CHECK(c2 == Color::Black());
}