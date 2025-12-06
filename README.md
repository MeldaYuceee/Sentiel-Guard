# Sentinel-Guard – Multi-Sensor Perimeter Node

> **Domain:** Field Ops / Perimeter Security  
> **Level:** Prototype (Student R&D)  
> **Purpose:** Demonstrate a simple edge device that can detect basic perimeter activity using low-cost sensors

---

## 1. Background & Operational Context
Single-sensor perimeter systems are generally prone to false alarms. In real deployments, different environmental conditions such as ambient light, sudden sound, or physical motion may correspond to different types of perimeter activity.

This prototype illustrates a **multi-sensor edge node**, combining motion, acoustic, and light sensing to form a minimal example of sensor fusion for perimeter monitoring.

- Threat Type: Unauthorized perimeter activity  
- Sensors: PIR, acoustic, light  
- Field Use: Facility watch / perimeter awareness  
- Why It Matters: Multi-layer detection reduces false alarms in field environments  

---

## 2. Concept & Objective
The idea behind **Sentinel-Guard** is not to build a fully integrated defense system, but to show how simple hardware and basic logic can be used to detect small-scale perimeter events.

This is intended as a training and demonstration tool, reflecting how sensor fusion concepts can be implemented on minimal hardware platforms.

---

## 3. Architecture
[PIR] ──┐
[LDR] ──├→ [Threat Logic] → [LCD / Buzzer / Relay]
[SND] ──┘


- **Input:** PIR, acoustic, and light sensor readings  
- **Processing:** Simple threshold-based logic  
- **Output:** LCD indication + audible alarm + relay activation  

---

## 4. Features
- Motion + sound + light detection
- Real-time LCD display
- Individual LED indication per sensor
- Relay + buzzer alert mechanism
- Fully autonomous operation (no manual control)

---

## 5. Hardware Components
- Arduino Uno  
- PIR Motion Sensor  
- HW-484 Sound Sensor  
- LDR (with 10kΩ resistor)  
- 16×2 LCD (I2C)  
- Relay module  
- Buzzer  
- LED indicators  

---

## 6. Wiring Summary
| Component | Pin |
|---|---|
| PIR | D2 |
| Sound | D3 |
| LDR | A0 |
| Relay | D5 |
| Buzzer | D6 |
| PIR LED | D7 |
| Sound LED | D8 |
| LDR LED | D9 |
| LCD I2C | SDA A4 / SCL A5 |

> LDR uses a 10kΩ voltage divider.

---

## 7. Operation
1. Sensors are sampled continuously  
2. Threshold is checked on each reading  
3. Active sensor is shown on LCD  
4. Relay and buzzer are triggered under alarm conditions  

---

## 8. Installation & Run
```bash
git clone https://github.com/MeldaYuceee/Sentinel-Guard.git
open in Arduino IDE or PlatformIO
upload to board
