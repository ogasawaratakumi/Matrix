#include <iostream>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

class Jacobi {
    private:
        double L1, L2, L3;
        double deg1, deg2, deg3;
        Vector3d q;
        Vector3d new_q;
        Vector2d deltaT;
        Vector2d goal;
        Vector3d tmp;
        Matrix<double,2,3> J;
        Matrix<double,2,2> J_calcin;
        Matrix<double,3,2> J_inverse;
    public:
        Jacobi() :
            L1(1.0), L2(1.0), L3(1.0) {}
        void set_matrix();
        void analyze();
};

void Jacobi::set_matrix() {
    q << M_PI/3.0,
         M_PI/2.0,
         M_PI/4.0;

    goal << 2.0,
            0.5;
}

void Jacobi::analyze() {
    for(int i=0; i<20; i++) {
        deltaT << goal[0] - ( cos(q[0])+cos(q[1])+cos(q[2]) ),
                  goal[1] - ( sin(q[0])+sin(q[1])+sin(q[2]) );

        J << -L1*sin(q[0]), -L2*sin(q[1]), -L3*sin(q[2]),
              L1*cos(q[0]),  L2*cos(q[1]),  L3*cos(q[2]);

        J_calcin = J*J.transpose();
        J_inverse = J.transpose()*J_calcin.inverse();

        new_q = q + J_inverse*deltaT;
        tmp = q;
        q = new_q;
        new_q = tmp;

        deg1 = new_q[0]*180.0/M_PI; deg2 = new_q[1]*180.0/M_PI; deg3 = new_q[2]*180.0/M_PI;

        cout << "new_q = " << new_q[0] << ' ' << new_q[1] << ' ' << new_q[2] << endl << endl;
        cout << "deg = " << deg1 << ' ' << deg2 << ' ' << deg3 << endl;
    }
}

int main() {
    Jacobi j;
    j.set_matrix();
    j.analyze();

    return 0;
}
