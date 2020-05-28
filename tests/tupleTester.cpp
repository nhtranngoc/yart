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
    // Tuple tp(4.3,-4.2,3.1,1.0); 

    // This will always pass.
    CHECK(1);

}