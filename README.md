# Sentiel-Guard

## Overview
I just completed my **Arduino-based Smart Security Module**! 🎯  
This system integrates **motion (PIR), sound (HW-484), and light (LDR) sensors** to detect potential threats. When a threat is detected, it displays an alert on the **LCD screen** and triggers a **buzzer** and **relay** for immediate notification.  

This project demonstrates **sensor fusion**, **hardware control**, and **basic security automation**. 🚀

---

## Features
- Multi-sensor threat detection: **PIR, Sound, LDR**  
- LED indicators for each sensor  
- LCD displays active alerts in real-time  
- Relay and buzzer trigger when a threat is detected  
- Fully automatic – no external control needed  

---

## Components
- **Arduino Uno**  
- **PIR Motion Sensor**  
- **HW-484 Sound Sensor**  
- **LDR Sensor**  
- **16x2 LCD Display (I2C)**  
- **Relay Module**  
- **Buzzer**  
- **LEDs for visual feedback**  

---

## Circuit Connections

| Component | Pin Connection |
|-----------|----------------|
| PIR       | Digital Pin 2  |
| Sound    | Digital Pin 3  |
| LDR       | Analog Pin A0 (with 10kΩ resistor) |
| Relay     | Digital Pin 5  |
| Buzzer    | Digital Pin 6  |
| PIR LED   | Pin 7          |
| Sound LED | Pin 8          |
| LDR LED   | Pin 9          |
| LCD I2C   | SDA → A4, SCL → A5 |

> LDR uses a voltage divider with 10kΩ to GND. LEDs can be different colors to indicate which sensor is active.

---

## How It Works
1. Arduino continuously reads all sensors.  
2. If any sensor exceeds its threshold, **LCD displays the active sensor(s)**.  
3. **LED corresponding to the triggered sensor lights up**.  
4. **Buzzer and relay** are activated when a threat is detected.  

---

## Installation
1. Clone the repository:
```bash
git clone https://github.com/<YourUsername>/SmartSecurityModule.git
