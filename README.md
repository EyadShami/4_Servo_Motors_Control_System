# Arduino 4-Servo Control with 3 Buttons

## Overview
This project demonstrates how to control **4 servo motors** connected to an Arduino Uno using **3 push buttons**:
- **Two directional buttons** to rotate the selected servo clockwise or counterclockwise.
- **One selection button** to cycle through the servo motors (1 → 2 → 3 → 4 → all) for targeted or group control.

---

## Components Used
- **Arduino Uno** (or compatible board)
- **4x Servo motors**
- **3x Push buttons**
- **3x 10kΩ resistors** 
- Breadboard and jumper wires
- USB cable for power and programming

---

## Circuit Connections
- **Servos:**
  - Signal wires connected to pins **A0, A1, A2, A3**.
  - Power (red) connected to the +5V rail.
  - Ground (black) connected to GND.

- **Buttons:**
  - Button 1 (CW rotation) connected to **pin 2**.
  - Button 2 (CCW rotation) connected to **pin 3**.
  - Button 3 (Servo select) connected to **pin 4**.
  - Each button uses a pull-down resistor (to GND).

- **Power:**
  - Arduino +5V to the breadboard positive rail.
  - Arduino GND to the breadboard ground rail.

---

## Code Logic
1. **Servo Control:**
   - All servos start at **90° (neutral position)**.
   - Pressing **CW** increases the angle by +1° up to **180°**.
   - Pressing **CCW** decreases the angle by -1° down to **0°**.

2. **Servo Selection:**
   - Each press of the **select button** cycles control between:
     - Servo 1 → Servo 2 → Servo 3 → Servo 4 → All Servos → (back to Servo 1).

3. **While-Pressed Movement:**
   - The CW and CCW buttons rotate the currently selected servo **continuously while held down**.

---

## Full circuit connections
![image alt](https://github.com/EyadShami/4_Servo_Motors_Control_System/blob/6b70c51dbd178e6ef8ba54d6ad2f80dc58f81b04/4_Servo_Motors_Control_System.png)

## Circuit Simulation
![image alt](https://github.com/EyadShami/4_Servo_Motors_Control_System/blob/6b70c51dbd178e6ef8ba54d6ad2f80dc58f81b04/Simulation.gif)
