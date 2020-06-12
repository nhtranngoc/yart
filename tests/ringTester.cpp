#include <CppUTest/TestHarness.h>
#include "ring.h"

TEST_GROUP(RingTest) {};

TEST(RingTest, ARingShouldExtendInBothXAndY) {
    auto pattern = std::make_shared<RingPattern>(Color::White(), Color::Black());

    auto c1 = pattern->PatternAtPoint(Point(0,0,0));
    auto c2 = pattern->PatternAtPoint(Point(1,0,0));
    auto c3 = pattern->PatternAtPoint(Point(0,0,1));
    // 0.708 = just slightly more than sqrt2/2
    auto c4 = pattern->PatternAtPoint(Point(0.708,0,0.708));

    CHECK(c1 == Color::White());
    CHECK(c2 == Color::Black());
    CHECK(c3 == Color::Black());
    CHECK(c4 == Color(0.708,0,0.708));
}