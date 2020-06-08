#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <stdlib.h>
#include <cmath>

using namespace std;

#define EPSILON 0.001
bool equal(float x, float y);

class Tuple {
	public:
		float x, y, z, w;
		Tuple();
		Tuple(float x, float y, float z, float w);
		bool IsPoint();
		bool IsVector();
		float Magnitude();
		Tuple Normalize();
		float Dot(Tuple const &);
		Tuple Cross(Tuple const &);
		Tuple Reflect(Tuple const &);

	friend bool operator == (Tuple const &, Tuple const &);
	friend Tuple operator + (Tuple const &, Tuple const &);
	friend Tuple operator - (Tuple const &, Tuple const &);
	friend Tuple operator - (Tuple const &);
	friend Tuple operator * (Tuple const &, float const);
	friend Tuple operator * (Tuple const &, Tuple const &);
	friend Tuple operator / (Tuple const &, float const);
	inline Tuple& operator= (const Tuple &) = default;
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_HPP_