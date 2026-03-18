#include "RobotArm.h"

int main()
{
    RobotArm robot;

    robot.setup();

    // 테스트용 1회 실행 (무한루프 X → 깃허브용 안전)
    robot.setTarget(30, 20, 10, 15);
    robot.update();

    return 0;
}
