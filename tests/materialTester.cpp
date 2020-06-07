#include <CppUTest/TestHarness.h>
#include "material.h"
#include "color.h"

TEST_GROUP(MaterialTest){};

TEST(MaterialTest, DefaultMaterial) {
    auto m = Material();

    CHECK(m.color == Color(1,1,1));
    DOUBLES_EQUAL(0.1, m.ambient, EPSILON);
    DOUBLES_EQUAL(0.9, m.diffuse, EPSILON);
    DOUBLES_EQUAL(0.9, m.specular, EPSILON);
    DOUBLES_EQUAL(200, m.shininess, EPSILON);
}