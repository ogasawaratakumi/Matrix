 /**フレーム{A}, {B}が与えられている.
  * {B}を{A}に一致させた状態から（原点を通る）ベクトルK=[0.707 0.707 0]の周りに任意の角度だけ回転させるとき,フレーム{B}の表現
  * 等価回転行列を利用
  */

#include <iostream>
#include <cmath>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

class CTM { //Coordinate Transformation Matrix
    private:
        double degree;
        double th;
        Matrix4d T;
        Vector3d k;
    public:
        CTM(double degree);
        void set_vector();
        void set_and_get_matrix();
};

CTM::CTM(double degree) {
    this->degree = degree;
}

void CTM::set_vector() {
    k << 0.707,
         0.707,
         0;
}

void CTM::set_and_get_matrix() { //原点の並進は行わない
    double th = degree*M_PI/180.0;
    T << pow(k[0], 2)*(1-cos(th))+cos(th), k[0]*k[1]*(1-cos(th))-k[2]*sin(th), k[0]*k[2]*(1-cos(th))+k[1]*sin(th),0,
         k[0]*k[1]*(1-cos(th))+k[2]*sin(th), pow(k[1], 2)*(1-cos(th))+cos(th), k[1]*k[2]*(1-cos(th))-k[0]*sin(th),0,
         k[0]*k[2]*(1-cos(th))-k[1]*sin(th), k[1]*k[2]*(1-cos(th))+k[0]*sin(th), pow(k[2], 2)*(1-cos(th))+cos(th),0,
         0, 0, 0, 1;

    cout << "T = " << endl;
    cout << T << endl;
}

int main() {
    double degree;

    cout << "角度を設定してください. >> "; cin >> degree;

    CTM ctm(degree);
    ctm.set_vector();
    ctm.set_and_get_matrix();

    return 0;
}
