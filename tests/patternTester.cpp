#include <CppUTest/TestHarness.h>
#include "pattern.h"
#include "material.h"
#include "pointlight.h"
#include "sphere.h"

TEST_GROUP(PatternTest) {};

TEST(PatternTest, CreateAStripePattern) {
    auto pattern = StripePattern(Color::White(), Color::Black());

    CHECK(pattern.a == Color::White());
    CHECK(pattern.b == Color::Black());
}

TEST(PatternTest, AStripePatternIsConstantInY) {
    auto pattern = StripePattern(Color::White(), Color::Black());

    CHECK(pattern.StripeAt(Point(0,0,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(0,1,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(0,2,0)) == Color::White());
}

TEST(PatternTest, AStripePatternIsConstantInZ) {
    auto pattern = StripePattern(Color::White(), Color::Black());

    CHECK(pattern.StripeAt(Point(0,0,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(0,1,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(0,2,0)) == Color::White());
}

TEST(PatternTest, AStripePatternAlternatesInX) {
    auto pattern = StripePattern(Color::White(), Color::Black());

    CHECK(pattern.StripeAt(Point(0,0,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(0.9,0,0)) == Color::White());
    CHECK(pattern.StripeAt(Point(1,0,0)) == Color::Black());
    CHECK(pattern.StripeAt(Point(-0.1,0,0)) == Color::Black());
    CHECK(pattern.StripeAt(Point(-1,0,0)) == Color::Black());
    CHECK(pattern.StripeAt(Point(-1.1,0,0)) == Color::White());
}

TEST(PatternTest, LightingWithAPatternApplied) {
    auto m = Material();
    m.pattern = StripePattern(Color::White(), Color::Black());
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

TEST(PatternTest, StripesWithAnObjectTransformation) {
    auto object = std::make_shared<Sphere>();
    object->SetTransform(Scaling(2,2,2));
    auto pattern = StripePattern(Color::White(), Color::Black());

    auto c = pattern.StripeAt(object, Point(1.5,0,0));

    CHECK(c == Color::White());
}

TEST(PatternTest, StripesWithAPatternTransformation) {
    auto object = std::make_shared<Sphere>();
    auto pattern = StripePattern(Color::White(), Color::Black());
    pattern.SetTransform(Scaling(2,2,2));

    auto c = pattern.StripeAt(object, Point(1.5,0,0));

    CHECK(c == Color::White());
}

TEST(PatternTest, StripesWithBothAnObjectAndPatternTransform) {
    auto object = std::make_shared<Sphere>();
    object->SetTransform(Scaling(2,2,2));
    auto pattern = StripePattern(Color::White(), Color::Black());
    pattern.SetTransform(Translation(0.5,0,0));

    auto c = pattern.StripeAt(object, Point(2.5,0,0));

    CHECK(c == Color::White());
}