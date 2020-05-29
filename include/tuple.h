#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <stdlib.h>
#include <cmath>

using namespace std;

#define EPSILON 0.0001
bool equal(float x, float y);

class Tuple {
	public:
		float x, y, z, w;
		Tuple(float x, float y, float z, float w);
		bool isPoint();
		bool isVector();
		float magnitude();
		Tuple normalize();
		float dot(Tuple const &);
		Tuple cross(Tuple const &);

	friend bool operator == (Tuple const &, Tuple const &);
	friend Tuple operator + (Tuple const &, Tuple const &);
	friend Tuple operator - (Tuple const &, Tuple const &);
	friend Tuple operator - (Tuple const &);
	friend Tuple operator * (Tuple const &, float const);
	friend Tuple operator / (Tuple const &, float const);
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_HPP_