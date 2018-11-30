#include <iostream>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

class Jacobi {
    private:
        static const double L1 = 1.0;
        static const double L2 = 1.0;
        double deg1, deg2;
        Vector2d q;
        Vector2d new_q;
        Vector2d deltaT;
        Vector2d goal;
        Vector2d tmp;
        Matrix<double,2,2> J;
    public:
        void set_matrix();
        void analyze();
};

void Jacobi::set_matrix() {
    q << M_PI/3.0,
        -M_PI/3.0;

    goal << 1.0,
            1.0;
}

void Jacobi::analyze() {
    for(int i=0; i<10; i++) {
        deltaT << goal[0]-(cos(q[0])+cos(q[0]+q[1])),
                  goal[1]-(sin(q[0])+sin(q[0]+q[1]));

        J << -L1*sin(q[0])-L2*sin(q[0]+q[1]), -L2*sin(q[0]+q[1]),
              L1*cos(q[0])+L2*cos(q[0]+q[1]),  L2*cos(q[0]+q[1]);

        new_q = q + J.inverse()*deltaT;
        tmp = q;
        q = new_q;
        new_q = tmp;

        deg1 = new_q[0]*180.0/M_PI; deg2 = new_q[1]*180.0/M_PI;
        cout << "count :" << i << endl;
        cout << "new_q = " << new_q[0] << ' '  << new_q[1] << endl << endl;
        cout << "deg ="  << deg1 << ' ' << deg2 << endl; 
        cout << "J = " << J << endl;
    }
}

int main() {
    Jacobi jacobi;
    jacobi.set_matrix();
    jacobi.analyze();

    return 0;
}
