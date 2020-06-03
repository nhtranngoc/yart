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

TEST(MatrixTest, MatrixEquality) {
    Matrix<4,4> A({
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    });

    Matrix<4,4> B({
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    });

    CHECK(A == B);
}

TEST(MatrixTest, MatrixInequality) {
    Matrix<4,4> A({
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    });

    Matrix<4,4> B({
        {2,3,4,5},
        {6,7,8,9},
        {8,7,6,5},
        {4,3,2,1}
    });

    CHECK(A != B);
}

TEST(MatrixTest, MultiplyTwoMatrices) {
    Matrix<4,4> A({
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    });

    Matrix<4,4> B({
        {-2,1,2,3},
        {3,2,1,-1},
        {4,3,6,5},
        {1,2,7,8}
    });

    Matrix<4,4> C({
        {20,22,50,48},
        {44,54,114,108},
        {40,58,110,102},
        {16,26,46,42}
    });

    CHECK((A * B) == C);
}

TEST(MatrixTest, MultiplyAMatrixWithATuple) {
    Matrix<4,4> A({
        {1,2,3,4},
        {2,4,4,2},
        {8,6,4,1},
        {0,0,0,1}
    });

    Tuple b(1,2,3,1);

    Tuple c(18,24,33,1);

    CHECK((A * b) == c);
}