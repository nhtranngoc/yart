#include "gtest/gtest.h"
#include "../src/tuple.cpp"

TEST(tupleFeatures, isAPoint) {
	Tuple tp(4.3,-4.2,3.1,1.0); 

	ASSERT_FLOAT_EQ(tp.x, 4.3);
	ASSERT_FLOAT_EQ(tp.y, -4.2);
	ASSERT_FLOAT_EQ(tp.z, 3.1);
	ASSERT_EQ(tp.isPoint(), true);
	ASSERT_EQ(tp.isVector(), false);
}

TEST(tupleFeatures, isAVector) {
	Tuple tp(4.3,-4.2, 3.1, 0.0);

	ASSERT_FLOAT_EQ(tp.x, 4.3);
	ASSERT_FLOAT_EQ(tp.y, -4.2);
	ASSERT_FLOAT_EQ(tp.z, 3.1);
	ASSERT_EQ(tp.isPoint(), false);
	ASSERT_EQ(tp.isVector(), true);
}

TEST(tupleFeatures, createPoint) {
	Tuple tp = Point(4,-4,3);

	ASSERT_FLOAT_EQ(tp.x, 4);
	ASSERT_FLOAT_EQ(tp.y, -4);
	ASSERT_FLOAT_EQ(tp.z, 3);
	ASSERT_EQ(tp.isPoint(), true);
	ASSERT_EQ(tp.isVector(), false);
}

TEST(tupleFeatures, createVector) {
	Tuple tp = Vector(4,-4,3);

	ASSERT_FLOAT_EQ(tp.x, 4);
	ASSERT_FLOAT_EQ(tp.y, -4);
	ASSERT_FLOAT_EQ(tp.z, 3);
	ASSERT_EQ(tp.isPoint(), false);
	ASSERT_EQ(tp.isVector(), true);
}