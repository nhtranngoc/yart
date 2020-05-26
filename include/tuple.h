#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <stdlib.h>
using namespace std;

#define EPSILON 0.00001
bool equal(float x, float y);

class Tuple {
	public:
		float x, y, z, w;
		Tuple(float x, float y, float z, float w);
		bool isPoint();
		bool isVector();
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_HPP_