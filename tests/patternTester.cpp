#include <CppUTest/TestHarness.h>
#include "pattern.h"
#include "transformation.h"
#include "matrix.h"
#include "sphere.h"

TEST_GROUP(PatternTest) {};

TEST(PatternTest, TheDefaultPatternTransformation) {
    auto pattern = std::make_shared<TestPattern>();
    auto identity = Matrix<4,4>::Identity();
    
    CHECK(pattern->transform == identity);
}

TEST(PatternTest, AssigningATransformation) {
    auto pattern = std::make_shared<TestPattern>();

    pattern->transform = Translation(1,2,3);

    CHECK(pattern->transform == Translation(1,2,3));
}

TEST(PatternTest, PatternsWithAnObjectTransformation) {
    auto object = std::make_shared<Sphere>();
    object->transform = Scaling(2,2,2);
    auto pattern = std::make_shared<TestPattern>();

    auto c = pattern->PatternAt(object, Point(2,3,4));

    CHECK(c == Color(1,1.5,2));
}

TEST(PatternTest, PatternsWithAPatternTransformation) {
    auto object = std::make_shared<Sphere>();
    auto pattern = std::make_shared<TestPattern>();
    pattern->transform = Scaling(2,2,2);

    auto c = pattern->PatternAt(object, Point(2,3,4));

    CHECK(c == Color(1,1.5,2));
}

TEST(PatternTest, PatternsWithBothAnObjectAndPatternTransform) {
    auto object = std::make_shared<Sphere>();
    object->transform = Scaling(2,2,2);
    auto pattern = std::make_shared<TestPattern>();
    pattern->transform = Translation(0.5,1,1.5);

    auto c = pattern->PatternAt(object, Point(2.5,3,3.5));

    CHECK(c == Color(0.75,0.5,0.25));
}