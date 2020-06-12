#include <CppUTest/TestHarness.h>
#include "gradient.h"

TEST_GROUP(GradientTest) {};

TEST(GradientTest, AGradientLinearlyInterpolatesBetweenColors) {
    auto pattern = std::make_shared<GradientPattern>(Color::White(), Color::Black());

    auto c1 = pattern->PatternAtPoint(Point(0,0,0));
    auto c2 = pattern->PatternAtPoint(Point(0.25,0,0));
    auto c3 = pattern->PatternAtPoint(Point(0.5,0,0));
    auto c4 = pattern->PatternAtPoint(Point(0.75,0,0));

    CHECK(c1 == Color::White());
    CHECK(c2 == Color(0.75,0.75,0.75));
    CHECK(c3 == Color(0.5,0.5,0.5));
    CHECK(c4 == Color(0.25,0.25,0.25));
}