/**
 * @file main.cpp
 * @brief main関数を定義している.
 *
 * @par 外部から位置ベクトルを設定する.
 *      3x1のベクトルに限る...
 *
 * @par 回転させる軸,角度をそれぞれ設定する.
 *      小文字での入力のみ適応.
 *      ex) x軸 -> x
 *
 *      角度はdegreeで入力.
 * @author ogasawara
 * @date 2018/10/05
 */
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "rotation_matrix.h"

using namespace std;
using namespace Eigen;
/**
 * メイン処理
 * @return リターンコード
 */
int main() {
    char axis;
    int i;
    double num[3];
    double degree;

    cout << "ベクトルを設定 : " << endl;
    for(i=0; i<3; i++) {
        cout << "d[" << i+1 << "] = ";
        cin >> num[i];
    }

    cout << "回転させる軸 : "; cin >> axis;

    cout << "回転させる角度 : "; cin >> degree;

    RM rm(degree);

    rm.set_matrix();
    rm.set_vector(num);
    rm.conversion(axis);

    return 0;
}

