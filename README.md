#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

/*
================================================
Joint Class
각 관절의 각도 및 회전 제어
================================================
*/

class Joint
{
private:

    double angle;
    double minAngle;
    double maxAngle;

public:

    Joint(double minA=-180, double maxA=180)
    {
        angle = 0;
        minAngle = minA;
        maxAngle = maxA;
    }

    void setAngle(double a)
    {

        if(a < minAngle)
        {
            a = minAngle;
        }

        if(a > maxAngle)
        {
            a = maxAngle;
        }

        angle = a;
    }

    void rotate(double delta)
    {
        setAngle(angle + delta);
    }

    double getAngle() const
    {
        return angle;
    }

    void print()
    {
        cout << "Angle : " << angle << endl;
    }

};

/*
================================================
Trajectory Class
관절 이동 경로 생성
================================================
*/

class Trajectory
{

public:

    static vector<double> linear(double start,
                                 double end,
                                 int steps)
    {

        vector<double> path;

        double delta = (end - start) / steps;

        for(int i=0;i<=steps;i++)
        {
            path.push_back(start + delta*i);
        }

        return path;

    }

};

/*
================================================
RobotArm Class
3축 로봇팔 제어
================================================
*/

class RobotArm
{

private:

    Joint joint1;
    Joint joint2;
    Joint joint3;

public:

    RobotArm()
    {

        joint1 = Joint(-180,180);
        joint2 = Joint(-120,120);
        joint3 = Joint(-120,120);

    }

    void moveJoint1(double a)
    {
        joint1.setAngle(a);
    }

    void moveJoint2(double a)
    {
        joint2.setAngle(a);
    }

    void moveJoint3(double a)
    {
        joint3.setAngle(a);
    }

    void rotateJoint1(double delta)
    {
        joint1.rotate(delta);
    }

    void rotateJoint2(double delta)
    {
        joint2.rotate(delta);
    }

    void rotateJoint3(double delta)
    {
        joint3.rotate(delta);
    }

    void printStatus()
    {

        cout << "------ Robot Arm Status ------" << endl;

        cout << "Joint1 : " << joint1.getAngle() << endl;
        cout << "Joint2 : " << joint2.getAngle() << endl;
        cout << "Joint3 : " << joint3.getAngle() << endl;

        cout << "------------------------------" << endl;

    }

    /*
    ================================================
    Trajectory Motion
    ================================================
    */

    void moveTo(double t1,
                double t2,
                double t3,
                int steps=20)
    {

        vector<double> p1 =
            Trajectory::linear(joint1.getAngle(),t1,steps);

        vector<double> p2 =
            Trajectory::linear(joint2.getAngle(),t2,steps);

        vector<double> p3 =
            Trajectory::linear(joint3.getAngle(),t3,steps);

        for(int i=0;i<=steps;i++)
        {

            joint1.setAngle(p1[i]);
            joint2.setAngle(p2[i]);
            joint3.setAngle(p3[i]);

            printStatus();

        }

    }

};

/*
================================================
FSM State Machine
================================================
*/

enum RobotState
{

    IDLE,
    MOVE,
    STOP,
    ERROR

};

class RobotController
{

private:

    RobotArm arm;
    RobotState state;

public:

    RobotController()
    {

        state = IDLE;

    }

    void commandMove(double a1,
                     double a2,
                     double a3)
    {

        cout << "Command Received" << endl;

        state = MOVE;

        arm.moveTo(a1,a2,a3);

        state = IDLE;

    }

    void emergencyStop()
    {

        cout << "Emergency Stop" << endl;

        state = STOP;

    }

    void reset()
    {

        cout << "Reset System" << endl;

        state = IDLE;

    }

};

/*
================================================
Simulation
================================================
*/

void simulation()
{

    RobotController controller;

    controller.commandMove(30,40,20);

    controller.commandMove(-20,10,30);

}

/*
================================================
Main
================================================
*/

int main()
{

    cout << "Robot Arm Control System Start" << endl;

    simulation();

    cout << "Program End" << endl;

    return 0;

}
