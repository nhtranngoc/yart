#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdint.h>
#include <initializer_list>
#include "tuple.h"

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

    Matrix<ROWS, COLS> identity();
    Matrix<ROWS, COLS> transpose();
};

#endif //MATRIX_H_