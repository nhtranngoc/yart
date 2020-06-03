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
            if(!equal(this->m_data[i][j], m1.m_data[i][j])) {
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
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::Identity() {
    return Matrix<4,4> ({
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    });
}

template <uint8_t ROWS, uint8_t COLS>
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::Transpose() {
    Matrix<ROWS, COLS> retVal;
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            retVal(i,j) = this->m_data[j][i];
        }
    }

    return retVal;
}

template<>
float Matrix<2,2>::Determinant() {
    return (this->m_data[0][0] * this->m_data[1][1] - this->m_data[0][1] * this->m_data[1][0]);
}

template<uint8_t ROWS, uint8_t COLS> 
float Matrix<ROWS, COLS>::Determinant() {
    float sum = 0;
    for(int i = 0; i < COLS; i++) {
        sum += this->m_data[0][i] * this->Cofactor(0,i);
    }

    return sum;
}

template<uint8_t ROWS, uint8_t COLS>
Matrix<ROWS-1, COLS-1> Matrix<ROWS, COLS>::Submatrix(const uint8_t row, const uint8_t col) {
    Matrix<ROWS-1, COLS-1> retVal;
    uint8_t sub_i, sub_j;

    for(int i = 0; i < ROWS - 1; i++) {
        sub_i = (i >= row) ? i + 1 : i;
        for(int j = 0; j < COLS - 1; j++) {
            sub_j = (j >= col) ? j + 1: j;
            retVal(i, j) = this->m_data[sub_i][sub_j];
        }
    }

    return retVal;
}

template<uint8_t ROWS, uint8_t COLS>
void Matrix<ROWS, COLS>::print() {
    for(int i = 0; i < ROWS; i++) {
        std::cout << "\n";
        for(int j = 0; j < COLS; j++) {
            std::cout << this->m_data[i][j] << " |";
        }
    }    
}

template<uint8_t ROWS, uint8_t COLS>
float Matrix<ROWS, COLS>::Minor(uint8_t row, uint8_t col) {
    return this->Submatrix(row, col).Determinant();
}

template<uint8_t ROWS, uint8_t COLS>
float Matrix<ROWS, COLS>::Cofactor(uint8_t row, uint8_t col) {
    if((row + col) % 2 == 1) { // is odd
        return -this->Minor(row, col);
    } else {
        return this->Minor(row, col);
    }
}

template<uint8_t ROWS, uint8_t COLS>
bool Matrix<ROWS, COLS>::IsInvertible() {
    return (this->Determinant() == 0) ? false : true;
}

template<uint8_t ROWS, uint8_t COLS>
Matrix<ROWS, COLS> Matrix<ROWS, COLS>::Inverse() {
    Matrix<ROWS, COLS> retVal;

    float det = this->Determinant();

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            retVal(j,i) = this->Cofactor(i,j) / det;
        }
    }

    return retVal;
}