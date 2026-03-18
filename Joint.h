#pragma once
#include <iostream>

class Joint
{
private:
    double targetAngle;   // 목표 각도
    double currentAngle;  // 현재 각도 (센서값)
    double kp;            // 비례 제어 게인

public:
    Joint(double kpVal = 0.5)
        : targetAngle(0), currentAngle(0), kp(kpVal) {}

    void setTarget(double target)
    {
        targetAngle = target;
    }

    double readSensor()
    {
        // 실제 환경에서는 엔코더 값을 읽음
        return currentAngle;
    }

    void update()
    {
        // 센서 피드백
        currentAngle = readSensor();

        // 오차 계산
        double error = targetAngle - currentAngle;

        // P 제어 (간단한 제어 구조)
        double control = kp * error;

        // 모터 출력 (시뮬레이션)
        currentAngle += control;

        std::cout << "[Joint] Target: " << targetAngle
                  << " | Current: " << currentAngle << std::endl;
    }
};
