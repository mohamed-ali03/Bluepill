# 🚗 Bluepill Projects

This repository contains STM32 Bluepill projects written in C using STM32 HAL drivers. Each project demonstrates a specific embedded system feature, with a primary focus on **IR Remote Controlled Car** logic using the TSOP1838 IR receiver, L298 motor driver, and GPIO interrupts.

---

## 📁 Project Structure

- `Blinking-LED`: Simple LED blinking using GPIO.
- `EXTInterrupt`: External interrupt demonstration on GPIO pin.
- `IR-Receiver`: TSOP1838 NEC IR protocol decoding using EXTI and USB CDC logging.
- `Motor-Driver`: L298 dual motor driver logic and basic motion control.
- `Remote-Controlled-Car`: Full-featured IR-controlled car project using saved button signals.

---

## 🧠 Remote-Controlled-Car Overview

This project controls a two-wheel car using an IR remote. It uses interrupt-based IR signal decoding and a programmable control mapping.

### ❗ Note:

> Each time the car is powered on, **you must reprogram the control signals**. This is done by pressing a **dedicated hardware button** on the car that launches programming mode. Once programmed, the car maps 7 IR signals to movement functions.

---

## 🔧 Hardware Used

- STM32F103C8T6 (Bluepill)
- L298N Motor Driver
- 2 DC Motors
- TSOP1838 IR Receiver (NEC Protocol)
- 2 × 3.7V Batteries (for motor + logic power)
- Power Switch
- **Hardware Programming Button** (connected to EXTI pin)
- IR Remote (any NEC-compatible)

---

## 🚀 Features

- **Programmable IR Mode**: Save 7 IR signals using a hardware button.
- **Motor Control**: Forward, backward, rotate, and turn at different angles.
- **Serial Debugging**: USB CDC logging for IR data.
- **Modular Codebase**: Cleanly separated motor and IR drivers.

---

## 🎮 Supported IR Functions

After programming, the following functions are mapped to remote buttons:

1. Forward
2. Backward
3. Rotate Right 90°
4. Rotate Left 90°
5. Turn Right 40°
6. Turn Left 40°
7. Stop

---

## 📂 Code Highlights

### Motor Control (in `Motor-Driver`)

Motor control logic includes:

- `move_forward()`, `move_backward()`
- `rotate_left()`, `rotate_right()`
- `turn_40_degree_left()`, `turn_40_degree_right()`
- `stop_moving()`

  
### IR Decoding (in `IR-Receiver`)

- Uses GPIO EXTI interrupts to measure pulse duration
- Decodes NEC 32-bit signal
- USB CDC logging for debugging IR values
- Saves and maps codes to motor functions

---

## 🔌 How to Use

1. Flash `Remote-Controlled-Car` firmware to Bluepill.
2. Power the car and press the program button.
3. Send 8 IR signals (in order) to assign buttons.
4. Use the IR remote to control the car.

---

## 📸 Preview
Coming soon .....

---

## ✍️ Author

**Mohamed Ali Mohamed Hasabeen**  
Student @ Alexandria University – Communications & Electronics
