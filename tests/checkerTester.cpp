#include <CppUTest/TestHarness.h>

#include "checkers.h"

TEST_GROUP(CheckersTest) {};

TEST(CheckersTest, CheckersShouldRepeatInX) {
    auto pattern = std::make_shared<CheckersPattern>(Color::White(), Color::Black());

    auto c1 = pattern->PatternAtPoint(Point(0,0,0));
    auto c2 = pattern->PatternAtPoint(Point(0.99,0,0));
    auto c3 = pattern->PatternAtPoint(Point(1.01,0,0));

    CHECK(c1 == Color::White());
    CHECK(c2 == Color::White());
    CHECK(c3 == Color::Black());
}

TEST(CheckersTest, CheckersShouldRepeatInY) {
    auto pattern = std::make_shared<CheckersPattern>(Color::White(), Color::Black());

    auto c1 = pattern->PatternAtPoint(Point(0,0,0));
    auto c2 = pattern->PatternAtPoint(Point(0,0.99,0));
    auto c3 = pattern->PatternAtPoint(Point(0,1.01,0));

    CHECK(c1 == Color::White());
    CHECK(c2 == Color::White());
    CHECK(c3 == Color::Black());
}

TEST(CheckersTest, CheckersShouldRepeatInZ) {
    auto pattern = std::make_shared<CheckersPattern>(Color::White(), Color::Black());

    auto c1 = pattern->PatternAtPoint(Point(0,0,0));
    auto c2 = pattern->PatternAtPoint(Point(0,0,0.99));
    auto c3 = pattern->PatternAtPoint(Point(0,0,1.01));

    CHECK(c1 == Color::White());
    CHECK(c2 == Color::White());
    CHECK(c3 == Color::Black());
}
