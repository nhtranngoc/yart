#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdint.h>
#include <initializer_list>
#include "tuple.h"
// #include "iostream"

// To ensure static memory allocation, we are using std::initializer_list, instead of vectors.

template <uint8_t ROWS, uint8_t COLS>
class Matrix {
    private:
        float m_data[ROWS][COLS];
    public:
        Matrix(std::initializer_list<std::initializer_list<float> > data);
        Matrix(void);

    float operator() (uint8_t, uint8_t) const;
    float& operator() (uint8_t, uint8_t); 

    bool operator== (const Matrix &);
    bool operator!= (const Matrix &);
    Matrix<ROWS,COLS> operator* (const Matrix &);
    Tuple operator*(const Tuple &);

    static Matrix<4, 4> Identity();
    Matrix<ROWS, COLS> Transpose();
    float Determinant();
    Matrix<ROWS-1, COLS-1> Submatrix(const uint8_t, const uint8_t);
    float Minor(uint8_t , uint8_t);
    float Cofactor(uint8_t, uint8_t);
    bool IsInvertible();

    Matrix<ROWS, COLS> Inverse();

    // void print();
};

// Explicitly instantiate relevant templates
template class Matrix<4,4>;
template class Matrix<3,3>;
template class Matrix<2,2>;

#endif //MATRIX_H_