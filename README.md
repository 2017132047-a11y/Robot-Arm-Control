# Robot Arm Control System (C++)

## Overview
This project implements a robot arm control system using C++ with an embedded-style control structure.

## Features
- Target-based joint control
- Feedback system (sensor simulation)
- Proportional (P) control algorithm
- Modular object-oriented design

## Architecture
Command Input → Target Angle → Control → Feedback → Update

## Design Approach
Each joint is controlled independently using a target-based method.
A simple P control algorithm is applied to simulate actuator behavior.

The system is designed with a loop-based structure,
similar to embedded firmware.

## Future Work
- PID control implementation
- Real sensor (encoder) integration
- Motor driver (PWM) control
