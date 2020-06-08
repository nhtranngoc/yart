#include <CppUTest/TestHarness.h>

#include "canvas.h"

TEST_GROUP(CanvasTest) {};

TEST(CanvasTest, CanvasContainsBufferOfAppropriateSize) {
    auto image = Canvas(10, 10);

    LONGS_EQUAL(0xff000000, image.buffer[99]);
}

TEST(CanvasTest, CanvasInitializationIsBlack) {
    auto image = Canvas(10, 10);
    LONGS_EQUAL(0xff000000, image.buffer[0]);
}

TEST(CanvasTest, WritePixel) {
    auto image = Canvas(320, 240);

    image.WritePixel(2, 3, Color(1,0,0));
    
    LONGS_EQUAL(0xffff0000, image.buffer[(2*240+3)]);
}