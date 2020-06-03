#include <CppUTest/TestHarness.h>
#include "matrix.cpp"

#define EPSILON 0.0001

TEST_GROUP(MatrixTest){};

TEST(MatrixTest, Constructing4x4Matrix) {
    Matrix<4,4> M({
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}});

    DOUBLES_EQUAL(M(0,0), 1, EPSILON);
    DOUBLES_EQUAL(M(0,3), 4, EPSILON);
    DOUBLES_EQUAL(M(1,0), 5.5, EPSILON);
    DOUBLES_EQUAL(M(1,2), 7.5, EPSILON);
    DOUBLES_EQUAL(M(2,2), 11, EPSILON);
    DOUBLES_EQUAL(M(3,0), 13.5, EPSILON);
    DOUBLES_EQUAL(M(3,2), 15.5, EPSILON);
}

TEST(MatrixTest, Represent2x2Matrix) {
    Matrix<2,2> M({
        {-3 ,5},
        {1, -2}
    });

    DOUBLES_EQUAL(M(0,0), -3, EPSILON);
    DOUBLES_EQUAL(M(0,1), 5, EPSILON);
    DOUBLES_EQUAL(M(1,0), 1, EPSILON);
    DOUBLES_EQUAL(M(1,1), -2, EPSILON);
}