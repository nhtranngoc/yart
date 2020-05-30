#include <CppUTest/TestHarness.h>

#include "canvas.cpp"

uint32_t *const test_canvas = (uint32_t *) malloc(LCD_BYTES);

TEST_GROUP(CanvasTest) {
};

TEST(CanvasTest, ClearCanvas) {
    clear_canvas(test_canvas);

    LONGS_EQUAL(0xff000000, test_canvas[0]);
}

TEST(CanvasTest, WritePixel) {
    clear_canvas(test_canvas);
    write_pixel(test_canvas, 2, 3, Color(1,0,0).toHex());

    LONGS_EQUAL(0xffff0000, test_canvas[(3*240+2)]);
}