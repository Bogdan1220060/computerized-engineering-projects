#include <iostream>
#include <cmath>
#include <array>

class Robot2DOF {
private:
    double L1, L2; // lungimi brate
    double theta1, theta2; // unghiuri in grade

public:
    Robot2DOF(double l1, double l2) : L1(l1), L2(l2), theta1(0), theta2(0) {}

    void setAngles(double t1, double t2) {
        theta1 = t1;
        theta2 = t2;
    }

    std::array<double, 2> forwardKinematics() {
        double t1 = theta1 * M_PI / 180.0;
        double t2 = theta2 * M_PI / 180.0;
        double x = L1 * cos(t1) + L2 * cos(t1 + t2);
        double y = L1 * sin(t1) + L2 * sin(t1 + t2);
        return {x, y};
    }

    void printPosition() {
        auto pos = forwardKinematics();
        std::cout << "Pozitia efectorului: x = " << pos[0]
                  << " m, y = " << pos[1] << " m\n";
    }
};

int main() {
    Robot2DOF robot(0.6, 0.4);
    robot.setAngles(35, 25);
    robot.printPosition();

    return 0;
}
