//3自由度マニピュレータ
#include <iostream>
#include <cmath>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

class Manipulator {
    private:
        double link0, link1, link2, link3;
        double a1;
        double degree1, degree2;
        double th1, th2;
    public:
        Matrix4d T1;
        Matrix4d T2;
        Matrix4d T3;
       // Vector4d Pr;
        Manipulator(double link0, double link1, double link2, double link3, double a1, double degree1, double degree2);
        void set_matrix();
        void conversion();
};

Manipulator::Manipulator(double link0, double link1, double link2, double link3, double a1, double degree1, double degree2) {
    this->link0 = link0;
    this->link1 = link1;
    this->link2 = link2;
    this->link3 = link3;
    this->a1 = a1;
    this->degree1 = degree1;
    this->degree2 = degree2;
    th1 = this->degree1*M_PI/180.0;
    th2 = this->degree2*M_PI/180.0;
}

void Manipulator::set_matrix() {
    T1 << cos(th1), -sin(th1), 0, 0,
            sin(th1), cos(th1), 0, 0,
            0, 0, 1, link0,
            0, 0, 0, 1;

    T2 << cos(th2), -sin(th2), 0, 0,
          sin(th2), cos(th2), 0, link1,
          0, 0, 1, 0,
          0, 0, 0, 1;

    T3 << 1, 0, 0, 0,
           0, 1, 0, link2,
           0, 0, 1, -a1-link3,
           0, 0, 0, 1;

   // Pr << 0, 0, -link3, 1;
}

void Manipulator::conversion() {
    cout << T1*T2*T3 << endl;
    //cout << Tz_1*TRz_1*Ty*TRz_2*Tyz*Tz_2*Pr << endl;
}

int main() {
    Manipulator mani(10, 10, 4, 3, 4, 45, 30); //l0, l1, l2, l3, a1, degree1, degree2
    mani.set_matrix();
    mani.conversion();

    return 0;
}

