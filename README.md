# LPC2148-Obstacle-Avoiding-Robot-Car

Embedded C project using LPC2148 ARM7 microcontroller, IR sensors, L293D motor driver,DC motors, and a 16×2 LCD.

- LPC2148 ARM7 microcontroller
- Three IR obstacle sensors
- L293D motor driver
- Two DC motors
- 16×2 LCD
- Automatic obstacle detection
- Automatic forward, reverse, left and right movement

## Hardware Used

- LPC2148 development board
- L293D motor driver
- 2 × DC motors
- 3 × IR sensors
- 16×2 LCD
- Battery / power supply

## Pin Configuration

| LPC2148 Pin | Connection |
|---|---|
| P0.2 | L293D IN1 |
| P0.3 | L293D IN2 |
| P0.4 | L293D IN3 |
| P0.5 | L293D IN4 |
| P1.27 | Center IR sensor |
| P1.28 | Left IR sensor |
| P1.29 | Right IR sensor |
| P0.16–P0.23 | LCD Data |
| P0.10 | LCD RS |
| P0.12 | LCD RW |
| P0.13 | LCD EN |

## Working

The IR sensors detect obstacles around the robot.

When no obstacle is detected, the robot moves forward.

When an obstacle is detected, the LPC2148 changes the motor directions through the L293D motor driver to avoid the obstacle.

The current movement is displayed on the 16×2 LCD.

## Software

- Embedded C
- LPC2148 ARM7
- Keil µVision
- Proteus

## Project Files

- `robot_car.c` – Main embedded C program
- `circuit/` – Circuit diagram
- `images/` – Hardware photographs
