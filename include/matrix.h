#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdint.h>
// #include <initializer_list>

// To ensure static memory allocation, we are using std::initializer_list, instead of vectors.

template <uint8_t ROWS, uint8_t COLS>
class Matrix {
    private:
        float m_data[ROWS][COLS];
    public:
        Matrix(std::initializer_list<std::initializer_list<float> > data);

    float operator()(const uint8_t &, const uint8_t &);
    bool operator== (const Matrix &);
    bool operator!= (const Matrix &);
    // Matrix<ROWS,COLS> operator* (const Matrix &);
};

#endif //MATRIX_H_