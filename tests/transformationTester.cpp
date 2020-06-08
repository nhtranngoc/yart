#include <CppUTest/TestHarness.h>
#include "transformation.h"
#include "tuple.h"
#include "matrix.h"

TEST_GROUP(TransformationTest){};

TEST(TransformationTest, MultiplyByTranslationMatrix) {
    Matrix<4,4> transform = Translation(5,-3,2);
    Tuple p = Point(-3,4,5);

    CHECK((transform * p) == Point(2,1,7));
}

TEST(TransformationTest, MultiplyByInverseOfTranslationMatrix) {
    Matrix<4,4> transform = Translation(5,-3,2);

    Matrix<4,4> inv = transform.Inverse();
    Tuple p = Point(-3,4,5);

    CHECK((inv * p) == Point(-8,7,3));
}

TEST(TransformationTest, TranslationDoesNotAffectVectors) {
    Matrix<4,4> transform = Translation(5,-3,2);
    Tuple v = Vector(-3,4,5);

    CHECK((transform * v) == v);
}

TEST(TransformationTest, ScalingMatrixToAPoint) {
    Matrix<4,4> transform = Scaling(2,3,4);
    Tuple p = Point(-4,6,8);

    CHECK((transform * p) == Point(-8,18,32));
}

TEST(TransformationTest, ScalingMatrixToAVector) {
    Matrix<4,4> transform = Scaling(2,3,4);
    Tuple v = Vector(-4,6,8);

    CHECK((transform * v) == Vector(-8,18,32));
}

TEST(TransformationTest, MultiplyByInverseOfScalingMatrix) {
    Matrix<4,4> transform = Scaling(2,3,4);
    Matrix<4,4> inv = transform.Inverse();
    Tuple v = Vector(-4,6,8);

    CHECK((inv * v) == Vector(-2,2,2));
}

TEST(TransformationTest, Reflection) {
    Matrix<4,4> transform = Scaling(-1,1,1);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(-2,3,4));
}

TEST(TransformationTest, RotationAroundXAxis) {
    Tuple p = Point(0,1,0);

    Matrix<4,4> half_quarter = RotationX(pi/4);
    Matrix<4,4> full_quarter = RotationX(pi/2);

    CHECK((half_quarter * p) == Point(0,sqrt(2)/2,sqrt(2)/2));
    CHECK((full_quarter * p) == Point(0,0,1));
}

TEST(TransformationTest, InverseRotationAroundXAxis) {
    Tuple p = Point(0,1,0);

    Matrix<4,4> half_quarter = RotationX(pi/4);
    Matrix<4,4> inv = half_quarter.Inverse();

    CHECK((inv * p) == Point(0, sqrt(2)/2, -sqrt(2)/2));
}

TEST(TransformationTest, RotationAroundYAxis) {
    Tuple p = Point(0,0,1);

    Matrix<4,4> half_quarter = RotationY(pi/4);
    Matrix<4,4> full_quarter = RotationY(pi/2);

    CHECK((half_quarter * p) == Point(sqrt(2)/2, 0, sqrt(2)/2));
    CHECK((full_quarter * p) == Point(1,0,0));
}

TEST(TransformationTest, RotationAroundZAxis) {
    Tuple p = Point(0,1,0);

    Matrix<4,4> half_quarter = RotationZ(pi/4);
    Matrix<4,4> full_quarter = RotationZ(pi/2);

    CHECK((half_quarter * p) == Point(-sqrt(2)/2, sqrt(2)/2, 0));
    CHECK((full_quarter * p) == Point(-1,0,0));
}

TEST(TransformationTest, ShearingXY) {
    Matrix<4,4> transform = Shearing(1,0,0,0,0,0);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(5,3,4));
}

TEST(TransformationTest, ShearingXZ) {
    Matrix<4,4> transform = Shearing(0,1,0,0,0,0);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(6,3,4));
}

TEST(TransformationTest, ShearingYX) {
    Matrix<4,4> transform = Shearing(0,0,1,0,0,0);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(2,5,4));
}

TEST(TransformationTest, ShearingYZ) {
    Matrix<4,4> transform = Shearing(0,0,0,1,0,0);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(2,7,4));
}

TEST(TransformationTest, ShearingZX) {
    Matrix<4,4> transform = Shearing(0,0,0,0,1,0);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(2,3,6));
}

TEST(TransformationTest, ShearingZY) {
    Matrix<4,4> transform = Shearing(0,0,0,0,0,1);
    Tuple p = Point(2,3,4);

    CHECK((transform * p) == Point(2,3,7));
}

TEST(TransformationTest, IndividualTransformationsInSequence) {
    Tuple p = Point(1,0,1);
    Matrix<4,4> A = RotationX(pi/2);
    Matrix<4,4> B = Scaling(5,5,5);
    Matrix<4,4> C = Translation(10,5,7);

    // Rotation
    Tuple p2 = A * p;
    CHECK(p2 == Point(1,-1,0));

    // Scaling
    Tuple p3 = B * p2;
    CHECK(p3 == Point(5,-5,0));

    //Translation
    Tuple p4 = C * p3;
    CHECK(p4 == Point(15,0,7));
}

TEST(TransformationTest, ChainedTransformationAppliedInReverseOrder) {
    Tuple p = Point(1,0,1);
    Matrix<4,4> A = RotationX(pi/2);
    Matrix<4,4> B = Scaling(5,5,5);
    Matrix<4,4> C = Translation(10,5,7);

    Matrix<4,4> T = C * B * A;
    CHECK((T * p) == Point(15,0,7));
}

TEST(TransformationTest, TransformationMatrixForDefaultOrientation) {
    auto from = Point(0,0,0);
    auto to = Point(0,0,-1);
    auto up = Vector(0,1,0);

    auto t = View(from, to, up);
    auto identity = Matrix<4,4>::Identity();

    CHECK(t == identity);
}

TEST(TransformationTest, ViewTransformationLookingInPositiveZDirection) {
    auto from = Point(0,0,0);
    auto to = Point(0,0,1);
    auto up = Vector(0,1,0);

    auto t = View(from, to, up);

    CHECK(t == Scaling(-1, 1, -1));
}

TEST(TransformationTest, ViewTransformationMovesTheWorld) {
    auto from = Point(0,0,8);
    auto to = Point(0,0,0);
    auto up = Vector(0,1,0);

    auto t = View(from, to, up);

    CHECK(t == Translation(0,0,-8));
}

TEST(TransformationTest, ArbitraryViewTransformation) {
    auto from = Point(1,3,2);
    auto to = Point(4,-2,8);
    auto up = Vector(1,1,0);

    auto t = View(from, to, up);

    auto m = Matrix<4,4> ({
        {-0.50709, 0.50709,  0.67612, -2.36643},
        {0.76772, 0.60609,  0.12122, -2.82843},
        {-0.35857, 0.59761, -0.71714,  0.00000},
        {0.00000, 0.00000,  0.00000,  1.00000}
    });

    CHECK(t == m);
}