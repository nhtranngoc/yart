#include <CppUTest/TestHarness.h>

#include "canvas.h"

TEST_GROUP(CanvasTest) {};

TEST(CanvasTest, CanvasContainsBufferOfAppropriateSize) {
    auto image = Canvas(10, 10);
    
    LONGS_EQUAL(10, image.height);
    LONGS_EQUAL(10, image.width);
}

TEST(CanvasTest, CanvasInitializationIsBlack) {
    auto image = Canvas(10, 10);
    uint32_t *canvas = (uint32_t *) malloc(10*10*4);
    image.Init(canvas);
    LONGS_EQUAL(0xff000000, canvas[99]);
}

TEST(CanvasTest, WritePixel) {
    auto image = Canvas(320, 240);
    uint32_t *canvas = (uint32_t *) malloc(320*240*4);

    image.WritePixel(canvas, 2, 3, Color::Red());
    
    LONGS_EQUAL(0xffff0000, canvas[(2*240+3)]);
}