#include "matrix.h"

// This constructor was taken almost directly from 
// https://github.com/sebasfei89/raytracer-cpp/blob/6537ff8a0504d79fc3da2173afd9087a37f7d4e8/Libs/RayTracer/Include/RayTracer/Matrix.h
// I need to learn more about copying initializer_list
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
float Matrix<ROWS, COLS>::operator () (const uint8_t &row, const uint8_t &col) {
    return this->m_data[row][col];
}

template <uint8_t ROWS, uint8_t COLS>
bool Matrix<ROWS,COLS>::operator == (const Matrix<ROWS,COLS> &m1) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(this->m_data[i][j] != m1.m_data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

template <uint8_t ROWS, uint8_t COLS>
bool Matrix<ROWS, COLS>::operator != (const Matrix<ROWS,COLS> &m1) {
    return !this->operator==(m1);
}

// template <uint8_t ROWS, uint8_t COLS>
// Matrix<ROWS, COLS> Matrix<ROWS, COLS>::operator * (const Matrix<ROWS, COLS> &m1) {
//     Matrix<ROWS, COLS> retVal;
//     for(int i = 0; i < ROWS; i++) {
//         for(int j = 0; j < COLS, j++) {
//             retVal(i,i) = this->m_data[]
//         }
//     }    
// }