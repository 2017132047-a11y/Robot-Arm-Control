#pragma once
#include "Joint.h"

class RobotArm
{
private:
    Joint joint1;    // θ1
    Joint joint2;    // θ2
    Joint base;      // θ3
    Joint shoulder;  // θ4

public:
    RobotArm()
        : joint1(0.5), joint2(0.5), base(0.5), shoulder(0.5) {}

    void setup()
    {
        std::cout << "Robot Arm System Initialized" << std::endl;
    }

    void setTarget(double a1, double a2, double a3, double a4)
    {
        joint1.setTarget(a1);
        joint2.setTarget(a2);
        base.setTarget(a3);
        shoulder.setTarget(a4);
    }

    void update()
    {
        joint1.update();
        joint2.update();
        base.update();
        shoulder.update();
    }
};
