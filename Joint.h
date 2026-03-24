#pragma once
#include <iostream>
#include <string>

class Joint
{
private:
    double targetValue;   // 목표값 (각도 or 거리)
    double currentValue;  // 현재값 (센서값)
    double kp;            // 비례 제어 게인
    std::string type;     // "ROTATION" or "LINEAR"

public:
    Joint(double kpVal = 0.5, std::string jointType = "ROTATION")
        : targetValue(0), currentValue(0), kp(kpVal), type(jointType) {}

    void setTarget(double target)
    {
        targetValue = target;
    }

    double readSensor()
    {
        // 실제 환경에서는 엔코더 또는 리니어 센서 값
        return currentValue;
    }

    void update()
    {
        // 센서 피드백
        currentValue = readSensor();

        // 오차 계산
        double error = targetValue - currentValue;

        // P 제어
        double control = kp * error;

        // 상태 업데이트 (시뮬레이션)
        currentValue += control;

        // 출력 (회전 / 직선 구분)
        if (type == "ROTATION")
        {
            std::cout << "[Joint - Rotation] Target: " << targetValue << " deg"
                      << " | Current: " << currentValue << " deg" << std::endl;
        }
        else if (type == "LINEAR")
        {
            std::cout << "[Joint - Linear] Target: " << targetValue << " mm"
                      << " | Current: " << currentValue << " mm" << std::endl;
        }
    }

    double getCurrent() const
    {
        return currentValue;
    }

    double getTarget() const
    {
        return targetValue;
    }
};
