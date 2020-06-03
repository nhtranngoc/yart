#include "matrix.h"

template <uint8_t ROWS, uint8_t COLS>
Matrix<ROWS, COLS>::Matrix(std::initializer_list<std::initializer_list<float> > data) {
    int i = 0;
    for (auto row : data) {
        if (i >= ROWS) break;
        int col = 0;
        for (float v : row) {
            if(col > COLS) break;
            m_data[i][col++] = v;
        }
        i++;
    }
}

template <uint8_t ROWS, uint8_t COLS>
float Matrix<ROWS, COLS>::operator() (const uint8_t &row, const uint8_t &col) {
    return this->m_data[row][col];
}