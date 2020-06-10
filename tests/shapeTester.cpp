#include <CppUTest/TestHarness.h>
#include "shape.h"
#include "matrix.h"
#include "transformation.h"

TEST_GROUP(ShapeTest) {};

TEST(ShapeTest, AShapesDefaultTransformation) {
    auto s = std::make_shared<TestShape>();
    auto identity = Matrix<4,4>::Identity();

    CHECK(s->transform == identity);
}

TEST(ShapeTest, AssigningATransformation) {
    auto s = std::make_shared<TestShape>();

    s->SetTransform(Translation(2,3,4));

    CHECK(s->transform == Translation(2,3,4));
}

TEST(ShapeTest, DefaultMaterial) {
    auto s = std::make_shared<TestShape>();

    auto m = s->material;

    CHECK(m == Material());
}

TEST(ShapeTest, AssigningAMaterial) {
    auto s = std::make_shared<TestShape>();
    auto m = Material();
    m.ambient = 1;

    s->material = m;

    CHECK(s->material == m);
}

TEST(ShapeTest, ComputeNormalOnATranslatedShape) {
    auto s = std::make_shared<TestShape>();
    s->SetTransform(Translation(0,1,0));

    auto n = s->NormalAt(Point(0, 1.70711, -0.70711));

    CHECK(n == Vector(0, 0.70711, -0.70711));
}

TEST(ShapeTest, ComputeNormalOnATransformedShape) {
    auto s = std::make_shared<TestShape>();
    s->SetTransform(Scaling(1, 0.5, 1) * RotationZ(pi/5));
    
    auto n = s->NormalAt(Point(
        0, 
        (float) sqrt(2) / 2,
        (float) -sqrt(2) / 2));

    CHECK(n == Vector(0, 0.97014, -0.24254));
}