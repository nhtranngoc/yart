#include "transformation.h"

Matrix<4,4> Translation(float x, float y, float z) {
    return Matrix<4,4>({
        {1,0,0,x},
        {0,1,0,y},
        {0,0,1,z},
        {0,0,0,1}
    });
}

Matrix<4,4> Scaling(float x, float y, float z) {
    return Matrix<4,4>({
        {x,0,0,0},
        {0,y,0,0},
        {0,0,z,0},
        {0,0,0,1}
    });
}

Matrix<4,4> RotationX(float r) {
    float const cosr = cosf(r);
    float const sinr = sinf(r);

    return Matrix<4,4>({
        {1,0,0,0},
        {0,cosr,-sinr,0},
        {0,sinr,cosr,0},
        {0,0,0,1}
    });
}

Matrix<4,4> RotationY(float r) {
    float const cosr = cosf(r);
    float const sinr = sinf(r);

    return Matrix<4,4>({
        {cosr,0,sinr,0},
        {0,1,0,0},
        {-sinr,0,cosr,0},
        {0,0,0,1}
    });
}

Matrix<4,4> RotationZ(float r) {
    float const cosr = cosf(r);
    float const sinr = sinf(r);

    return Matrix<4,4>({
        {cosr,-sinr, 0,0},
        {sinr,cosr,0,0},
        {0,0,1,0},
        {0,0,0,1}
    });
}

Matrix<4,4> Shearing(float xy, float xz, float yx, float yz, float zx, float zy) {
    return Matrix<4,4>({
        {1,xy,xz,0},
        {yx,1,yz,0},
        {zx,zy,1,0},
        {0,0,0,1}
    });
}

Matrix<4,4> View(Tuple from, Tuple to, Tuple up) {
    auto forward = (to - from).Normalize();
    auto left = forward.Cross(up.Normalize());
    auto true_up = left.Cross(forward);

    auto orientation = Matrix<4,4>({
        {left.x,left.y,left.z,0},
        {true_up.x,true_up.y,true_up.z,0},
        {-forward.x,-forward.y,-forward.z,0},
        {0,0,0,1}
    });

    return orientation * Translation(-from.x, -from.y, -from.z);
}