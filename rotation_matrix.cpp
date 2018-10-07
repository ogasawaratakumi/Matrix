/**
 * @file rotation_matrix.cpp
 * @brief RMクラスの実装
 * @author ogasawara
 */
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "rotation_matrix.h"

using namespace std;
using namespace Eigen;
/**
 * 受け取った角度(degree)をラジアンに変換する.
 */
RM::RM(double degree) {
    this->degree = degree;
    angle = this->degree*M_PI/180.0;
}
/**
 * それぞれの回転行列を設定する.
 */
void RM::set_matrix() {

    Rx << 1,0,0,
          0,cos(angle),-sin(angle),
          0,sin(angle),cos(angle);

    Ry << cos(angle),0,sin(angle),
          0,1,0,
          -sin(angle),0,cos(angle);

    Rz << cos(angle), -sin(angle), 0,
          sin(angle), cos(angle), 0,
          0,0,1;
}
/**
 * 位置ベクトルを設定する.
 */
void RM::set_vector(double num[]) {
    d << num[0],
         num[1],
         num[2];
}
/**
 * 受け取った回転させる軸に応じて計算を行う.
 * @todo 1回だけでなく何度も行えるようにする.
 */
void RM::conversion(char axis) {
    this->axis = axis;

    switch(axis) {
        case 'x':
            cout << Rx*d << endl;
            break;
        case 'y':
            cout << Ry*d << endl;
            break;
        case 'z':
            cout << Rz*d << endl;
            break;
        default:
            break;
    }
}
