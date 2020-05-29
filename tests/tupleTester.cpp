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
    CHECK(!tp.isVector());
}

TEST(TupleTest, isAVector) {
    Tuple tp(4.3, -4.2, 3.1, 0.0);

    DOUBLES_EQUAL(4.3, tp.x, EPSILON);
    DOUBLES_EQUAL(-4.2, tp.y, EPSILON);
    DOUBLES_EQUAL(3.1, tp.z, EPSILON);
    CHECK(!tp.isPoint());
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