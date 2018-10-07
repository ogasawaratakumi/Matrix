/**
 * @file rotation_matrix.h
 * @brief ワールド座標上にある位置ベクトルを,指定した軸周りに,指定した角度回転し,ワールド座標から見た位置ベクトルを表示
 * @author ogasawara
 * @date 2018/10/05
 */
#include <iostream>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;
  /**
   * RMクラスでは,それぞれの軸に対応する回転行列を設定.
   * 計算を行い,結果を出す.
   */
class RM {
    private:
        /**
         * 内部で保持している軸,角度.
         */
        char axis;
        double angle;
        double degree;
    public:
        /** 回転行列 */
        /** x軸方向 */
        Matrix3d Rx;
        /** y軸方向 */
        Matrix3d Ry;
        /** z軸方向 */
        Matrix3d Rz;
        /** 位置ベクトル */
        Vector3d d;

        /**
         * コンストラクタ
         * @param degree 角度設定する,
         */
        RM(double degree);
        /** 3方向に対する回転行列を設定,
         */
        void set_matrix();
        /**
         * 外部入力により,位置ベクトルを設定.
         * @param num 位置ベクトルを設定する.
         */
        void set_vector(double num[]);
        /**
         * 計算を行うメンバ関数.
         * @param axis 回転させる軸を設定する.
         */
        void conversion(char axis);
};
