#include <CppUTest/TestHarness.h>
#include "matrix.h"

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

TEST(MatrixTest, MultiplyAMatrixByIdentity) {
    Matrix<4,4> A({
        {0,1,2,4},
        {1,2,4,8},
        {2,4,8,16},
        {4,8,16,32}
    });

    CHECK((A * A.Identity()) == A);
}

TEST(MatrixTest, MultiplyIdentityMatrixByTuple) {
    Matrix<4,4> A;
    Tuple a(1,2,3,4);

    CHECK((A.Identity() * a) == a);
}

TEST(MatrixTest, TransposeAMatrix) {
    Matrix<4,4> A({
        {0,9,3,0},
        {9,8,0,8},
        {1,8,5,3},
        {0,0,5,8}
    });

    Matrix<4,4> B({
        {0,9,1,0},
        {9,8,8,0},
        {3,0,5,5},
        {0,8,3,8}
    });

    CHECK(A.Transpose() == B);
}

TEST(MatrixTest, TransposeIdentity) {
    Matrix<4,4> A;
    Matrix<4,4> Identity = A.Identity();

    CHECK(Identity.Transpose() == Identity);
}

TEST(MatrixTest, CalculateDeterminant2x2Matrix) {
    Matrix<2,2> A({
        {1,5},
        {-3,2}
    });

    DOUBLES_EQUAL(A.Determinant(), 17, EPSILON);
}

TEST(MatrixTest, SubmatrixOf3x3Is2x2) {
    Matrix<3,3> A({
        {1,5,0},
        {-3,2,7},
        {0,6,-3}
    });

    Matrix<2,2> B({
        {-3,2},
        {0,6}
    });

    CHECK(A.Submatrix(0,2) == B);
}

TEST(MatrixTest, MinorOf3x3Matrix) {
    Matrix<3,3> A({
        {3,5,0},
        {2,-1,-7},
        {6,-1,5}
    });

    Matrix<2,2> B = A.Submatrix(1,0);

    DOUBLES_EQUAL(B.Determinant(), 25, EPSILON);
    DOUBLES_EQUAL(A.Minor(1,0), 25, EPSILON);
}

TEST(MatrixTest, CofactorOf3x3Matrix) {
    Matrix<3,3> A({
        {3,5,0},
        {2,-1,-7},
        {6,-1,5}
    });

    DOUBLES_EQUAL(A.Minor(0,0), -12, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,0), -12, EPSILON);
    DOUBLES_EQUAL(A.Minor(1,0), 25, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(1,0), -25, EPSILON);
}

TEST(MatrixTest, DeterminantOf3x3Matrix) {
    Matrix<3,3> A({
        {1,2,6},
        {-5,8,-4},
        {2,6,4}
    });

    DOUBLES_EQUAL(A.Cofactor(0,0), 56, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,1), 12, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,2), -46, EPSILON);
    DOUBLES_EQUAL(A.Determinant(), -196, EPSILON);
}

TEST(MatrixTest, DeterminantOf4x4Matrix) {
    Matrix<4,4> A({
        {-2,-8,3,5},
        {-3,1,7,3},
        {1,2,-9,6},
        {-6,7,7,-9}
    });

    DOUBLES_EQUAL(A.Cofactor(0,0), 690, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,1), 447, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,2), 210, EPSILON);
    DOUBLES_EQUAL(A.Cofactor(0,3), 51, EPSILON);
    DOUBLES_EQUAL(A.Determinant(), -4071, EPSILON);
}

TEST(MatrixTest, TestInvertibleMatrix) {
    Matrix<4,4> A({
        {6,4,4,4},
        {5,5,7,6},
        {4,-9,3,-7},
        {9,1,7,-6}
    });

    DOUBLES_EQUAL(A.Determinant(), -2120, EPSILON);
    CHECK(A.IsInvertible());
}

TEST(MatrixTest, TestNonInvertibleMatrix) {
    Matrix<4,4> A({
        {-4,2,-2,-3},
        {9,6,2,6},
        {0,-5,1,-5},
        {0,0,0,0}
    });

    DOUBLES_EQUAL(A.Determinant(), 0, EPSILON);
    CHECK(!A.IsInvertible());
}

TEST(MatrixTest, CalculateInverseOfMatrix) {
    Matrix<4,4> A({
        {-5,2,6,-8},
        {1,-5,1,8},
        {7,7,-6,-7},
        {1,-3,7,4}
    });

    Matrix<4,4> B = A.Inverse();

    DOUBLES_EQUAL(A.Determinant(), 532, EPSILON);

    DOUBLES_EQUAL(A.Cofactor(2,3), -160, EPSILON);
    DOUBLES_EQUAL(B(3,2), (float) -160/532, EPSILON);

    DOUBLES_EQUAL(A.Cofactor(3,2), 105, EPSILON);
    DOUBLES_EQUAL(B(2,3), (float) 105/532, EPSILON);

    Matrix<4,4> C({
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    });

    CHECK(B == C);
}

TEST(MatrixTest, CalculateInverseOfMatrix2) {
    Matrix<4,4> A({
        {8,-5,9,2},
        {7,5,6,1},
        {-6,0,9,6},
        {-3,0,-9,-4}
    });

    Matrix<4,4> B({
        { -0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692,  0.12308,  0.02564,  0.03077},
        {0.35897,  0.35897,  0.43590,  0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    });

    CHECK(A.Inverse() == B);
}

TEST(MatrixTest, CalculateInverseOfMatrix3) {
    Matrix<4,4> A({
        {9,3,0,9},
        {-5,-2,-6,-3},
        {-4,9,6,4},
        {-7,6,6,2}
    });

    Matrix<4,4> B({
        {-0.04074, -0.07778,  0.14444, -0.22222},
        {-0.07778,  0.03333,  0.36667, -0.33333},
        {-0.02901, -0.14630, -0.10926,  0.12963},
        {0.17778, 0.06667, -0.26667, 0.33333}
    });

    CHECK(A.Inverse() == B);
}

TEST(MatrixTest, MultiplyAProductByItsInverse) {
    Matrix<4,4> A({
        {3,-9,7,3},
        {3,-8,2,-9},
        {-4,4,4,1},
        {-6,5,-1,1}
    });

    Matrix<4,4> B({
        {8,2,2,2},
        {3,-1,7,0},
        {7,0,5,4},
        {6,-2,0,5}
    });

    Matrix<4,4> C = A * B;

    CHECK((C * B.Inverse()) == A);
}