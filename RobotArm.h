#pragma once
#include "Joint.h"
#include "Gripper.h"

class RobotArm
{
private:
    Joint joint1;   // θ1 (Rotation)
    Joint joint2;   // θ2 (Rotation)
    Joint linear3;  // L3 (Linear Axis)
    Joint base;     // θ3 (Base Rotation)

    Gripper gripper;  // (Gripper)

public:
    RobotArm()
        : joint1(0.5, "ROTATION"),
          joint2(0.5, "ROTATION"),
          linear3(0.5, "LINEAR"),
          base(0.5, "ROTATION") {}

    void setup()
    {
        std::cout << "Robot Arm System Initialized" << std::endl;
    }

    // Joint + Linear
    void setTarget(double a1, double a2, double l3)
    {
        joint1.setTarget(a1);
        joint2.setTarget(a2);
        linear3.setTarget(l3);
    }

    // Base
    void setBase(double b)
    {
        base.setTarget(b);
    }

    // Gripper 제어
    void openGripper()
    {
        gripper.open();
    }

    void closeGripper()
    {
        gripper.close();
    }

    void update()
    {
        joint1.update();
        joint2.update();
        linear3.update();
        base.update();
    }
};
