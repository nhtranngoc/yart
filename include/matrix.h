#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdint.h>

// To ensure static memory allocation, we are using std::initializer_list, instead of vectors.

template <uint8_t ROWS, uint8_t COLS>
class Matrix {
    private:
        float m_data[ROWS][COLS];
    public:
        Matrix(std::initializer_list<std::initializer_list<float> > data);

    float operator ()(const uint8_t &, const uint8_t &);
};

#endif //MATRIX_H_