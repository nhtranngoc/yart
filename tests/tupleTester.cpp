#include <CppUTest/TestHarness.h>
#include "../src/tuple.cpp"

extern "C" {

}

TEST_GROUP(TupleTest) {
    void setup() {

    }

    void tearDown() {

    }
};

TEST(TupleTest, isAPoint) {
    Tuple tp(4.3,-4.2,3.1,1.0); 

    DOUBLES_EQUAL(4.3, tp.x, EPSILON);
    DOUBLES_EQUAL(-4.2, tp.y, EPSILON);
    DOUBLES_EQUAL(3.1, tp.z, EPSILON);
    CHECK(tp.isPoint());
}

TEST(TupleTest, isAVector) {
    Tuple tp(4.3, -4.2, 3.1, 0.0);
    CHECK(tp.isVector());
}

TEST(TupleTest, createAPoint) {
    Tuple tp = Point(4, -4, 3);

    DOUBLES_EQUAL(4, tp.x, EPSILON);
    DOUBLES_EQUAL(-4, tp.y, EPSILON);
    DOUBLES_EQUAL(3, tp.z, EPSILON);
    CHECK(tp.isPoint());
    CHECK(!tp.isVector());
}

TEST(TupleTest, createAVector) {
    Tuple tp = Vector(4,-4,3);

    DOUBLES_EQUAL(4, tp.x, EPSILON);
    DOUBLES_EQUAL(-4, tp.y, EPSILON);
    DOUBLES_EQUAL(3, tp.z, EPSILON);
    CHECK(!tp.isPoint());
    CHECK(tp.isVector());
}

TEST(TupleTest, compareTwoTuples) {
    Tuple t1(3,4,2,0);
    Tuple t2(3,4,2,0);

    CHECK(t1 == t2);
}

TEST(TupleTest, addTwoTuples) {
    Tuple a1(3,-2,5,1);
    Tuple a2(-2,3,1,0);

    CHECK((a1 + a2) == Tuple(1,1,6,1));
}

TEST(TupleTest, subtractTwoPoints) {
    Tuple p1 = Point(3,2,1);
    Tuple p2 = Point(5,6,7);

    CHECK((p1 - p2) == Vector(-2,-4,-6));
}

TEST(TupleTest, subtractVectorFromPoint) {
    Tuple p = Point(3,2,1);
    Tuple v = Vector(5,6,7);

    CHECK((p - v) == Point(-2,-4,-6));
}

TEST(TupleTest, subtractVectorFromZeroVector) {
    Tuple zero = Vector(0,0,0);
    Tuple v = Vector(1,-2,3);

    CHECK((zero - v) == Vector(-1,2,-3));
}

TEST(TupleTest, negateATuple) {
    Tuple a(1,-2,3,-4);

    CHECK(-a == Tuple(-1,2,-3,4));
}

TEST(TupleTest, multiplyTupleByAScalar) {
    Tuple a(1,-2,3,-4);

    CHECK((a * 3.5) == Tuple(3.5,-7,10.5,-14));
}

TEST(TupleTest, divideTupleByAScalar) {
    Tuple a(1,-2,3,-4);

    CHECK((a / 2) == Tuple(0.5,-1,1.5,-2));
}

TEST(TupleTest, magnitudeOfVector) {
    Tuple v1 = Vector(1,0,0);
    Tuple v2 = Vector(0,1,0);
    Tuple v3 = Vector(0,0,1);

    DOUBLES_EQUAL(v1.magnitude(), 1, EPSILON);
    DOUBLES_EQUAL(v2.magnitude(), 1, EPSILON);
    DOUBLES_EQUAL(v3.magnitude(), 1, EPSILON);
}

TEST(TupleTest, normalizeVector) {
    Tuple v1 = Vector(4,0,0);
    Tuple v2 = Vector(1,2,3);
    Tuple v3 = v2.normalize();

    CHECK(v1.normalize() == Vector(1,0,0));
    CHECK(v2.normalize() == Vector(0.26726,0.53452,0.80178));
    DOUBLES_EQUAL(v3.magnitude(), 1, EPSILON);
}

TEST(TupleTest, dotProductOfTwoTuples) {
    Tuple a = Vector(1,2,3);
    Tuple b = Vector(2,3,4);

    DOUBLES_EQUAL(a.dot(b), 20, EPSILON);
}

TEST(TupleTest, crossProductOfTwoVectors) {
    Tuple a = Vector(1,2,3);
    Tuple b = Vector(2,3,4);

    CHECK(a.cross(b) == Vector(-1,2,-1));
    CHECK(b.cross(a) == Vector(1,-2,1));
}