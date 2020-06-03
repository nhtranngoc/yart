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
Matrix<ROWS, COLS>::Matrix(void) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            m_data[i][j] = 0;
        }
    }
}

template <uint8_t ROWS, uint8_t COLS>
float Matrix<ROWS, COLS>::operator () (uint8_t row, uint8_t col) const {
    return this->m_data[row][col];
}

template <uint8_t ROWS, uint8_t COLS>
float& Matrix<ROWS, COLS>::operator () (uint8_t row, uint8_t col) {
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

template <uint8_t ROWS, uint8_t COLS>
// typename std::enable_if<(ROWS == 4) && (COLS == 4), Matrix<4,4> >::type 
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::operator * (const Matrix<ROWS, COLS> &m1) {
    Matrix<ROWS, COLS> retVal;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            retVal(i,j) = 
                this->m_data[i][0] * m1.m_data[0][j] + 
                this->m_data[i][1] * m1.m_data[1][j] +
                this->m_data[i][2] * m1.m_data[2][j] +
                this->m_data[i][3] * m1.m_data[3][j];
        }
    }

    return retVal;    
}

template <uint8_t ROWS, uint8_t COLS>
Tuple Matrix<ROWS, COLS>::operator * (const Tuple &t) {
    return Tuple(
        this->m_data[0][0] * t.x + this->m_data[0][1] * t.y + this->m_data[0][2] * t.z + this->m_data[0][3] * t.w,
        this->m_data[1][0] * t.x + this->m_data[1][1] * t.y + this->m_data[1][2] * t.z + this->m_data[1][3] * t.w,
        this->m_data[2][0] * t.x + this->m_data[2][1] * t.y + this->m_data[2][2] * t.z + this->m_data[2][3] * t.w,
        this->m_data[3][0] * t.x + this->m_data[3][1] * t.y + this->m_data[3][2] * t.z + this->m_data[3][3] * t.w
    );
}

template <uint8_t ROWS, uint8_t COLS>
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::identity() {
    return Matrix<4,4> ({
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    });
}

template <uint8_t ROWS, uint8_t COLS>
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::transpose() {
    Matrix<ROWS, COLS> retVal;
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            retVal(i,j) = this->m_data[j][i];
        }
    }

    return retVal;
}