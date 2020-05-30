#include <CppUTest/TestHarness.h>
#include "color.h"

TEST_GROUP(ColorTest) {
    void setup() {

    }

    void tearDown() {

    }
};

TEST(ColorTest, AddingColors) {
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);

    CHECK((c1 + c2) == Color(1.6, 0.7, 1.0));
}

TEST(ColorTest, SubtractingColors) {
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);

    CHECK((c1 - c2) == Color(0.2, 0.5, 0.5));
}

TEST(ColorTest, MultiplyingColorByAScalar) {
    Color c(0.2, 0.3, 0.4);

    CHECK((c * 2) == Color(0.4, 0.6, 0.8));
}

TEST(ColorTest, MultiplyingColors) {
    Color c1(1, 0.2, 0.4);
    Color c2(0.9, 1, 0.1);

    CHECK((c1 * c2) == Color(0.9, 0.2, 0.04));
}

TEST(ColorTest, ConvertToHex) {
    Color c1(0,0,0);
    LONGS_EQUAL(0xff000000, c1.toHex());
    Color c2(1,0,0);
    LONGS_EQUAL(0xffff0000, c2.toHex());
    Color c3(0,1,0);
    LONGS_EQUAL(0xff00ff00, c3.toHex());
    Color c4(0,0,1);
    LONGS_EQUAL(0xff0000ff, c4.toHex());

    Color c5(0.5,0.5,0.5);
    LONGS_EQUAL(0xff7f7f7f, c5.toHex());
}